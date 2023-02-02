/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_name_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:45:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/18 14:20:16 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_n_check_map_hw(t_solong **vars, int h, int l)
{
	(*vars)->map_h = h;
	(*vars)->map_w = l;
	if (h == l)
		ft_slmap_free_n_exit(vars);
}

void	ft_file_name_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i--;
	if (av[i--] != 'r')
		ft_slmapname_free_n_exit();
	if (av[i--] != 'e')
		ft_slmapname_free_n_exit();
	if (av[i--] != 'b')
		ft_slmapname_free_n_exit();
	if (av[i--] != '.')
		ft_slmapname_free_n_exit();
}
