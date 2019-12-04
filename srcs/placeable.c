/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:25:43 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:08:32 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int	add_element(int y_piece, int x_piece, t_piece *piece, t_map *map)
{
	char	p_el;
	char	map_el;

	p_el = piece->arr_chr[y_piece][x_piece];
	map_el = map->arr_chr[map->pos_y][map->pos_x];
	if (p_el == map_el || p_el == '.')
		return (1);
	if (p_el == '*' && map_el == '.')
		return (1);
	if (p_el == '*' &&
	(map_el == map->symb_player || map_el == (map->symb_player + 32))
	&& map->ovlap == 0)
	{
		map->ovlap = 1;
		return (1);
	}
	else
	{
		map->ovlap = 0;
		return (0);
	}
}

static	int	is_placeable(t_map *map, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->ovlap = 0;
	while (i < piece->size_y)
	{
		j = 0;
		while (j < piece->size_x)
		{
			if (add_element(i, j, piece, map) == 0)
				return (0);
			map->pos_x++;
			j++;
		}
		i++;
		map->pos_y++;
		map->pos_x = map->pos_x - j;
	}
	if (map->ovlap == 1)
		return (1);
	else
		return (0);
}

void		get_placeable_arr(t_map *map, t_piece *piece)
{
	int		i;
	int		j;
	t_crd	*crd;

	i = 0;
	map->plbl_arr = NULL;
	while (i <= map->size_y - piece->size_y)
	{
		j = 0;
		while (j <= map->size_x - piece->size_x)
		{
			map->pos_x = j;
			map->pos_y = i;
			if (is_placeable(map, piece))
			{
				crd = init_list(i, j);
				ft_crdadd(&map->plbl_arr, crd);
			}
			j++;
		}
		i++;
	}
}
