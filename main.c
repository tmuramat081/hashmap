#include "ft_hashmap.h"
#include <libc.h>

/*
int func(void *void_data)
{
    t_hashmap_data *data;

    data = void_data;
    printf("%s: %d\n", data->key, data->value);
    return (0);
}
*/

void print_env(char **envp)
{
    size_t  i;

    i = 0;
    while (envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
    
}


int main(int argc, char **argv, char **envp)
{
    t_hashmap *m;
    int n1 = 1;
    int n2 = 2;
    int n42 = 42;
    void *data;

    (void)argc;
    (void)argv;
    print_env(envp);
    m = ft_hashmap_init(hashmap_hash_int);
    ft_hashmap_insert(m, "one", &n1);
    ft_hashmap_insert(m, "two", &n2);
    ft_hashmap_insert(m, "three", &n2);
    ft_hashmap_insert(m, "forty_two", &n42);
    ft_hashmap_find(m, "forty_two", &data);
        
    printf("%d\n", *(int *)data);
    return (0);
}
