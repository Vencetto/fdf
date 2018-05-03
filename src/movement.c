/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:22:40 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/15 19:22:41 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_x(t_obj *map, int sign)
{
	if (sign == 1)
		map->sh_x = map->sh_x + 2;
	else if (sign == -1)
		map->sh_x = map->sh_x - 2;
	else
		return ;
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}

void	zoom(t_obj *map, int sign)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (sign == 1)
			{
				map->arr[i][j].x = map->arr[i][j].x * 1.2;
				map->arr[i][j].y = map->arr[i][j].y * 1.2;
				map->arr[i][j].z = map->arr[i][j].z * 1.2;
			}
			else if (sign == -1)
			{
				map->arr[i][j].x = map->arr[i][j].x / 1.2;
				map->arr[i][j].y = map->arr[i][j].y / 1.2;
				map->arr[i][j].z = map->arr[i][j].z / 1.2;
			}
		}
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}

void	color_change(t_obj *map)
{
	int	i;
	int	j;
	int color;

	color = 0xFFFFFF + rand();
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->arr[i][j].color = color;
			j++;
		}
		i++;
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}

void	move_y(t_obj *map, int sign)
{
	if (sign == 1)
		map->sh_y = map->sh_y + 2;
	else if (sign == -1)
		map->sh_y = map->sh_y - 2;
	else
		return ;
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}
