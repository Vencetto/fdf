/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:02:23 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/09 20:02:25 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	show_error(char *s)
{
	ft_putendl(s);
	exit(0);
}

void	algo(t_obj *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, W_HT, W_WD, "mlx h");
	map->sh_x = W_WD / 2;
	map->sh_y = W_HT / 2;
	scale(map);
	put_zero(map);
	rot_x(map, 1);
	draw_map(map);
	mlx_string_put(map->mlx, map->win, 420, 100, 0x00ffcb, "PRESS ENTER");
	mlx_hook(map->win, 17, 0, &just_exit, (void *)0);
	mlx_hook(map->win, 2, 5, deal_key, map);
	mlx_loop(map->mlx);
}

void	make_arr(t_ll **head, t_obj *map)
{
	char	**p_arr;
	int		height;
	int		i;

	map->width = 0;
	p_arr = ft_strsplit((*head)->line, ' ');
	i = 0;
	while (p_arr[i++])
		map->width++;
	while (--i >= 0)
		free(p_arr[i]);
	free(p_arr);
	map->arr = (t_pnt **)malloc(sizeof(t_pnt*) * map->height);
	height = map->height;
	while (height--)
		map->arr[height] = (t_pnt *)malloc(sizeof(t_pnt) * map->width);
	splitter(head, map, 0xFFFFFF);
}

void	add_to_list(char *line, t_ll **head)
{
	t_ll	*new;
	t_ll	*tmp;

	new = (t_ll*)malloc(sizeof(t_ll));
	new->next = NULL;
	new->line = line;
	if (*head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_obj	map;
	t_ll	*head;

	if (ac == 2)
	{
		head = NULL;
		map.height = 0;
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			add_to_list(line, &head);
			map.height++;
		}
		make_arr(&head, &map);
		algo(&map);
	}
	else
		ft_putstr("usage: ./fdf <map-file>\n");
	return (0);
}
