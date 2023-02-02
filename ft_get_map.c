/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:08:00 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/01/17 17:14:07 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_first_last_row(t_solong **vars, int i)
{
	int	j;

	j = 0;
	while ((*vars)->map_d[i][j])
	{
		if ((*vars)->map_d[i][j] != '1')
			ft_slmap_free_n_exit(vars);
		j++;
	}
}

void	ft_count_cep(t_solong **vars, int i)
{
	int	j;

	j = 0;
	while ((*vars)->map_d[i][j])
	{
		if ((*vars)->map_d[i][j] == 'C')
			(*vars)->c++;
		else if ((*vars)->map_d[i][j] == 'E')
			(*vars)->e++;
		else if ((*vars)->map_d[i][j] == '2')
		{
			(*vars)->n++;
			ft_enemy_position(vars, i, j);
		}
		else if ((*vars)->map_d[i][j] == 'P')
		{
			(*vars)->p_pos_x = j;
			(*vars)->p_pos_y = i;
			(*vars)->p++;
		}
		else if ((*vars)->map_d[i][j] != '1' && (*vars)->map_d[i][j] != '0')
			ft_slmap_free_n_exit(vars);
		j++;
	}
}

void	ft_check_map(t_solong **v, int h, int l)
{
	int	i;

	i = 0;
	(*v)->c = 0;
	(*v)->e = 0;
	(*v)->p = 0;
	(*v)->n = 0;
	ft_check_first_last_row(v, 0);
	while (i < h && (*v)->map_d[i])
	{
		if ((int)ft_strlen((*v)->map_d[i]) != l)
			ft_slmap_free_n_exit(v);
		if ((*v)->map_d[i][0] != '1' || (*v)->map_d[i][l - 1] != '1')
			ft_slmap_free_n_exit(v);
		ft_count_cep(v, i);
		i++;
	}
	i--;
	ft_check_first_last_row(v, i);
	if ((*v)->c < 1 || (*v)->e != 1 || (*v)->p != 1)
		ft_slmap_free_n_exit(v);
	(*v)->i = i;
}

char	**ft_free_and_malloc(char **str, int h)
{
	void	**dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char **) * h);
	if (!dest)
	{
		while (str[i])
			free(str[i++]);
		free(str);
		return (NULL);
	}
	if (!(*str))
	{
		free(dest);
		return (NULL);
	}
	while (i < h - 1)
	{
		dest[i] = ft_strdup(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return ((char **)dest);
}

void	ft_get_map(t_solong *vars, char **av)
{
	int		l;
	int		h;
	int		fd;

	vars->map_d = NULL;
	h = 0;
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		ft_slmapname_free_n_exit();
	ft_file_name_check(av[1]);
	vars->map_d = malloc(sizeof(char **));
	while (1)
	{
		vars->map_d[h] = get_next_line(fd);
		if (!(vars->map_d[h]))
			break ;
		l = ft_strlen(vars->map_d[h]);
		if (vars->map_d[h][l - 1] == '\n')
			vars->map_d[h][l - 1] = '\0';
		h++;
		vars->map_d = ft_free_and_malloc(vars->map_d, h + 1);
	}
	close(fd);
	ft_set_n_check_map_hw(&vars, h, l);
	ft_check_map(&vars, h, l);
}
