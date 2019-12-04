/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:30:11 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/08 13:32:11 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	write_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("Scan map:\n");
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			ft_printf("%d", map->arr_int[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	write_piece(t_piece *piece)
{
	int i;

	i = 0;
	ft_printf("Scan piece :\n");
	while (i < piece->size_y)
	{
		ft_printf("%s", piece->arr_chr[i]);
		ft_printf("\n");
		i++;
	}
}
