/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:30:22 by whector           #+#    #+#             */
/*   Updated: 2020/09/09 19:15:25 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

int		main(int argc, char **argv)
{
	char	*buf;
	int		i;
	int		**arr;
	int		lib[5];

	buf = NULL;
	arr = NULL;
	if (argc == 1)
	{
		buf = check_valid_fifo(lib);
		if (buf == NULL || buf[0] == '\0')
			exit(map_error());
		arr = analis_map(buf, lib);
		final_process(arr, lib, buf);
		exit(0);
	}
	i = 0;
	while (++i < argc)
	{
		map_processing(buf, argv[i], lib, arr);
		if (argc > 2 && i != argc - 1)
			write(1, "\n", 1);
	}
	exit(0);
}

void	map_processing(char *buf, char *argv, int *lib, int **arr)
{
	buf = check_valid(argv, lib);
	if (buf != NULL && buf[0] != '\0')
	{
		arr = analis_map(buf, lib);
		final_process(arr, lib, buf);
	}
	else
		map_error();
}

void	final_process(int **arr, int *lib, char *buf)
{
	int	max;

	if (arr != NULL)
	{
		max = search_square(arr, lib);
		print_result(arr, lib, max);
		free_arr(arr, lib[0], buf);
	}
	else
		error();
}

int		map_error(void)
{
	write(1, "map error\n", 10);
	return (1);
}

void	free_arr(int **arr, int size, char *buf)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (i < size + 1)
			free(arr[i++]);
		free(arr);
		free(buf);
		arr = NULL;
		buf = NULL;
	}
}
