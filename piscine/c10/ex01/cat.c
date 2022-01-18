unsigned int ft_strlen(char *str)
{
    unsigned int i;

    i = 0
    while(str[i])
        i++;
    return (i);
}


int display_file(char *path)
{
    char *file_buffer[32767];//min before 1999 32,767 bytes
    int filedesc;
    int bytes_read;

    filedesc = open(path, O_RDONLY);
    if(filedesc < 0)
        return 1;
    filedesc = (unsigned int) filedesc;
    len = 0; 
    while(1)
    {
        bytes_read = read(filedesc,&file_buffer[0],32767)); //fildesc should be 0 so standard input
        if (bytes_read > 0)
            write(1,&file_buffer[0],bytes_read);
        else
            break ;
    }
    close(fd);
    if (!len)
        return (1)    
    return 0;
}
/*
    cat - concatenate files and print on the standard output
    Concatenate FILE(s) to standard output.
    With no FILE, or when FILE is -, read standard input.
*/
int		main(int c, char **strings)
{
	char    read_buffer[30000];
    int     bytes_read;
	int     i;
    int     j;

    if (c < 2)
    {   
        if ( c == 1 || strings[1] == "-")
        {
            length = open(0,&read_buffer[0],30000);
            read(0,&read_buffer[0],length);//what to do with this???? 
        }
    }
    else
    {
        i = 0;
        j = 0;
        while (++i < c)
       {
            filedesc = open(strings[i], O_RDONLY);//basename for path?
            if(filedesc < 0)
                return 1;//strerror?
            filedesc = (unsigned int) filedesc;//filedesc should contain the info to find file ...
            bytes_read = read(filedesc,&read_buffer[j],30000-j))
            j += bytes_read;
        }
        if (ft_strlen(&read_buffer[0]))
            write(1,&read_buffer[0],ft_strlen(&read_buffer[0]));
        else
            return (1);
	}
    return (0);
}