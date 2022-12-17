/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:22:02 by tmuramat          #+#    #+#             */
/*   Updated: 2022/12/16 07:22:05 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

int	ft_hashmap_find(t_hashmap *map, char *key, void **arg)
{
	size_t	i;
	size_t	curr_key;

	curr_key = map->hash(key);
	i = map->mask & (curr_key * PRIME_1);
	while (map->data[i].key != 0)
	{
		if (map->data[i].key == curr_key)
		{
			*arg = map->data[i].value;
			return (HASHMAP_SUCCESS);
		}
		else
			i = map->mask & (i + PRIME_2);
	}
	*arg = NULL;
	return (HASHMAP_FAILURE);
}
