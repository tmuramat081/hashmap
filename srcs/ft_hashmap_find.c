/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:22:02 by tmuramat          #+#    #+#             */
/*   Updated: 2022/12/17 17:11:51 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

int	ft_hashmap_find(t_hashmap *map, char *key, void **arg)
{
	size_t	i;
	size_t	hashed_key;

	hashed_key = map->hash(key);
	i = map->mask & (hashed_key * PRIME_1);
	while (map->data[i].in_use == true)
	{
		if (ft_strcmp(map->data[i].key, key) == 0)
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
