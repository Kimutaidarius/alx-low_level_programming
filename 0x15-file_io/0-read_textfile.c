#include "main.h"

/**
 * read_textfile - Reads a text file and prints
 * it to the POSIX standard output.
 * @filename: The name of the file.
 * @letters: The number of letters to read and print
 *
 * Description: functions as described above.
 * Return: Returns number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t frd, nwrt;
	char *buff;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	frd = read(fd, buff, letters);
	nwrt = write(STDOUT_FILENO, buff, frd);

	close(fd);

	free(buff);

	return (nwrt);
}
