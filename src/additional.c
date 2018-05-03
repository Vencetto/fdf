/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:02:19 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/20 14:02:20 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		split_helper(char *p_arr, char **s_arr, int color)
{
	s_arr = ft_strsplit(p_arr, ',');
	p_arr = s_arr[0];
	color = find_color(s_arr[1]);
	free(s_arr[0]);
	free(s_arr[1]);
	free(s_arr);
	return (color);
}

void	disco(t_obj *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->arr[i][j].color = 0xFFFFFF + rand();
			j++;
		}
		i++;
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}

void	scale(t_obj *map)
{
	int		i;
	int		j;
	double	dist;
	double	width;
	double	win_wd;

	win_wd = W_WD;
	width = map->width;
	dist = (win_wd / map->width) / 2;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->arr[i][j].x = map->arr[i][j].x * dist;
			map->arr[i][j].y = map->arr[i][j].y * dist;
			map->arr[i][j].z = map->arr[i][j].z * dist;
			j++;
		}
		i++;
	}
}

void	color(t_obj *map, int s)
{
	int color;
	int i;
	int j;

	if (s == 1)
		color = 0x00ff00;
	else if (s == 2)
		color = 0xff0000;
	else if (s == 3)
		color = 0x0000ff;
	i = -1;
	while (++i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr[i][j].sp == 0)
			{
				map->arr[i][j].color = color;
			}
			j++;
		}
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}

void	color_2(t_obj *map, int s)
{
	int color;
	int i;
	int j;

	if (s == 1)
		color = 0x00ffcb;
	else if (s == 2)
		color = 0x9000ff;
	else if (s == 3)
		color = 0xfff721;
	i = -1;
	while (++i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr[i][j].sp == 1)
			{
				map->arr[i][j].color = color;
			}
			j++;
		}
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}
