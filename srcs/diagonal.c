/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:16:47 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:24:50 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	diagonal_down(t_map *map, int y, int x)
{
	int y_l;
	int x_l;
	int count;

	y_l = y;
	x_l = x;
	count = 1;
	while (x_l >= 0 && y_l >= 0)
	{
		if (count < map->arr_int[y_l][x_l] || map->arr_int[y_l][x_l] == 0)
			map->arr_int[y_l][x_l] = count;
		vertical(map, y_l, x_l);
		horisontal(map, y_l, x_l);
		x_l--;
		y_l--;
		count++;
	}
}

static	void	diagonal_up(t_map *map, int y, int x)
{
	int y_l;
	int x_l;
	int count;

	y_l = y;
	x_l = x;
	count = 1;
	while (x_l < map->size_x && y_l < map->size_y)
	{
		if (count < map->arr_int[y_l][x_l] || map->arr_int[y_l][x_l] == 0)
			map->arr_int[y_l][x_l] = count;
		vertical(map, y_l, x_l);
		horisontal(map, y_l, x_l);
		x_l++;
		y_l++;
		count++;
	}
}

void			diagonal(t_map *map, int y, int x)
{
	diagonal_down(map, y, x);
	diagonal_up(map, y, x);
}
