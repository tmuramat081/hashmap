/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashset_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:04:35 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 23:04:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

#define INIT_NBITS 16

size_t	default_hash(const void	*void_data, void *item)
{
	t_hashmap_data *data;

	data = (t_hashmap_data *)void_data;
	printf("%d\n", data->value);
	return ((size_t)data);
}

t_hashmap	*ft_hashmap_init(size_t(*hash)(const void *data))
{
	t_hashmap	*new_map;

	new_map = malloc(sizeof(t_hashmap));
	if (!new_map)
		return (NULL);
	new_map->nbits = INIT_NBITS;
	new_map->cap = (size_t)(1 << new_map ->nbits);
	new_map->mask = new_map->cap - 1;
	if (!hash)
		new_map->hash = default_hash;
	else
		new_map->hash = hash;
	new_map->data = malloc(sizeof(t_hashmap_data) * new_map->cap);
	if (!new_map->data)
	{
		free(new_map);
		return (NULL);
	}
	ft_hashmap_clear(new_map);
	return (new_map);
}
