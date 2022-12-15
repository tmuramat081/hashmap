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

static int	_hash_insert(t_hashmap *map, t_hashmap_data *data)
{
	size_t	i;

	i = map->mask & (data->key * PRIME_1);
	while (map->data[i].key != 0)
	{
		if (map->data[i].key == data->key)
			return (HASHMAP_FAILURE);
		else
			i = map->mask & (i + PRIME_2);
	}
	map->len += 1;
	map->data[i] = *data;
	return (HASHMAP_SUCCESS);
}

int	ft_hashmap_insert(t_hashmap *map, char *key, void *value)
{
	t_hashmap_data	data;
	bool			ret;

	data.key = map->hash(key);
	data.value = value;
 	ret = _hash_insert(map, &data);
	if (_is_over_load_factor(map) == true)
	{
		if (ft_hashmap_resize(map) == HASHMAP_FAILURE)
			return (HASHMAP_FAILURE);
	}
	return (ret);
}
