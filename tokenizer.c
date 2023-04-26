#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: pointing to the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int q, r, p, t, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (q = 0; str[q] != '\0'; q++)
		if (!is_delim(str[q], d) && (is_delim(str[q + 1], d) || !str[q + 1]))
			num_words++;

	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (q = 0, r = 0; r < num_words; r++)
	{
		while (is_delim(str[q], d))
			r++;
		p = 0;
		while (!is_delim(str[q + p], d) && str[q + p])
			p++;
		s[r] = malloc((p + 1) * sizeof(char));
		if (!s[r])
		{
			for (p = 0; p < r; p++)
				free(s[p]);
			free(s);
			return (NULL);
		}
		for (t = 0; t < p; t++)
			s[r][t] = str[q++];
		s[r][t] = 0;
	}
	s[r] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: pointing to the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int q, r, p, t, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (q = 0; str[q] != '\0'; q++)
		if ((str[q] != d && str[q + 1] == d) ||
		    (str[q] != d && !str[q + 1]) || str[q + 1] == d)
			num_words++;
	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (q = 0, r = 0; r < num_words; r++)
	{
		while (str[q] == d && str[q] != d)
			q++;
		p = 0;
		while (str[q + p] != d && str[q + p] && str[q + r] != d)
			p++;
		s[r] = malloc((p + 1) * sizeof(char));
		if (!s[r])
		{
			for (p = 0; p < r; p++)
				free(s[p]);
			free(s);
			return (NULL);
		}
		for (t = 0; t < p; t++)
			s[r][t] = str[q++];
		s[r][t] = 0;
	}
	s[r] = NULL;
	return (s);
}
