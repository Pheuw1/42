#include <fcntl.h>
#include <unistd.h>

//#include <sys/types.h> might need to include that
//#include <sys/stat.h>   might need to include that

//    read : On success, the number of bytes read is returned (zero indicates
//    end of file), and the file position is advanced by this number.
//    It is not an error if this number is smaller than the number of
//    bytes requested;

int display_file(char *path)
{
	char *file_buffer[32767]; // min before 1999 32,767 bytes
	int   filedesc;
	int   bytes_read;

	filedesc = open(path, O_RDONLY);
	if (filedesc < 0)
		return 1;
	// filedesc = (unsigned int) filedesc;
	bytes_read = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(filedesc,&file_buffer[0],32767)); //fildesc should be 0 so standard input and other sutff?
		write(1, &file_buffer[0], bytes_read);
	}
	close(filedesc);
	if (!bytes_read)
		return (1);
}

int main(int c, char *strings)
{
	if (argc < 2)
		write(2, "File name missing.\n", 20);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 21);
	else if (ft_display_file(argv[1]) != 0) // ernno is never set to zero >:)
		write(2, "Cannot read file.\n", 18);
	return (0);
}
