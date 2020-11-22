/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:09:42 by whector           #+#    #+#             */
/*   Updated: 2020/09/09 12:44:46 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

void	print_result(int **arr, int *lib, int max)
{
	int	i;
	int	j;

	arr_null(arr, lib, max);
	fill_square_max(arr, lib, max);
	i = -1;
	while (++i < lib[0])
	{
		j = 0;
		while (++j < lib[1] + 1)
		{
			if (arr[i][j] == -1)
				write(1, &lib[3], 1);
			else if (arr[i][j] == max)
				write(1, &lib[4], 1);
			else
				write(1, &lib[2], 1);
		}
		write(1, "\n", 1);
	}
}

void	arr_null(int **arr, int *lib, int max)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < lib[0])
	{
		j = -1;
		while (++j < lib[1] + 1)
		{
			if (arr[i][j] == -1)
				continue ;
			else if (arr[i][j] == max && flag == 0)
				flag = 1;
			else
				arr[i][j] = 0;
		}
	}
}

void	fill_square_max(int **arr, int *lib, int max)
{
	int	i[4];
	int	flag;

	i[0] = -1;
	flag = 0;
	while (++i[0] < lib[0] && flag == 0)
	{
		i[1] = -1;
		while (++i[1] < lib[1] + 1 && flag == 0)
		{
			if (arr[i[0]][i[1]] == max && flag == 0)
			{
				flag = 1;
				i[2] = i[0];
				while (i[2] < i[0] + max)
				{
					i[3] = i[1];
					while (i[3] < i[1] + max)
						arr[i[2]][i[3]++] = (arr[i[2]][i[3]] == -1) ? -1 : max;
					i[2]++;
				}
			}
		}
	}
}
