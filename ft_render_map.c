/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:58:07 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/11 11:34:03 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_epn(t_solong v, int i, int j)
{
	int	n;
	int	m;

	n = j * 80;
	m = 20 + i * 80;
	if (v.map_d[i][j] == 'E')
		mlx_put_image_to_window(v.mlx, v.win, v.pic_end, n, m);
	if (v.map_d[i][j] == 'P')
	{
		mlx_put_image_to_window(v.mlx, v.win, v.pic_ground, n, m);
		mlx_put_image_to_window(v.mlx, v.win, v.pic_player, n, m);
	}
	if (v.map_d[i][j] == '2')
	{
		mlx_put_image_to_window(v.mlx, v.win, v.pic_ground, n, m);
		mlx_put_image_to_window(v.mlx, v.win, v.pic_enemy, n, m);
	}
}

void	ft_render_wgc(t_solong v, int i, int j)
{
	int	n;
	int	m;

	n = j * 80;
	m = 20 + i * 80;
	if (v.map_d[i][j] == '1')
		mlx_put_image_to_window(v.mlx, v.win, v.pic_wall, n, m);
	if (v.map_d[i][j] == '0')
		mlx_put_image_to_window(v.mlx, v.win, v.pic_ground, n, m);
	if (v.map_d[i][j] == 'C')
	{
		mlx_put_image_to_window(v.mlx, v.win, v.pic_ground, n, m);
		mlx_put_image_to_window(v.mlx, v.win, v.pic_star, 25 + n, 25 + m);
	}
}

void	ft_render_map(t_solong v)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (v.map_d[i])
	{
		j = 0;
		while (v.map_d[i][j])
		{
			ft_render_wgc(v, i, j);
			ft_render_epn(v, i, j);
			j++;
		}
		i++;
	}
}
