/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:21:26 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/18 13:28:14 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_image(t_solong *img)
{
	mlx_destroy_image(img->mlx, img->pic_end);
	mlx_destroy_image(img->mlx, img->pic_wall);
	mlx_destroy_image(img->mlx, img->pic_ground);
	mlx_destroy_image(img->mlx, img->pic_star);
	mlx_destroy_image(img->mlx, img->pic_enemy);
	mlx_destroy_image(img->mlx, img->pic_play);
}

void	ft_get_image_s3(t_solong *img)
{
	int	x;

	x = 0;
	ft_destroy_image(img);
	if (img->c == 0)
		img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path2, &x, &x);
	else
		img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path, &x, &x);
	img->pic_wall = mlx_xpm_file_to_image(img->mlx, img->wall_path, &x, &x);
	img->pic_ground = mlx_xpm_file_to_image(img->mlx, img->ground_path, &x, &x);
	img->pic_star = mlx_xpm_file_to_image(img->mlx, img->star_path3, &x, &x);
	img->pic_play = mlx_xpm_file_to_image(img->mlx, img->player_path3, &x, &x);
	img->pic_enemy = mlx_xpm_file_to_image(img->mlx, img->enemy_path3, &x, &x);
}

void	ft_get_image_s2(t_solong *img)
{
	int	x;

	x = 0;
	ft_destroy_image(img);
	if (img->c == 0)
		img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path2, &x, &x);
	else
		img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path, &x, &x);
	img->pic_wall = mlx_xpm_file_to_image(img->mlx, img->wall_path, &x, &x);
	img->pic_ground = mlx_xpm_file_to_image(img->mlx, img->ground_path, &x, &x);
	img->pic_star = mlx_xpm_file_to_image(img->mlx, img->star_path2, &x, &x);
	img->pic_play = mlx_xpm_file_to_image(img->mlx, img->player_path2, &x, &x);
	img->pic_enemy = mlx_xpm_file_to_image(img->mlx, img->enemy_path2, &x, &x);
}

void	ft_get_image_s1(t_solong *img)
{
	int	x;

	x = 0;
	ft_destroy_image(img);
	if (img->c == 0)
		img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path2, &x, &x);
	else
		img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path, &x, &x);
	img->pic_wall = mlx_xpm_file_to_image(img->mlx, img->wall_path, &x, &x);
	img->pic_ground = mlx_xpm_file_to_image(img->mlx, img->ground_path, &x, &x);
	img->pic_star = mlx_xpm_file_to_image(img->mlx, img->star_path, &x, &x);
	img->pic_play = mlx_xpm_file_to_image(img->mlx, img->player_path, &x, &x);
	img->pic_enemy = mlx_xpm_file_to_image(img->mlx, img->enemy_path, &x, &x);
}

void	ft_get_image(t_solong *img)
{
	int	x;

	x = 0;
	img->wall_path = "./assets/wall.xpm";
	img->ground_path = "./assets/floor.xpm";
	img->star_path = "./assets/chest.xpm";
	img->star_path2 = "./assets/chest1.xpm";
	img->star_path3 = "./assets/chest2.xpm";
	img->end_path2 = "./assets/door_open.xpm";
	img->end_path = "./assets/door.xpm";
	img->player_path = "./assets/girl1.xpm";
	img->enemy_path = "./assets/enemy1.xpm";
	img->player_path2 = "./assets/girl2.xpm";
	img->enemy_path2 = "./assets/enemy2.xpm";
	img->player_path3 = "./assets/girl3.xpm";
	img->enemy_path3 = "./assets/enemy3.xpm";
	img->pic_end = mlx_xpm_file_to_image(img->mlx, img->end_path, &x, &x);
	img->pic_wall = mlx_xpm_file_to_image(img->mlx, img->wall_path, &x, &x);
	img->pic_ground = mlx_xpm_file_to_image(img->mlx, img->ground_path, &x, &x);
	img->pic_star = mlx_xpm_file_to_image(img->mlx, img->star_path, &x, &x);
	img->pic_play = mlx_xpm_file_to_image(img->mlx, img->player_path, &x, &x);
	img->pic_enemy = mlx_xpm_file_to_image(img->mlx, img->enemy_path, &x, &x);
}

//try fixing may cause the mem leak