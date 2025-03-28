#include "main.h"

/**
 * write_buffer - add char to buffer or flush if full
 */
int write_buffer(char *buffer, int *index, char c)
{
	if (*index >= 1024)
	{
		write(1, buffer, *index);
		*index = 0;
	}
	buffer[(*index)++] = c;
	return (1);
}

/**
 * flush_buffer - flush remaining buffer
 */
int flush_buffer(char *buffer, int index)
{
	return (write(1, buffer, index));
}
