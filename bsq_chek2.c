#include "bsq_head.h"

void		creat_lib_strings(char *buff, int *lib)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	i = (buff[i] != '\0') ? i + 1 : i;
	while (buff[i] != '\0' && buff[i + 1] != '\0' && buff[i++] != '\n')
		k++;
	lib[1] = (k);
}

void		delete_first_line(char *buff, int *lib)
{
	char	*str;
	int		raz;
	int		i;
	int		j;

	i = 0;
	raz = (lib[0] + 1) * (lib[1] + 1);
	str = (char *)malloc(sizeof(char) * raz);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	i = (buff[i] != '\0') ? i + 1 : i;
	buff[i] = (buff[i] == '\0' || buff[i] == '\n') ? '\0' : buff[i];
	j = 0;
	while (buff[i] != '\0')
	{
		str[j] = buff[i];
		i++;
		j++;
	}
	str[j] = '\0';
	i = -1;
	while (str[++i] != '\0')
		buff[i] = str[i];
	buff[i] = '\0';
	free(str);
}

void		check_even_columns(char *buff, int *lib)
{
	int		i;
	int		c;
	int		r;

	i = 0;
	c = 0;
	r = 0;
	while (buff[i] != '\0')
	{
		c = 0;
		while (buff[i] != '\0' && buff[i] != '\n')
		{
			c++;
			i++;
		}
		if (c != lib[1])
		{
			buff[0] = '\0';
			return ;
		}
		i++;
		r++;
	}
	if (r != lib[0])
		buff[0] = '\0';
}

void		check_symbol_map(char *buff, int *lib)
{
	int		i;

	i = 0;
	while (buff[i] != '\0')
	{
		if ((buff[i] != lib[2] && buff[i] != lib[3] &&
			buff[i] != '\n'))
		{
			buff[0] = '\0';
			return ;
		}
		i++;
	}
}

void		check_library_double(char *buff, int *lib)
{
	int		i;
	int		j;

	i = 2;
	while (i <= 3)
	{
		j = i + 1;
		while (j <= 4)
		{
			if (lib[i] == lib[j])
			{
				buff[0] = '\0';
				return ;
			}
			j++;
		}
		i++;
	}
}
