/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:03:10 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/19 20:14:04 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_crd	*init_list(int y, int x)
{
	t_crd	*crd;

	if (!(crd = (t_crd *)malloc(sizeof(t_crd))))
		exit(0);
	crd->x = x;
	crd->y = y;
	crd->next = NULL;
	return (crd);
}

void	ft_crdadd(t_crd **crd, t_crd *new)
{
	new->next = *crd;
	*crd = new;
}
