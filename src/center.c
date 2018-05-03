/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:05:35 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/15 20:05:36 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	left_side(t_obj *map)
{
	return (map->arr[0][0].x <=
			map->arr[map->height - 1][0].x ?
			map->arr[0][0].x :
			map->arr[map->height - 1][0].x);
}

double	right_side(t_obj *map)
{
	return (map->arr[0][map->width - 1].x >=
			map->arr[map->height - 1][map->width - 1].x ?
			map->arr[0][map->width - 1].x :
			map->arr[map->height - 1][map->width - 1].x);
}

double	up_side(t_obj *map)
{
	return (map->arr[0][0].y <=
			map->arr[0][map->width - 1].y ?
			map->arr[0][0].y :
			map->arr[0][map->width - 1].y);
}

double	down_side(t_obj *map)
{
	return (map->arr[map->height - 1][0].y >=
			map->arr[map->height - 1][map->width - 1].y ?
			map->arr[map->height - 1][0].y :
			map->arr[map->height - 1][map->width - 1].y);
}

void	put_zero(t_obj *map)
{
	int		i;
	int		j;
	double	x_center;
	double	y_center;

	x_center = (right_side(map) + left_side(map)) / 2;
	y_center = (down_side(map) + up_side(map)) / 2;
	mlx_pixel_put(map->mlx, map->win, x_center + 2, y_center + 2, 0x122FFF);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->arr[i][j].x = map->arr[i][j].x - x_center;
			map->arr[i][j].y = map->arr[i][j].y - y_center;
			j++;
		}
		i++;
	}
}
