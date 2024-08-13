/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/13 20:31:15 by almanuel         ###   ########.fr       */
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

void    ft_free(char **str)
{
    size_t i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}
void   map_init(t_data *zona)
{
    zona->ptr = NULL;
    zona->point.x = 0;
    zona->point.y = 0;
    zona->C = 0;
    zona->E = 0;
    zona->P = 0;
}
size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
void    messagen_erro(char **str)
{
    ft_free(str);
    perror("Erro");
    exit(1);
}
void    val_retangulo(t_data *zona)
{
    size_t  ix;
    size_t  iy;
    size_t  ix1;

    ix1 = ft_strlen(zona->ptr[0]);
    iy = 0;
    while (zona->ptr[iy])
    {
            ix = 0;
            while (zona->ptr[iy][ix])
                ix++;
            if (ix1 != ix)
                messagen_erro(zona->ptr);
            ix1 = ix;
            iy++;
    }
    if (ix == iy)
        messagen_erro(zona->ptr);
    zona->point.x = ix;
    zona->point.y = iy;
}
void    val_valuer(t_data *zona)
{
    size_t ix;
    size_t iy;

    iy = 0;
    while (iy < zona->point.y)
    {
        ix = 0;
        while (ix < zona->point.x)
        {
            if (iy == 0 && zona->ptr[iy][ix] != '1')
                messagen_erro(zona->ptr);
            if (iy > 0 && iy < zona->point.y)
                if ((ix == 0 || ix == (zona->point.x - 1)) && zona->ptr[iy][ix] != '1')
                    messagen_erro(zona->ptr);
            if (iy == (zona->point.y - 1)  && zona->ptr[iy][ix] != '1')
                messagen_erro(zona->ptr);
            ix++;
        }
        iy++;
    }
}
static
    void    val_components_2(t_data *zona, size_t iy, size_t ix)
{
    if (zona->ptr[iy][ix] != '1' && zona->ptr[iy][ix] != '0' &&
            zona->ptr[iy][ix] != 'P' && zona->ptr[iy][ix] != 'E' &&
                zona->ptr[iy][ix] != 'C')
        messagen_erro(zona->ptr);  
}
void    val_components(t_data *zona)
{
    size_t  ix;
    size_t  iy;

    iy = 0;
    while (iy < zona->point.y)
    {
        ix = 0;
        while (ix < zona->point.x)
        {
            if (zona->ptr[iy][ix] == 'P')
                zona->P++;
            if (zona->ptr[iy][ix] == 'E')
                zona->E++;
            if (zona->ptr[iy][ix] == 'C')
                zona->C++;
            val_components_2(zona, iy, ix);
            ix++;
        }
        iy++;
    }
    if (zona->P != 1 || zona->E != 1 || zona->C < 1)
        messagen_erro(zona->ptr);
}
void    begin_play(t_data *zona, t_data *begin)
{
    while (begin->point.y < zona->point.y)
    {
        begin->point.x = 0;
        while (begin->point.x < zona->point.x)
        {
            if (zona->ptr[begin->point.y][begin->point.x] == 'P')
                return ;
            begin->point.x++;
        }
        begin->point.y++;
    }
}
void    copy_map(t_data *map, t_data *begin)
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
    begin->ptr = ft_split(str, '\n'); 
}

void    fill(char **tab, t_point size, t_point start, char F)
{
    size_t a = 0;

    if (tab[start.y][start.x] == 'C')
        tab[start.y][start.x] = '0';
    if (start.x < a || start.x > (size.x - 1) ||
            start.y < a || start.y > (size.y - 1) ||
                tab[start.y][start.x] != F)
        return ;
    tab[start.y][start.x] = 'F';
    fill(tab, size, (t_point){start.x - 1, start.y}, F);
    fill(tab, size, (t_point){start.x + 1, start.y}, F);
    fill(tab, size, (t_point){start.x, start.y - 1}, F);
    fill(tab, size, (t_point){start.x, start.y + 1}, F);
}
void    fool_fill(char **tab, t_point size, t_point start)
{
    tab[start.y][start.x] = '0';
    fill(tab, size, start, tab[start.y][start.x]);
}
int main(void)
{
    int i;
    t_data  zona;
    t_data  begin;

    map_init(&zona);
    map_init(&begin);
    open_zona(&zona);
    val_retangulo(&zona);
    val_valuer(&zona);
    val_components(&zona);
    begin_play(&zona, &begin);
    copy_map(&zona, &begin);
    fool_fill(begin.ptr, zona.point, begin.point);
    i = 0;
    while (begin.ptr[i])
        printf("%s\n", begin.ptr[i++]);
    ft_free(begin.ptr);
    return (0);
}