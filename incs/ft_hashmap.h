/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:28:43 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 16:28:43 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_H
# define FT_HASHMAP_H

# define HASHMAP_SUCCESS 1
# define HASHMAP_FAILURE 0

# define PRIME_1 73
# define PRIME_2 5009
# define REHASH_THRESHOLD 0.8

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_hashmap_data {
	size_t	key;
	void	*value;
}	t_hashmap_data;

typedef struct s_hashmap {
	size_t			nbits;
	size_t			mask;
	t_hashmap_data	*data;
	size_t			len;
	size_t			cap;
	size_t 			(*hash)(const void *);
}	t_hashmap;

t_hashmap	*ft_hashmap_init(size_t(*hash)(const void *data));
void		ft_hashmap_clear(t_hashmap *map);
void		ft_hashmap_delete(t_hashmap **map);
int			ft_hashmap_insert(t_hashmap *map, char *key, void *value);
int			ft_hashmap_resize(t_hashmap *map);
int			ft_hashmap_get(t_hashmap *map, char *key, void **arg);
size_t		hashmap_hash_int(const void* data);
#endif