/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:33:41 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:00:51 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	*init_map(void)
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(1);
	map->size_x = 0;
	map->size_y = 0;
	map->is_check = 0;
	map->is_player = 0;
	map->is_quart = 0;
	map->quart = 0;
	map->prior = -1;
	map->arr_int = NULL;
	map->arr_chr = NULL;
	map->plbl_arr = NULL;
	return (map);
}

t_piece	*init_piece(void)
{
	t_piece *piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		exit(1);
	piece->size_x = 0;
	piece->size_y = 0;
	piece->is_check = 0;
	piece->arr_chr = NULL;
	return (piece);
}
