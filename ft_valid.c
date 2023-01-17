/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:36:51 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/11 14:06:41 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sl_restore(t_solong *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map_d[i])
	{
		j = 0;
		while (a->map_d[i][j])
		{
			if (a->map_d[i][j] == '6')
				a->map_d[i][j] = '0';
			if (a->map_d[i][j] == '7')
				a->map_d[i][j] = 'C';
			if (a->map_d[i][j] == '8')
				a->map_d[i][j] = 'E';
			if (a->map_d[i][j] == '9')
				a->map_d[i][j] = '2';
			j++;
		}
		i++;
	}
}

void	ft_sl_valid_c(t_solong *a, int i, int j, int *c)
{
	if (a->t != *c)
		return ;
	if (i < 1 || j < 1 || a->map_h < i || a->map_w < j)
		return ;
	if (a->map_d[i][j] == '1' || a->map_d[i][j] == 'E'
		|| a->map_d[i][j] == '6' || a->map_d[i][j] == '7'
		|| a->map_d[i][j] == '8' || a->map_d[i][j] == '9')
		return ;
	if (a->map_d[i][j] == 'P')
	{
		(*c)++;
		return ;
	}
	if (a->map_d[i][j] == '0')
		a->map_d[i][j] = '6';
	if (a->map_d[i][j] == 'C')
		a->map_d[i][j] = '7';
	if (a->map_d[i][j] == 'E')
		a->map_d[i][j] = '8';
	if (a->map_d[i][j] == '2')
		a->map_d[i][j] = '9';
	ft_sl_valid_c(a, i - 1, j, c);
	ft_sl_valid_c(a, i + 1, j, c);
	ft_sl_valid_c(a, i, j - 1, c);
	ft_sl_valid_c(a, i, j + 1, c);
}

void	ft_sl_valid_e(t_solong *a, int i, int j, int *e)
{
	if (*e > 0)
		return ;
	if (i < 1 || j < 1 || a->map_h < i || a->map_w < j)
		return ;
	if (a->map_d[i][j] == '1' || a->map_d[i][j] == '6'
		|| a->map_d[i][j] == '7' || a->map_d[i][j] == '8'
		|| a->map_d[i][j] == '9')
		return ;
	if (a->map_d[i][j] == 'P')
	{
		(*e)++;
		return ;
	}
	if (a->map_d[i][j] == '0')
		a->map_d[i][j] = '6';
	if (a->map_d[i][j] == 'C')
		a->map_d[i][j] = '7';
	if (a->map_d[i][j] == 'E')
		a->map_d[i][j] = '8';
	if (a->map_d[i][j] == '2')
		a->map_d[i][j] = '9';
	ft_sl_valid_e(a, i - 1, j, e);
	ft_sl_valid_e(a, i + 1, j, e);
	ft_sl_valid_e(a, i, j - 1, e);
	ft_sl_valid_e(a, i, j + 1, e);
}

void	ft_sl_safety(t_solong *a, int i, int j, int *c)
{
	a->t = *c;
	ft_sl_valid_c(a, i, j, c);
}

int	ft_sl_valid(t_solong *a)
{
	int	i;
	int	j;
	int	c;
	int	e;

	i = -1;
	c = 0;
	e = 0;
	while (a->map_d[++i])
	{
		j = -1;
		while (a->map_d[i][++j])
		{
			if (a->map_d[i][j] == 'C')
				ft_sl_safety(a, i, j, &c);
			ft_sl_restore(a);
			if (a->map_d[i][j] == 'E')
				ft_sl_valid_e(a, i, j, &e);
			ft_sl_restore(a);
		}
	}
	if (c != a->c || e != 1)
		return (1);
	return (0);
}
