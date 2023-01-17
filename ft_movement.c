/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:07:25 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/17 16:24:04 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_solong *vars)
{
	int	i;
	int	j;

	i = vars->p_pos_y;
	j = vars->p_pos_x;
	if (vars->map_d[i - 1][j] == '1')
		return ;
	if (vars->map_d[i - 1][j] == 'E' && vars->c != 0)
		return ;
	if (vars->map_d[i - 1][j] == 'C')
		vars->c--;
	if (vars->map_d[i - 1][j] == '2')
		ft_slgameover_free_n_exit(&vars);
	if (vars->map_d[i - 1][j] == 'E' && vars->c == 0)
		ft_slgamewon_free_n_exit(&vars);
	vars->map_d[i - 1][j] = 'P';
	vars->map_d[i][j] = '0';
	vars->p_pos_y--;
	vars->moves++;
	ft_put_moves_count(*vars);
}

void	ft_move_left(t_solong *vars)
{
	int	i;
	int	j;

	i = vars->p_pos_y;
	j = vars->p_pos_x;
	if (vars->map_d[i][j - 1] == '1')
		return ;
	if (vars->map_d[i][j - 1] == 'E' && vars->c != 0)
		return ;
	if (vars->map_d[i][j - 1] == 'C')
		vars->c--;
	if (vars->map_d[i][j - 1] == '2')
		ft_slgameover_free_n_exit(&vars);
	if (vars->map_d[i][j - 1] == 'E' && vars->c == 0)
		ft_slgamewon_free_n_exit(&vars);
	vars->map_d[i][j - 1] = 'P';
	vars->map_d[i][j] = '0';
	vars->p_pos_x--;
	vars->moves++;
	ft_put_moves_count(*vars);
}

void	ft_move_down(t_solong *vars)
{
	int	i;
	int	j;

	i = vars->p_pos_y;
	j = vars->p_pos_x;
	if (vars->map_d[i + 1][j] == '1')
		return ;
	if (vars->map_d[i + 1][j] == 'E' && vars->c != 0)
		return ;
	if (vars->map_d[i + 1][j] == 'C')
		vars->c--;
	if (vars->map_d[i + 1][j] == '2')
		ft_slgameover_free_n_exit(&vars);
	if (vars->map_d[i + 1][j] == 'E' && vars->c == 0)
		ft_slgamewon_free_n_exit(&vars);
	vars->map_d[i + 1][j] = 'P';
	vars->map_d[i][j] = '0';
	vars->p_pos_y++;
	vars->moves++;
	ft_put_moves_count(*vars);
}

void	ft_move_right(t_solong *vars)
{
	int	i;
	int	j;

	i = vars->p_pos_y;
	j = vars->p_pos_x;
	if (vars->map_d[i][j + 1] == '1')
		return ;
	if (vars->map_d[i][j + 1] == 'E' && vars->c != 0)
		return ;
	if (vars->map_d[i][j + 1] == 'C')
		vars->c--;
	if (vars->map_d[i][j + 1] == '2')
		ft_slgameover_free_n_exit(&vars);
	if (vars->map_d[i][j + 1] == 'E' && vars->c == 0)
		ft_slgamewon_free_n_exit(&vars);
	vars->map_d[i][j + 1] = 'P';
	vars->map_d[i][j] = '0';
	vars->p_pos_x++;
	vars->moves++;
	ft_put_moves_count(*vars);
}
