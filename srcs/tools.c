/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:41:47 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:09:29 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	list_death(t_map *map)
{
	t_crd *buf;

	while (map->plbl_arr != NULL)
	{
		buf = map->plbl_arr;
		map->plbl_arr = map->plbl_arr->next;
		free(buf);
	}
}

void			skip_lines(int i)
{
	char	*line;
	int		j;

	j = 0;
	while (j < i)
	{
		get_next_line(0, &line);
		free(line);
		j++;
	}
}

void			piece_death(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->size_y)
	{
		free(piece->arr_chr[i]);
		i++;
	}
	if (i != 0)
		free(piece->arr_chr);
	free(piece);
}

void			map_death(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->arr_int[i]);
		free(map->arr_chr[i]);
		i++;
	}
	free(map->arr_chr);
	free(map->arr_int);
	list_death(map);
	free(map);
}

void			map_death_lite(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->arr_int[i]);
		free(map->arr_chr[i]);
		i++;
	}
	free(map->arr_chr);
	free(map->arr_int);
	list_death(map);
}
