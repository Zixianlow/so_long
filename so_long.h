/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:10:01 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/11 12:53:36 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_enemy{
	struct s_enemy	*prev;
	int				pos_x;
	int				pos_y;
	int				enemy_direction;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_solong{
	void	*mlx;
	void	*win;
	void	*pic;
	char	*wall_path;
	char	*ground_path;
	char	*star_path;
	char	*end_path;
	char	*player_path;
	char	*enemy_path;
	char	*star_path1;
	char	*end_path1;
	char	*player_path1;
	char	*enemy_path1;
	char	*star_path2;
	char	*end_path2;
	char	*player_path2;
	char	*enemy_path2;
	char	*star_path3;
	char	*end_path3;
	char	*player_path3;
	char	*enemy_path3;
	void	*pic_wall;
	void	*pic_ground;
	void	*pic_star;
	void	*pic_end;
	void	*pic_player;
	void	*pic_enemy;
	char	**map_d;
	int		map_h;
	int		map_w;
	int		frame;
	int		p_pos_x;
	int		p_pos_y;
	int		moves;
	int		star;
	int		enemy_count;
	int		i;
	int		c;
	int		e;
	int		p;
	int		n;
	int		t;
	t_enemy	*enemy;
}	t_solong;

void	ft_get_map(t_solong *vars, char **av);
void	ft_set_n_check_map_hw(t_solong **vars, int h, int l);
void	ft_file_name_check(char *av);
void	ft_get_image(t_solong *vars);
void	ft_get_image_s2(t_solong *img);
void	ft_get_image_s3(t_solong *img);
void	ft_render_map(t_solong v);
void	ft_put_moves_count(t_solong v);
void	ft_enemy_position(t_solong **v, int i, int j);
void	ft_enemy_move(t_solong **vars);
int		ft_sl_valid(t_solong *a);
void	ft_slmapname_free_n_exit(void);
void	ft_slmap_free_n_exit(t_solong **vars);
void	ft_slpath_free_n_exit(t_solong *vars);
void	ft_slesc_free_n_exit(t_solong **vars);
void	ft_slx_free_n_exit(t_solong **vars);
void	ft_slgameover_free_n_exit(t_solong **vars);
void	ft_slgamewon_free_n_exit(t_solong **vars);
//ft_movement
void	ft_move_up(t_solong *vars);
void	ft_move_left(t_solong *vars);
void	ft_move_down(t_solong *vars);
void	ft_move_right(t_solong *vars);

#endif