/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:01:56 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/10 18:42:33 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_move_left(t_solong **vars, int i, int j, t_enemy *head)
{
	if ((*vars)->map_d[i][j - 1] != '0'
		&& (*vars)->map_d[i][j - 1] != 'P')
		(*vars)->enemy->enemy_direction = 1;
	else if ((*vars)->map_d[i][j - 1] == '0'
		|| (*vars)->map_d[i][j - 1] == 'P')
	{
		if ((*vars)->map_d[i][j - 1] == 'P')
		{
			(*vars)->enemy = head;
			ft_slgameover_free_n_exit(vars);
		}
		(*vars)->map_d[i][j - 1] = '2';
		(*vars)->map_d[i][j] = '0';
		(*vars)->enemy->pos_x--;
	}
}

void	ft_enemy_move_right(t_solong **vars, int i, int j, t_enemy *head)
{
	if ((*vars)->map_d[i][j + 1] != '0'
		&& (*vars)->map_d[i][j + 1] != 'P')
		(*vars)->enemy->enemy_direction = -1;
	else if ((*vars)->map_d[i][j + 1] == '0'
		|| (*vars)->map_d[i][j + 1] == 'P')
	{
		if ((*vars)->map_d[i][j + 1] == 'P')
		{
			(*vars)->enemy = head;
			ft_slgameover_free_n_exit(vars);
		}
		(*vars)->map_d[i][j + 1] = '2';
		(*vars)->map_d[i][j] = '0';
		(*vars)->enemy->pos_x++;
	}
}

void	ft_enemy_move(t_solong **vars)
{
	int		i;
	int		j;
	t_enemy	*head;

	if (!((*vars)->n))
		return ;
	head = (*vars)->enemy;
	while ((*vars)->enemy)
	{
		i = (*vars)->enemy->pos_y;
		j = (*vars)->enemy->pos_x;
		if ((*vars)->enemy->enemy_direction == 1)
			ft_enemy_move_right(vars, i, j, head);
		if ((*vars)->enemy->enemy_direction == -1)
			ft_enemy_move_left(vars, i, j, head);
		(*vars)->enemy = (*vars)->enemy->next;
	}
	(*vars)->enemy = head;
}
