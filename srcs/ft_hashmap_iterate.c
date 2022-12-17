#include "ft_hashmap.h"

int hashmap_iterate(t_hashmap *map, int(*f)(void *), void * item)
{
    size_t i;
    int     ret;
    void    *data;

    i = 0;
    while (i < map->cap)
    {
        if (map->data[i].value != 0)
        {
            data = map[i].data;
            ret = f(item);
            if (ret != HASHMAP_SUCCESS) 
            {
                return (ret);
            }
        }
        i++;
    }
    return (HASHMAP_SUCCESS);
}