/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:55:53 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:13:22 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	find_quart(t_map *map)
{
	if (map->size_y / 2 >= map->pos_y)
		if (map->size_x / 2 >= map->pos_x)
			map->quart = 1;
		else
			map->quart = 2;
	else if (map->size_x / 2 >= map->pos_x)
		map->quart = 3;
	else
		map->quart = 4;
}

static	void	find_symb(t_map *map)
{
	int i;
	int j;

	map->is_quart = 1;
	i = 0;
	j = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (map->arr_chr[i][j] != map->symb_player
			&& map->arr_chr[i][j] != '.')
			{
				map->pos_x = j;
				map->pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static	void	solver(t_map *map)
{
	t_crd *buf;

	if (map->is_quart == 0)
	{
		find_symb(map);
		find_quart(map);
		get_manhat(map);
		while (map->plbl_arr != NULL)
		{
			if (map->prior < 0 ||
			map->prior >= map->arr_int[map->plbl_arr->y][map->plbl_arr->x])
			{
				map->prior = map->arr_int[map->plbl_arr->y][map->plbl_arr->x];
				map->pos_x = map->plbl_arr->x;
				map->pos_y = map->plbl_arr->y;
			}
			buf = map->plbl_arr;
			map->plbl_arr = map->plbl_arr->next;
			free(buf);
		}
		ft_printf("%d %d\n", map->pos_y, map->pos_x);
	}
}

void			get_result(t_map *map)
{
	if (map->plbl_arr == NULL)
	{
		ft_printf("0 0\n");
		map_death(map);
	}
	else
	{
		solver(map);
		map_death_lite(map);
	}
}
