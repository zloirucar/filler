/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:44:08 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:26:35 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			horisontal(t_map *map, int y, int x)
{
	int x_l;
	int count;

	x_l = x;
	count = 1;
	while (x_l >= 0)
	{
		if (count < map->arr_int[y][x_l] || map->arr_int[y][x_l] == 0)
			map->arr_int[y][x_l] = count;
		x_l--;
		count++;
	}
	x_l = x;
	count = 1;
	while (x_l < map->size_x)
	{
		if (count < map->arr_int[y][x_l] || map->arr_int[y][x_l] == 0)
			map->arr_int[y][x_l] = count;
		x_l++;
		count++;
	}
}

void			vertical(t_map *map, int y, int x)
{
	int y_l;
	int count;

	y_l = y;
	count = 1;
	while (y_l >= 0)
	{
		if (count < map->arr_int[y_l][x] || map->arr_int[y_l][x] == 0)
			map->arr_int[y_l][x] = count;
		y_l--;
		count++;
	}
	y_l = y;
	count = 1;
	while (y_l < map->size_y)
	{
		if (count < map->arr_int[y_l][x] || map->arr_int[y_l][x] == 0)
			map->arr_int[y_l][x] = count;
		y_l++;
		count++;
	}
}

static	void	change_arr(t_map *map, int y, int x)
{
	horisontal(map, y, x);
	vertical(map, y, x);
	diagonal(map, y, x);
}

void			get_manhat(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (map->arr_chr[i][j] == map->symb_enemy)
				change_arr(map, i, j);
			j++;
		}
		i++;
	}
}
