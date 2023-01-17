/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_moves_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:26:03 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/11 11:50:49 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_moves_count(t_solong v)
{
	char		*s;
	char		*n;

	s = "Move count : ";
	n = ft_itoa(v.moves);
	s = ft_strjoin(s, n);
	mlx_string_put(v.mlx, v.win, 0, 0, 0x00FF0000, s);
	free (s);
	free (n);
}
