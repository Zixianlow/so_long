/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_free_n_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:59:03 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/17 18:55:20 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_slmapname_free_n_exit(void)
{
	write (2, "Invalid map file name!!!\n", 24);
	exit(0);
}

void	ft_slmap_free_n_exit(t_solong **vars)
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
	write (2, "Invalid map attributes!!!\n", 25);
	exit(0);
}

void	ft_slpath_free_n_exit(t_solong *vars)
{
	int		i;
	t_enemy	*temp;

	i = 0;
	while (vars->map_d[i])
		free(vars->map_d[i++]);
	free (vars->map_d);
	while (vars->n > 0)
	{
		temp = vars->enemy;
		vars->enemy = vars->enemy->next;
		free(temp);
		vars->n--;
	}
	write (2, "Even GOD can't win this!!!\n", 26);
	exit(0);
}

void	ft_slesc_free_n_exit(t_solong **vars)
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
	write (2, "You hit ESC!!!\n", 14);
	exit(0);
}

void	ft_slx_free_n_exit(t_solong **vars)
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
	write (2, "You close the terminal!!!\n", 25);
	exit(0);
}
