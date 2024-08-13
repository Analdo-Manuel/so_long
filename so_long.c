/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/13 15:43:26 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
    size_t  line_map(char *str)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            j++;
        i++;
    }
    return (j + 1);
}
static
    size_t  culun_map(char *str)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] != '\n')
            j++;
        i++;
    }
    return (j);
}
static
    char    **ft_split(char *str)
{
    char    **p;
    char    *line;
    size_t i;
    size_t j;
    size_t k;

    line = str;
    p = (char **) malloc(sizeof(char *) * (line_map(line) + 1));
    if (!p)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        k = 0;
        p[j] = (char *) malloc(sizeof(char) * (culun_map(line) + 1 ));
        while (str[i] && str[i] != '\n')
            p[j][k++] = str[i++];
        p[j][k] = '\0';
        j++;
        i++;
    }
    p[j] = NULL;
    return (p);
}


void    copy_map(t_data *map)
{
    int fd;
    char    str[4096] = {0};
    size_t  s_read;

    fd = open("map.ber", O_RDONLY);
    if (fd < 0)
    {
        perror("error de fichero");
        exit (1);
    }
    while ((s_read = read(fd, str, sizeof(str))) > 0)
        str[s_read] = '\0';
    map->p = ft_split(str);
    close(fd);
}

void    ft_free(char **str)
{
    size_t i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}
void   map_init(t_data *map)
{
    map->p = NULL;
    map->x = 0;
    map->y = 0;
}

size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
void    validation(t_data *map)
{
    size_t ix;
    size_t iy;
    size_t ix1;

    ix1 = ft_strlen(map->p[0]);
    iy = 0;
    while (map->p[iy])
    {
            ix = 0;
            while (map->p[iy][ix])
                ix++;
            if (ix1 != ix)
            {
                ft_free(map->p);
                perror("Erro");
                exit(1);
            }
            ix1 = ix;
            iy++;
    }
    map->x = ix;
    map->y = iy;
}
int main(void)
{
    int i;
    t_data  map;
    
    map_init(&map);
    copy_map(&map);
    validation(&map);
    i = 0;
    while (map.p[i])
        printf("%s\n", map.p[i++]);
    ft_free(map.p);
    return (0);
}