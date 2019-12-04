/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:25:48 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:33:48 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		convert_symb(t_map *map, char symb)
{
	if (symb == '.')
		return (0);
	if (symb == map->symb_enemy)
		return (1);
	return (0);
}

static	void	map_line_death(char **map_line)
{
	free(map_line[0]);
	free(map_line[1]);
	free(map_line[2]);
	free(map_line);
}

void			scan_map(t_map *map)
{
	char	**map_line;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	skip_lines(1);
	while (i < map->size_y)
	{
		get_next_line(0, &line);
		map_line = ft_strsplit(line, ' ');
		map->arr_chr[i] = ft_strdup(map_line[1]);
		j = 0;
		while (j < map->size_x)
		{
			map->arr_int[i][j] = convert_symb(map, map_line[1][j]);
			j++;
		}
		i++;
		map_line_death(map_line);
		free(line);
	}
}

void			scan_piece(t_piece *piece, char *line)
{
	char	*line2;
	int		i;

	i = 0;
	line2 = NULL;
	piece->is_check = 1;
	get_size_piece(piece, line);
	create_arr_piece(piece);
	while (i < piece->size_y)
	{
		get_next_line(0, &line2);
		piece->arr_chr[i] = ft_strdup(line2);
		i++;
		free(line2);
	}
}
