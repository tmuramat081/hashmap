/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashset_modifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:04:58 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 23:04:58 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include <stdio.h>

static bool	_is_over_load_factor(t_hashmap *map)
{
	if ((double)map->cap * REHASH_THRESHOLD < map->len)
		return (true);
	return (false);
}

static int	_hash_insert(t_hashmap *map, char *key, void *value)
{
	size_t	i;
	size_t hashed_key;

	hashed_key = map->hash(key);
	i = map->mask & (hashed_key * PRIME_1);
	while (map->data[i].in_use != false)
	{
		if (strcmp(map->data[i].key, key) == 0)
			return (HASHMAP_FAILURE);
		else
			i = map->mask & (i + PRIME_2);
	}

	map->data[i].key = key;
	map->data[i].value = value;
	map->data[i].in_use = true;
	map->len += 1;
	return (HASHMAP_SUCCESS);
}

int	ft_hashmap_insert(t_hashmap *map, char *key, void *value)
{
	bool			status;

 	status = _hash_insert(map, key, value);
	if (_is_over_load_factor(map) == true)
	{
		if (ft_hashmap_resize(map) == HASHMAP_FAILURE)
			return (HASHMAP_FAILURE);
	}
	return (status);
}
