/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:38:57 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:26:50 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/srcs/ft_printf/ft_printf.h"

typedef struct		s_crd
{
	int				x;
	int				y;
	struct s_crd	*next;
}					t_crd;

typedef struct		s_map
{
	int				is_player;
	char			symb_player;
	char			symb_enemy;
	int				is_turn;
	int				is_check;
	int				size_x;
	int				size_y;
	int				**arr_int;
	char			**arr_chr;
	int				size_pl_arr;
	int				pos_x;
	int				pos_y;
	int				is_quart;
	int				quart;
	int				ovlap;
	int				prior;
	t_crd			*plbl_arr;
}					t_map;

typedef	struct		s_piece
{
	int				size_x;
	int				size_y;
	int				is_check;
	char			**arr_chr;
}					t_piece;

void				scan_map(t_map *map);
void				scan_piece(t_piece *piece, char *line);
void				write_piece(t_piece *piece);
void				write_map(t_map *map);
t_piece				*init_piece(void);
t_map				*init_map(void);
void				get_size_piece(t_piece *piece, char *line);
void				get_size_map(t_map *map, char *line);
void				create_arr_piece(t_piece *piece);
void				create_arr_map(t_map *map);
void				skip_lines(int i);
void				clear_2d_arr(char **arr);
void				write_log(t_piece *piece, t_map *map);
t_crd				*init_list(int y, int x);
void				ft_crdadd(t_crd **crd, t_crd *new);
void				get_placeable_arr(t_map *map, t_piece *piece);
void				get_result(t_map *map);
void				map_death_lite(t_map *map);
void				map_death(t_map *map);
void				piece_death(t_piece *piece);
void				get_manhat(t_map *map);
void				diagonal(t_map *map, int y, int x);
void				horisontal(t_map *map, int y, int x);
void				vertical(t_map *map, int y, int x);
#endif
