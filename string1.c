#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: pointing to the destination
 * @src: pointing to the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int o = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[o])
	{
		dest[o] = src[o];
		o++;
	}
	dest[o] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: pointing to the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: pointing to the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int l = 0;

	if (!str)
		return;
	while (str[l] != '\0')
	{
		_putchar(str[l]);
		l++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: pointing to the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int l;
	static char Buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || l >= WRITE_BUF_SIZE)
	{
		write(1, Buf, l);
		l = 0;
	}
	if (c != BUF_FLUSH)
		Buf[l++] = c;
	return (1);
}
