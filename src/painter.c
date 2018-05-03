/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:30:14 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/10 19:30:15 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	liner(t_obj *map, t_pnt p1, t_pnt p2, double length_xy[])
{
	double	x;
	double	y;
	int		d;

	x = p1.x;
	y = p1.y;
	d = -length_xy[0];
	while (length_xy[4]-- && p1.x < W_WD && p1.x > 0 && p1.y > 0 && p1.y < W_HT)
	{
		mlx_pixel_put(map->mlx, map->win, x, y, p1.color);
		x += length_xy[2];
		d += 2 * length_xy[1];
		if (d > 0)
		{
			d -= 2 * length_xy[0];
			y += length_xy[3];
		}
	}
}

void	liner_2(t_obj *map, t_pnt p1, t_pnt p2, double length_xy[])
{
	double	x;
	double	y;
	int		d;

	x = p1.x;
	y = p1.y;
	d = -length_xy[1];
	while (length_xy[4]-- && p1.x < W_WD && p1.x > 0 && p1.y > 0 && p1.y < W_HT)
	{
		mlx_pixel_put(map->mlx, map->win, x, y, p1.color);
		y += length_xy[3];
		d += 2 * length_xy[0];
		if (d > 0)
		{
			d -= 2 * length_xy[1];
			x += length_xy[2];
		}
	}
}

void	line(t_obj *map, t_pnt p1, t_pnt p2)
{
	double length_xy[5];

	p1.x = p1.x + map->sh_x;
	p1.y = p1.y + map->sh_y;
	p2.x = p2.x + map->sh_x;
	p2.y = p2.y + map->sh_y;
	length_xy[0] = ft_abs(p2.x - p1.x);
	length_xy[1] = ft_abs(p2.y - p1.y);
	length_xy[2] = (p2.x - p1.x >= 0 ? 1 : -1);
	length_xy[3] = (p2.y - p1.y >= 0 ? 1 : -1);
	length_xy[4] = (length_xy[0] >= length_xy[1]) ? length_xy[0] : length_xy[1];
	if (length_xy[4] == 0 && p1.x < W_WD && p1.x > 0 && p1.y > 0 && p1.y < W_HT)
		mlx_pixel_put(map->mlx, map->win, p1.x, p1.y, p1.color);
	if (length_xy[1] <= length_xy[0])
	{
		length_xy[4]++;
		liner(map, p1, p2, length_xy);
	}
	else
	{
		length_xy[4]++;
		liner_2(map, p1, p2, length_xy);
	}
}

void	draw_map(t_obj *map)
{
	int	i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			line(map, map->arr[i][j], map->arr[i][j + 1]);
			if (i > 0)
				line(map, map->arr[i][j], map->arr[i - 1][j]);
			j++;
		}
		if (i > 0)
			line(map, map->arr[i][j], map->arr[i - 1][j]);
		i++;
	}
}
