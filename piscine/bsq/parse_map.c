#include "ft.h"
#include <stdio.h>
//any inlines
//assuming the buffer is big anough to contain

void print_grid(t_map *map)
{
	for (int j = 0; j < map->width; j++)
	{
		for (int i = 0; i < map->height; i++)
		{
			printf("%d |" ,map->grid[i + j*map->width]);
		}
		printf("\n");
	}
}


void	init_grid(t_map *map)
{
	int	i;
	int j;

	map->grid = malloc(map->width * map->height);
	i = -1;
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
			map->grid[i + j * map->height] = 0;
	}
	i = -1;
	while (++i < map->obstacles.size)
	{
		map->grid [map->obstacles.obs_pos[i].x + map->height * map->obstacles.obs_pos[i].y] = 1;
		printf("%d : %d \n",map->obstacles.obs_pos[i].x , map->obstacles.obs_pos[i].y);
	}
	print_grid(map);
	printf("\n");
	i = 0;
	j = 0;
	while (++j < map->height)
	{
		i = 0;
		while (++i < map->width)
		{
			map->grid[i + map->height * j] = map->grid[i - 1 + map->height * j]	
			+ map->grid[i + map->height * (j - 1)] - map->grid[i - 1 + map->height * (j - 1)]
			+ map->grid[i + map->height * j];
		}
	}
	print_grid(map);
}


int buffer_get_info(char *buffer,t_map *map, int bytesread, int y)
{
	int	i;

	i = -1;
	map->obstacles.size = 0;
	map->height = 0;
	map->width = 0;
	while (++i < bytesread)
	{
		if (buffer[i] == map->obstacle)
			map->obstacles.size++;
		else if (buffer[i] == '\n')
		{
			map->height++;
			if (!map->width)
				map->width = i;
			else if (!(i % map->width))//checking for same width for every line
				return (-1);
		}
		else if (buffer[i] != map->empty)
			return (-1);
	}
	if (y < 0 || map->height != y)
		return (-1);
	return (0);
}

int	first_line(t_map *map, char *buffer, int i)//putain de first line
{
	int y;

	y = 0;
	i--;
	if (buffer[i] == buffer[i - 1] ||
		buffer[i] == buffer[i - 2] ||
		buffer[i - 1] == buffer[i - 2] || i == 0)
		return (-1); 
	map->full = buffer[i];
	map->obstacle = buffer[--i];
	map->empty = buffer[--i];
	i--;
	while('0' >= buffer[i] && buffer[i] <= '9')
		i--;
	if (i == 0)
		while (buffer[i] != map->empty)
			y = y*10 + buffer[i++] - '0';
	else
		return (-1);
	return (y);
}
int putain_de_first_line(t_map *map,char *path)//in buffer get info
{
	char	file_buffer[32767];
	int		filedesc;
	int		bytes_read;
	int		i;

	filedesc = open(path, O_RDONLY);
	if (filedesc < 0)
		return (-1);
	bytes_read = read(filedesc, &file_buffer[0], 32767);
	if (bytes_read < 0)
		return (-1);
	i = 0;
	while (file_buffer[i] != '\n')
		i++;
	close(filedesc);
	return (first_line(map,file_buffer,i));
}

int	check_map(char* path,t_map *map)
{
	char	file_buffer[32767];//?
	int		filedesc;
	int		bytes_read;
	int		size;
	int		y;
	
	y = putain_de_first_line(map,path);
	if (y < 0)
		return (-1);
	size = 0;
	filedesc = open(path, O_RDONLY);
	bytes_read = 1;
	while (file_buffer[0] != '\n')
		read(filedesc,&file_buffer[0],1);
	while (bytes_read > 0)
	{
		bytes_read = read(filedesc, &file_buffer[0], 32767);
		size += bytes_read;
		if ( bytes_read && buffer_get_info(file_buffer, map, bytes_read,y) < 0)
			return (-1);
	}
	close(filedesc);
	return (size);
}

void	file_to_str(char *path, t_map *map)
{
	int		filedesc;
	char 	c;
	
	c = 'm';
	filedesc = open(path, O_RDONLY);
	while (c != '\n')
		read(filedesc,&c,1);
	read(filedesc,map->str,map->str_length+1);//?
	close(filedesc);
}
//knowing how many obstacles there are already might make it worth it to create another function 
void	get_obstacle_postitions(t_map *map)
{
	int	i;//iterating over the string
	int j;//without \n
	int	c;//over objects

	i = 0;
	j = 0;
	c = 0;
	while (i < map->str_length)
	{
		if (map->str[i] == map->obstacle)
		{
			map->obstacles.obs_pos[c].x = j%map->width;
			map->obstacles.obs_pos[c].y = j/map->height;
			c++;
		}
		if (map->str[i] != '\n')
			j++;
		i++;
	}
}

int	init_map(char *path,t_map *map)
{

	map->str_length = check_map(path,map);
	if (map->str_length <= 0)
		return (-1);
	else
	{
		map->str = malloc((map->str_length + 1) *sizeof(char));//?
		map->obstacles.obs_pos = malloc(map->obstacles.size);
		if(!map->str || !map->obstacles.size)
			return (-1);
		file_to_str(path,map);
		map->str[map->str_length] = '\0';
		get_obstacle_postitions(map);
	}
	return (0);
}

void print_map_with_square(t_map *map, t_square *square)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while(++j < square->size)
		while(++i < square->size)
			map->str[square->pos.x + i + square->pos.y + map->width * j] = map->full;//?

	write(1,map->str,map->str_length);
}


int	is_possible(t_map *map, t_square *square)
{
	if   (map->grid[square->pos.x  + square->size + 1 + map->width * (square->pos.y + square->size + 1)] 
		- map->grid[square->pos.x - 1 + map->width * (square->pos.y + square->size + 1)]
		- map->grid[square->pos.x + square->size + 1 + map->width * (square->pos.y - 1)]
		+ map->grid[square->pos.x - 1 + map->width * (square->pos.y - 1)] > 0)
		return (0);
	return (1);
}

t_square *bsq(t_map *map, t_square *square)
{
	int i;
	int j;
	t_square best_square;

	square->pos.x = 0;
	square->pos.y = 0;
	square->size = 1;
	i = 0;
	j = 0;
	while (++j < map->height && j < map->height - square->size)
	{
		square->pos.y = j;
		i = 0;
		while (++i < map->width && i < map->width - square->size)
		{
			square->pos.x = i;
			while (1)
			{

				if (is_possible(map, square))
					square->size++;
				else
				{
					if (best_square.size < square->size)
						best_square = *square;
					break ;
				}
			}
		}
	}
	*square = best_square;
	return (square);
}

int main(int ac, char **av)
{
	t_square	square;
	t_square	*best_square;
	t_map		map;
	int			i;
	int			check;

	i = 0;
	if (ac != 1)
	{
		while (++i < ac)
		{
			check = init_map(av[i], &map);
			if (check < 0)
				write(1, "map error\n", 10);
			else
			{
				init_grid(&map);
				best_square = bsq(&map, &square);
				printf("%d\n",best_square->size);
				//print_map_with_square(&map, best_square);
			}
		}	
	}
}