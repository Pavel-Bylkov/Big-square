#include "bsq_head.h"

char		*check_valid(char *argv, int *lib)
{
	char	*buff;

	buff = create_buff(argv);
	if (buff == NULL)
		return (NULL);
	creat_lib_symbol(buff, lib);
	creat_lib_strings(buff, lib);
	check_library_double(buff, lib);
	if (buff[0] == '\0')
		return (buff);
	delete_first_line(buff, lib);
	check_even_columns(buff, lib);
	check_symbol_map(buff, lib);
	return (buff);
}

char		*check_valid_fifo(int *lib)
{
	char	*buff;

	buff = create_buff_fifo();
	if (buff == NULL)
		return (NULL);
	creat_lib_symbol(buff, lib);
	creat_lib_strings(buff, lib);
	check_library_double(buff, lib);
	if (buff[0] == '\0')
		return (buff);
	delete_first_line(buff, lib);
	check_even_columns(buff, lib);
	check_symbol_map(buff, lib);
	return (buff);
}

char		*create_buff_fifo(void)
{
	char	c;
	char	*buff;
	ssize_t	ret;
	int		i[2];

	buff = (char *)malloc(sizeof(char) * 1100000);
	if (buff == NULL)
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	buff[0] = '\0';
	ret = 1;
	i[1] = -1;
	while (++i[1] < 1100000 && ret > 0)
	{
		ret = read(0, &c, 1);
		buff[i[1]] = (ret > 0) ? c : '\0';
	}
	if (buff[0] != '\0')
		return (buff);
	free(buff);
	return (NULL);
}
