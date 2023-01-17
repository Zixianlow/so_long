/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:21:26 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/11 13:41:31 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_image_s3(t_solong *img)
{
	int	x;

	x = 0;
	img->wall_path = "./assets/wall.xpm";
	img->ground_path = "./assets/floor.xpm";
	img->star_path = "./assets/chest2.xpm";
	if (img->c == 0)
		img->end_path = "./assets/door_open.xpm";
	else
		img->end_path = "./assets/door.xpm";
	img->player_path = "./assets/girl3.xpm";
	img->enemy_path = "./assets/enemy3.xpm";
	img->pic_wall = mlx_xpm_file_to_image(img->mlx, img->wall_path, &x, &x);
	img->pic_ground = mlx_xpm_file_to_image(img->mlx, img->ground_path, &x, &x);
	img->pic_star = mlx_xpm_file_to_image(img->mlx, img->star_path, &x, &x);
	img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path, &x, &x);
	img->pic_player = mlx_xpm_file_to_image(img->mlx, img->player_path, &x, &x);
	img->pic_enemy = mlx_xpm_file_to_image(img->mlx, img->enemy_path, &x, &x);
}

void	ft_get_image_s2(t_solong *img)
{
	int	x;

	x = 0;
	img->wall_path = "./assets/wall.xpm";
	img->ground_path = "./assets/floor.xpm";
	img->star_path = "./assets/chest1.xpm";
	if (img->c == 0)
		img->end_path = "./assets/door_open.xpm";
	else
		img->end_path = "./assets/door.xpm";
	img->player_path = "./assets/girl2.xpm";
	img->enemy_path = "./assets/enemy2.xpm";
	img->pic_wall = mlx_xpm_file_to_image(img->mlx, img->wall_path, &x, &x);
	img->pic_ground = mlx_xpm_file_to_image(img->mlx, img->ground_path, &x, &x);
	img->pic_star = mlx_xpm_file_to_image(img->mlx, img->star_path, &x, &x);
	img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path, &x, &x);
	img->pic_player = mlx_xpm_file_to_image(img->mlx, img->player_path, &x, &x);
	img->pic_enemy = mlx_xpm_file_to_image(img->mlx, img->enemy_path, &x, &x);
}

void	ft_get_image(t_solong *img)
{
	int	x;

	x = 0;
	img->wall_path = "./assets/wall.xpm";
	img->ground_path = "./assets/floor.xpm";
	img->star_path = "./assets/chest.xpm";
	if (img->c == 0)
		img->end_path = "./assets/door_open.xpm";
	else
		img->end_path = "./assets/door.xpm";
	img->player_path = "./assets/girl1.xpm";
	img->enemy_path = "./assets/enemy1.xpm";
	img->pic_wall = mlx_xpm_file_to_image(img->mlx, img->wall_path, &x, &x);
	img->pic_ground = mlx_xpm_file_to_image(img->mlx, img->ground_path, &x, &x);
	img->pic_star = mlx_xpm_file_to_image(img->mlx, img->star_path, &x, &x);
	img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path, &x, &x);
	img->pic_player = mlx_xpm_file_to_image(img->mlx, img->player_path, &x, &x);
	img->pic_enemy = mlx_xpm_file_to_image(img->mlx, img->enemy_path, &x, &x);
}
