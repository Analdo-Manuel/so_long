/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:00:13 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/16 13:13:47 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    copy_map(t_data *map)
{
    char    str[4096] = {'\0'};
    size_t  i;
    size_t  j;
    size_t  k;

    i = 0;
    k = 0;
    while (map->ptr[i])
    {
        j = 0;
        while (map->ptr[i][j])
            str[k++] = map->ptr[i][j++];
        str[k++] = '\n';
        i++;
    }
    str[k] = '\0';
    map->map = ft_split(str, '\n'); 
}
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
char    **ft_split(char *str, char c)
{
    char    **ptr;
    char    *line;
    size_t i;
    size_t j;
    size_t k;

    line = str;
    ptr = (char **) malloc(sizeof(char *) * (line_map(line) + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        k = 0;
        ptr[j] = (char *) malloc(sizeof(char) * (culun_map(line) + 1 ));
        while (str[i] && str[i] != c)
            ptr[j][k++] = str[i++];
        ptr[j][k] = '\0';
        j++;
        i++;
    }
    ptr[j] = NULL;
    return (ptr);
}
void    open_zona(t_data *zona)
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
    zona->ptr = ft_split(str, '\n');
    close(fd);
}