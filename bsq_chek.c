#include "bsq_head.h"

int			size_file(int fd)
{
	int		i;
	char	c;
	ssize_t	ret;

	ret = read(fd, &c, 1);
	i = 0;
	while (ret > 0)
	{
		ret = read(fd, &c, 1);
		i++;
	}
	close(fd);
	return (i);
}

char		*create_buff(char *argv)
{
	char	c;
	char	*buff;
	int		fd;
	ssize_t	ret;
	int		i[2];

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i[0] = size_file(fd);
	buff = (char *)malloc(sizeof(char) * i[0] + 1);
	buff[i[0]] = '\0';
	fd = open(argv, O_RDONLY);
	ret = 1;
	i[1] = -1;
	while (++i[1] < i[0] && ret > 0)
	{
		ret = read(fd, &c, 1);
		buff[i[1]] = (ret > 0) ? c : '\0';
	}
	close(fd);
	if (buff[0] != '\0')
		return (buff);
	free(buff);
	return (NULL);
}

void		lib_symbol(char *buff, int *lib, int i, int k)
{
	if (buff[i - 1 - k] >= 32 && buff[i - 1 - k] <= 126)
		lib[4 - k] = buff[i - 1 - k];
	else
		buff[0] = '\0';
}

void		lib_numbers(char *buff, int *lib, int k)
{
	if (buff[k] >= 48 && buff[k] <= 57)
		lib[0] = 10 * lib[0] + (buff[k] - 48);
	else
		buff[0] = '\0';
}

void		creat_lib_symbol(char *buff, int *lib)
{
	int		k;
	int		i;

	i = 0;
	lib[0] = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (i >= 4 && buff[i] != '\0' && buff[i + 1] != '\0' &&
			buff[i + 1] != '\n')
	{
		k = 0;
		while (k <= 2 && buff[0] != '\0')
			lib_symbol(buff, lib, i, k++);
		i = i - k;
		k = 0;
		while (buff[k] == ' ')
			k++;
		if (buff[k] == '+')
			k++;
		while (k <= i - 1 && buff[0] != '\0')
			lib_numbers(buff, lib, k++);
	}
	else
		buff[0] = '\0';
}
