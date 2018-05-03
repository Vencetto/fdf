/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:15:29 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/16 15:15:30 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_z(t_obj *map, int sign)
{
	int			i;
	int			j;
	double		x;
	double		y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x = map->arr[i][j].x;
			y = map->arr[i][j].y;
			map->arr[i][j].x = x * cos(0.1 * sign) - y * sin(0.1 * sign);
			map->arr[i][j].y = x * sin(0.1 * sign) + y * cos(0.1 * sign);
			j++;
		}
		i++;
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}

void	rot_y(t_obj *map, int sign)
{
	int			i;
	int			j;
	double		x;
	double		z;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x = map->arr[i][j].x;
			z = map->arr[i][j].z;
			map->arr[i][j].x = x * cos(0.1 * sign) + z * sin(0.1 * sign);
			map->arr[i][j].z = x * -sin(0.1 * sign) + z * cos(0.1 * sign);
			j++;
		}
		i++;
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}

void	rot_x(t_obj *map, int sign)
{
	int			i;
	int			j;
	double		y;
	double		z;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			y = map->arr[i][j].y;
			z = map->arr[i][j].z;
			map->arr[i][j].y = y * cos(0.1 * sign) + z * -sin(0.1 * sign);
			map->arr[i][j].z = y * sin(0.1 * sign) + z * cos(0.1 * sign);
			j++;
		}
		i++;
	}
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
}
