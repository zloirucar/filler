/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:24:11 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:05:17 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	parse_player(t_map *map, char *line)
{
	map->is_player = 1;
	if (ft_strstr(line, "$$$ exec p1") && ft_strstr(line, "oelaina"))
	{
		map->symb_player = 'O';
		map->symb_enemy = 'X';
		map->is_turn = 1;
		return ;
	}
	else if (ft_strstr(line, "$$$ exec p2") && ft_strstr(line, "oelaina"))
	{
		map->symb_player = 'X';
		map->symb_enemy = 'O';
		map->is_turn = 0;
		return ;
	}
}

static	void	find_result(t_map *map, t_piece *piece)
{
	if (map->is_check == 1 && piece->is_check == 1)
	{
		get_placeable_arr(map, piece);
		get_result(map);
		map->is_quart = 0;
		map->quart = 0;
		map->prior = -1;
	}
}

int				main(void)
{
	t_map	*map;
	char	*line;
	t_piece	*piece;

	line = NULL;
	map = init_map();
	while (get_next_line(0, &line) > 0)
	{
		piece = init_piece();
		piece->is_check = 0;
		if (map->is_player == 0)
			parse_player(map, line);
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			get_size_map(map, line);
			create_arr_map(map);
			scan_map(map);
		}
		if (ft_strncmp(line, "Piece", 5) == 0)
			scan_piece(piece, line);
		find_result(map, piece);
		piece_death(piece);
		free(line);
	}
	return (0);
}
