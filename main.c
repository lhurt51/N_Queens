/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:23:50 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/05 11:23:51 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nqueens.h"

int		n_queens(int n, int row, char **pos)
{
	int		col;
	int		queen;
	int		found;

	col = 0;
	if (n == row)
		return (1);
	while (col < n)
	{
		found = 1;
		queen = 0;
		while (queen < row)
		{
			if((pos[queen][0] - 48) == col 
				|| queen - (pos[queen][0] - 48) == row - col 
				|| queen + (pos[queen][0] - 48) == row + col)
			{
				found = 0;
				break;
			}
			queen++;
		}
		if(found)
		{
			pos[row][0] = (col + 48);
			if (n_queens(n, row + 1, pos))
				return (1);
		}
		col++;
	}
	return (0);
}

int		main(void)
{
	char **pos;
	int i;

	i = 0;
	pos = (char**)malloc(sizeof(char*) * 5);
	while (i < 4)
	{
		pos[i] = ft_strnew(2);
		i++;
	}
	n_queens(4, 0, pos);
	i = 0;
	while (i < 4)
	{
		ft_putstr("( ");
		ft_putnbr(i);
		ft_putstr(" , ");
		ft_putstr(pos[i]);
		ft_putstr(" )");
		i++;
	}
}
