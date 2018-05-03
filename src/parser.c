/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:20:56 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/10 19:20:59 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	make_point(int i, int j, t_obj *map, char *arr)
{
	t_pnt	pnt;

	pnt.x = i;
	pnt.y = j;
	pnt.z = ft_atoi(arr);
	if (pnt.z > 0)
		pnt.sp = 1;
	else
		pnt.sp = 0;
	map->arr[j][i] = pnt;
}

void	add_color(t_obj *map, int i, int j, int color)
{
	if (i > map->width)
		show_error("map is not valid\n");
	map->arr[j][i].color = color;
}

void	splitter(t_ll **head, t_obj *map, int color)
{
	t_ll	*tmp;
	char	**p_arr;
	char	**s_arr;
	int		i;
	int		j;

	tmp = *head;
	j = 0;
	while (tmp)
	{
		p_arr = ft_strsplit(tmp->line, ' ');
		i = -1;
		while (p_arr[++i])
		{
			color = 0xFFFFFF;
			if (ft_strchr(p_arr[i], ','))
				color = split_helper(p_arr[i], s_arr, color);
			make_point(i, j, map, p_arr[i]);
			add_color(map, i, j, color);
			free(p_arr[i]);
		}
		free(p_arr);
		tmp = tmp->next;
		j++;
	}
}

int		swich(char a)
{
	if (a == 'A' || a == 'a')
		return (10);
	else if (a == 'B' || a == 'b')
		return (11);
	else if (a == 'C' || a == 'c')
		return (12);
	else if (a == 'D' || a == 'd')
		return (13);
	else if (a == 'E' || a == 'e')
		return (14);
	else if (a == 'F' || a == 'f')
		return (15);
	return (0);
}

int		find_color(char *arr)
{
	int	n;
	int	i;
	int t;

	i = ft_strlen(arr) - 1;
	t = 0;
	n = 0;
	while (i >= 0)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			n = n + (arr[i] - '0') * pow(16, t);
		else if ((arr[i] >= 'A' && arr[i] <= 'F')
			|| (arr[i] >= 'a' && arr[i] <= 'f'))
			n = n + swich(arr[i]) * pow(16, t);
		else if (arr[i] == 'x')
			return (n);
		else
			return (0);
		i--;
		t++;
	}
	return (n);
}
