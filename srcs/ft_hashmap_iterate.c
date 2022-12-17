/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_iterate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:42:19 by kkohki            #+#    #+#             */
/*   Updated: 2022/12/17 16:42:21 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

int ft_hashmap_iterate(t_hashmap *map, int(*f)(t_hashmap_data *, void *), void * item)
{
    size_t          i;
    int             status;
    t_hashmap_data  data;

	i = 0;
	while (i < map->cap)
	{
		if (map->data[i].in_use == true)
		{
			data = map->data[i];
			status = f(&data, item);
			if (status != HASHMAP_SUCCESS)
			{
				return (status);
			}
		}
		i++;
	}
	return (HASHMAP_SUCCESS);
}
