#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: pointing to the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat s;

	(void)info;
	if (!path || stat(path, &s))
		return (0);

	if (s.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: pointing to the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char Buf[1024];
	int l = 0, n = 0;

	for (n = 0, l = start; l < stop; l++)
		if (pathstr[l] != ':')
			Buf[n++] = pathstr[l];
	Buf[n] = 0;
	return (Buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: pointing to the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int l = 0, currpos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[l] || pathstr[l] == ':')
		{
			path = dup_chars(pathstr, currpos, l);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[l])
				break;
			currpos = l;
		}
		l++;
	}
	return (NULL);
}
