#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: Text to be appended to the file
 *
 * Description: functions as described above.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, fwrt, i;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_APPEND | O_RDWR, 0664);

	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (i = 0; text_content[i]; i++)
			;

		fwrt = write(file, text_content, i);

		if (fwrt == -1)
			return (-1);
	}
	close(file);
	return (1);
}
