/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:35:34 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:11:52 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_size_piece(t_piece *piece, char *line)
{
	char	**size;

	size = ft_strsplit(line, ' ');
	piece->size_y = ft_atoi(size[1]);
	piece->size_x = ft_atoi(size[2]);
	free(size[0]);
	free(size[1]);
	free(size[2]);
	free(size[3]);
	free(size);
}

void	get_size_map(t_map *map, char *line)
{
	char **size;

	size = ft_strsplit(line, ' ');
	map->is_check = 1;
	map->size_y = ft_atoi(size[1]);
	map->size_x = ft_atoi(size[2]);
	free(size[0]);
	free(size[1]);
	free(size[2]);
	free(size[3]);
	free(size);
}

void	create_arr_piece(t_piece *piece)
{
	int i;

	i = 0;
	if (!(piece->arr_chr = (char **)malloc(sizeof(char *) * piece->size_y)))
		exit(1);
}

void	create_arr_map(t_map *map)
{
	int i;

	i = 0;
	if (!(map->arr_int = (int **)malloc(sizeof(int *) * map->size_y)))
		exit(1);
	while (i < map->size_y)
	{
		if (!(map->arr_int[i] = (int *)malloc(sizeof(int) * map->size_x)))
			exit(1);
		i++;
	}
	i = 0;
	if (!(map->arr_chr = (char **)malloc(sizeof(char *) * map->size_y)))
		exit(1);
}
