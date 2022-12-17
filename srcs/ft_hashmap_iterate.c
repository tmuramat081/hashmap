/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_iterate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:43:22 by tmuramat          #+#    #+#             */
/*   Updated: 2022/12/17 09:45:37 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

int hashmap_iterate(t_hashmap *map, int (*f)(void *, void*), void *item)
{
	size_t i;
	int ret;
	void *data;

	i = 0;
	while (i < map->cap)
	{
		if (map->data[i].value != 0)
		{
			data = map[i].data;
			ret = f(data, item);
			if (ret != HASHMAP_SUCCESS)
			{
				return (ret);
			}
		}
		i++;
	}
	return (HASHMAP_SUCCESS);
}
