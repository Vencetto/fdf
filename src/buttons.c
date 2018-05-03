/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:41:46 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/12 14:41:50 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		just_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		expose_hook(t_obj *m)
{
	mlx_string_put(m->mlx, m->win, 40, 40, 0x00ffcb, "KEYS:");
	mlx_string_put(m->mlx, m->win, 40, 80, 0x9000ff, "MOVE: ARROWS");
	mlx_string_put(m->mlx, m->win, 40, 100, 0x9000ff, "ZOOM = + -");
	mlx_string_put(m->mlx, m->win, 40, 120, 0x9000ff, "ROTATE = A W S D Q E");
	mlx_string_put(m->mlx, m->win, 40, 140, 0x9000ff, "COLOR_MAP = 1 2 3");
	mlx_string_put(m->mlx, m->win, 50, 160, 0x1220ff, "(only for 42-map)");
	mlx_string_put(m->mlx, m->win, 40, 180, 0x9000ff, "COLOR_42 = 4 5 6");
	mlx_string_put(m->mlx, m->win, 50, 200, 0x1220ff, "(only for 42-map)");
	mlx_string_put(m->mlx, m->win, 40, 220, 0x9000ff, "COLOR = ENTER");
	mlx_string_put(m->mlx, m->win, 40, 240, 0x9000ff, "MAKE DISCO = SPACE");
	mlx_string_put(m->mlx, m->win, 40, 260, 0x9000ff, "EXIT = ESC");
	return (0);
}

int		deal_key_3(int key, t_obj *map)
{
	if (key == 21 || key == 86)
		color_2(map, 1);
	if (key == 22 || key == 87)
		color_2(map, 2);
	if (key == 23 || key == 88)
		color_2(map, 3);
	if (key == 49)
		disco(map);
	if (key == 36)
		color_change(map);
	expose_hook(map);
	return (0);
}

int		deal_key_2(int key, t_obj *map)
{
	if (key == 2)
		rot_y(map, 1);
	if (key == 0)
		rot_y(map, -1);
	if (key == 13)
		rot_x(map, 1);
	if (key == 1)
		rot_x(map, -1);
	if (key == 18 || key == 83)
		color(map, 1);
	if (key == 19 || key == 84)
		color(map, 2);
	if (key == 20 || key == 85)
		color(map, 3);
	else
		deal_key_3(key, map);
	expose_hook(map);
	return (0);
}

int		deal_key(int key, t_obj *map)
{
	if (key == 53)
		just_exit((void *)0);
	if (key == 123)
		move_x(map, -1);
	if (key == 124)
		move_x(map, 1);
	if (key == 126)
		move_y(map, -1);
	if (key == 125)
		move_y(map, 1);
	if (key == 69)
		zoom(map, 1);
	if (key == 78)
		zoom(map, -1);
	if (key == 12)
		rot_z(map, -1);
	if (key == 14)
		rot_z(map, 1);
	else
		deal_key_2(key, map);
	expose_hook(map);
	return (0);
}
