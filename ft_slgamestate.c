/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slgamestate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:11:58 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/17 18:55:25 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_slgameover_free_n_exit(t_solong **vars)
{
	int		i;
	t_enemy	*temp;

	i = 0;
	while ((*vars)->map_d[i])
		free((*vars)->map_d[i++]);
	free ((*vars)->map_d);
	while ((*vars)->n > 0)
	{
		temp = (*vars)->enemy;
		(*vars)->enemy = (*vars)->enemy->next;
		free(temp);
		(*vars)->n--;
	}
	ft_printf("GAME OVER!!!\n");
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	exit(0);
}

void	ft_slgamewon_free_n_exit(t_solong **vars)
{
	int		i;
	t_enemy	*temp;

	i = 0;
	while ((*vars)->map_d[i])
		free((*vars)->map_d[i++]);
	free ((*vars)->map_d);
	while ((*vars)->n > 0)
	{
		temp = (*vars)->enemy;
		(*vars)->enemy = (*vars)->enemy->next;
		free(temp);
		(*vars)->n--;
	}
	ft_printf("You have won the game!!!\n");
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	exit(0);
}
