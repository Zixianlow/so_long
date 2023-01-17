/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:01:30 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/11 13:47:07 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	kclose(int keycode, t_solong *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_slesc_free_n_exit(&vars);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		ft_enemy_move(&vars);
		if (keycode == 13)
			ft_move_up(vars);
		if (keycode == 0)
			ft_move_left(vars);
		if (keycode == 1)
			ft_move_down(vars);
		if (keycode == 2)
			ft_move_right(vars);
	}
	return (0);
}

int	exit_hook(t_solong *vars)
{
	ft_slx_free_n_exit(&vars);
	return (0);
}

int	ft_animate(t_solong *vars)
{
	vars->frame++;
	if (vars->frame % 500 == 1)
	{
		mlx_clear_window(vars->mlx, vars->win);
		ft_render_map(*vars);
		ft_put_moves_count(*vars);
	}
	if (vars->frame == 1)
		ft_get_image(vars);
	else if (vars->frame == 2500)
		ft_get_image_s2(vars);
	else if (vars->frame == 5000)
		ft_get_image_s3(vars);
	else if (vars->frame == 7500)
		ft_get_image(vars);
	else if (vars->frame == 10000)
		vars->frame = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	v;
	int			i;
	int			j;

	if (ac == 2)
	{
		v.frame = 0;
		ft_get_map(&v, av);
		if (ft_sl_valid(&v))
			ft_slpath_free_n_exit(&v);
		v.moves = 0;
		i = v.map_w * 80;
		j = 20 + v.map_h * 80;
		v.mlx = mlx_init();
		ft_get_image(&v);
		v.win = mlx_new_window(v.mlx, i, j, "so_long");
		ft_render_map(v);
		mlx_hook(v.win, 17, (1L << 0), exit_hook, &v);
		mlx_hook(v.win, 2, (1L << 0), kclose, &v);
		mlx_loop_hook(v.mlx, ft_animate, &v);
		mlx_loop(v.mlx);
	}
	return (0);
}
