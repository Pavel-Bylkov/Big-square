/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_analis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:32:46 by whector           #+#    #+#             */
/*   Updated: 2020/09/09 19:23:06 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

int		**analis_map(char *buf, int *lib)
{
	int	i;
	int	**arr;
	int	flag;

	arr = (int **)malloc((lib[0] + 1) * sizeof(int *));
	if (arr == NULL)
		return (NULL);
	i = -1;
	flag = 0;
	while ((++i < lib[0] + 1) && flag == 0)
	{
		arr[i] = (int *)malloc((lib[1] + 2) * sizeof(int));
		if (arr[i] == NULL)
		{
			flag = 1;
			break ;
		}
	}
	if (flag)
	{
		free_arr(arr, i - 1, buf);
		return (NULL);
	}
	fill_arr(arr, lib, buf);
	return (arr);
}

void	fill_arr(int **arr, int *lib, char *buf)
{
	int	i;
	int	j;
	int k;
	int n;

	i = 0;
	n = 0;
	while (buf[n])
	{
		j = 0;
		arr[i][j++] = -1;
		while (buf[n] != '\n' && buf[n])
		{
			arr[i][j] = 0;
			if (buf[n++] == lib[3])
				arr[i][j] = -1;
			j++;
		}
		arr[i++][j] = -1;
		n++;
	}
	k = 0;
	while (k <= j)
		arr[i][k++] = -1;
}

int		search_square(int **arr, int *lib)
{
	int	i[2];
	int	sum;
	int	k;
	int	max;

	i[0] = -1;
	max = 0;
	while (++i[0] < lib[0])
	{
		i[1] = -1;
		while (++i[1] < lib[1] + 1)
		{
			if (arr[i[0]][i[1]] == -1)
				continue ;
			sum = 0;
			k = 0;
			while (sum == 0)
				k = max_square(arr, &sum, i, k);
			arr[i[0]][i[1]] = k;
			max = (k > max) ? k : max;
		}
	}
	return (max);
}

int		max_square(int **arr, int *sum, int *i, int k)
{
	int	i2;
	int	j2;

	i2 = i[0] - 1;
	while (++i2 < i[0] + k + 1)
	{
		j2 = i[1] - 1;
		while (++j2 < i[1] + k + 1)
			*sum += arr[i2][j2];
	}
	return ((*sum == 0) ? k + 1 : k);
}

int		error(void)
{
	write(2, "malloc error\n", 13);
	return (1);
}
