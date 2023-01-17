/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:35:45 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/10 18:23:32 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_position(t_solong **v, int i, int j)
{
	t_enemy	*temp;

	temp = malloc(sizeof(t_enemy));
	temp->prev = NULL;
	temp->pos_x = j;
	temp->pos_y = i;
	temp->enemy_direction = 1;
	temp->next = NULL;
	if ((*v)->n == 1)
	{
		(*v)->enemy = temp;
	}
	else
	{
		while ((*v)->enemy && (*v)->enemy->next)
			(*v)->enemy = (*v)->enemy->next;
		temp->prev = (*v)->enemy;
		(*v)->enemy->next = temp;
	}
	while ((*v)->enemy->prev)
		(*v)->enemy = (*v)->enemy->prev;
}
