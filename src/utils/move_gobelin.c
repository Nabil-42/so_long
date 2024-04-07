/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gobelin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:28:17 by nabil             #+#    #+#             */
/*   Updated: 2024/04/07 13:35:55 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../so_long.h"
#include "../../minilibx-linux/mlx.h"

void find_gobelin_position(t_map *map, int *x, int *y, int gobelin_number)
{
    int i;
    int j;
    int buff = gobelin_number;
    j = 0;
    i = 0;
    while (i < map->map_y)
    {
        while (j < map->map_x)
        {
            if (map->grid[i][j] == 'G')
            {
                *x = j;
                *y = i;
                if (buff == 0)
                    return;
                buff--;
            }
            ++j;
        }
        j = 0;
        ++i;
    }
    *x = -1;
    *y = -1;
}

int is_valid_move_gobelin(t_map *map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->map_x || y >= map->map_y)
        return (0);
    if ((map->grid[y][x] == 'E' && map->collectible != 0))
        return (0);
    if (map->grid[y][x] != '1' && map->grid[y][x] != 'C'
        && map->grid[y][x] != 'G')
        return (1);
    return (0);
}

void move_gobelin_to(t_map *map, int x, int y, int gobelin_number)
{
    int current_x;
    int current_y;
    find_gobelin_position(map, &current_x, &current_y, gobelin_number);
    if (map->grid[y][x] == 'P')
        close_window(map);
    if (map->grid[y][x] == 'E' && map->collectible == 0)
        close_window(map);
    map->grid[current_y][current_x] = '0'; 
    map->grid[y][x] = 'G';
}

void	move_gobelin(t_map *map, int keycode, int gobelin_number)
{
    (void)gobelin_number;
    int new_x;
    int new_y;
    int current_x;
    int current_y;
    find_gobelin_position(map, &current_x, &current_y, gobelin_number);
    int dx = 0;
    int dy = 0;
    if (keycode == 0)
        dy = -1;
    else if (keycode == 1)
        dx = -1;
    else if (keycode == 2)
        dy = 1;
    else if (keycode == 3)
        dx = 1;
    new_x = current_x + dx;
    new_y = current_y + dy;
    if (is_valid_move_gobelin(map, new_x, new_y))
        move_gobelin_to(map, new_x, new_y, gobelin_number);
}

int update_goblins(t_map *map) 
{
    int i;
    int direction; 
    direction = 0;
    i = 0;
    while (i < map->count_gobelin) {
        direction = rand() % 4; // Générer un nombre aléatoire entre 0 et 3 inclus
        move_gobelin(map, direction, i);
        if (map->counter % 2 == 0)
            render_map(map,map->ptr_mlx, map->ptr_windows, direction);
        else render_map_bis(map,map->ptr_mlx, map->ptr_windows, direction);
        i++;
    }
    return (0);
}