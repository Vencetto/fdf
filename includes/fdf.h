/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:03:14 by vzomber           #+#    #+#             */
/*   Updated: 2018/03/09 20:03:15 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define W_WD 1000
# define W_HT 1000

typedef struct		s_ll
{
	char			*line;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_pnt
{
	double			x;
	double			y;
	double			z;
	int				sp;
	unsigned int	color;
}					t_pnt;

typedef struct		s_obj
{
	t_pnt			**arr;
	double			zoom;
	double			sh_x;
	double			sh_y;
	double			dist;
	int				width;
	int				height;
	void			*mlx;
	void			*win;
}					t_obj;

void				make_point(int i, int j, t_obj *map, char *arr);
void				splitter(t_ll **head, t_obj *map, int color);
void				make_arr(t_ll **head, t_obj *map);
void				add_to_list(char *line, t_ll **head);
void				show_error(char *s);
void				draw_map(t_obj *map);
void				algo(t_obj *map);
int					expose_hook(t_obj *m);
int					just_exit(void *param);
int					deal_key(int key, t_obj *map);
int					deal_key_2(int key, t_obj *map);
int					deal_key_3(int key, t_obj *map);
double				left_side(t_obj *map);
double				down_side(t_obj *map);
double				right_side(t_obj *map);
double				up_side(t_obj *map);
void				rot_z(t_obj *map, int sign);
void				rot_y(t_obj *map, int sign);
void				rot_x(t_obj *map, int sign);
void				move_x(t_obj *map, int sign);
void				color_change(t_obj *map);
void				disco(t_obj *map);
void				move_y(t_obj *map, int sign);
void				put_zero(t_obj *map);
void				line(t_obj *map, t_pnt p1, t_pnt p2);
void				add_color(t_obj *map, int i, int j, int color);
int					swich(char a);
int					find_color(char *arr);
void				scale(t_obj *map);
void				zoom(t_obj *map, int sign);
void				color(t_obj *map, int i);
void				color_2(t_obj *map, int i);
void				liner(t_obj *map, t_pnt p1, t_pnt p2, double length_xy[]);
void				liner_2(t_obj *map, t_pnt p1, t_pnt p2, double length_xy[]);
int					split_helper(char *p_arr, char **s_arr, int color);
#endif
