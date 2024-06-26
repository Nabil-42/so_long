/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keybord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:38:27 by nabil             #+#    #+#             */
/*   Updated: 2024/04/07 13:46:47 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../so_long.h"
#include "../../minilibx-linux/mlx.h"

void find_character_position(t_map *map, int *x, int *y)
{
    int i;
    int j;
    j = 0;
    i = 0;
    while (i < map->map_y)
    {
        while (j < map->map_x)
        {
            if (map->grid[i][j] == 'P')
            {
                *x = j;
                *y = i;
                return;
            }
            ++j;
        }
        j = 0;
        ++i;
    }
    *x = -1;
    *y = -1;
}

int is_valid_move(t_map *map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->map_x || y >= map->map_y)
        return (0);
    if ((map->grid[y][x] == 'E' && map->collectible != 0))
        return (0);
    if (map->grid[y][x] != '1')
        return (1);
    return (0);
}



void move_player_to(t_map *map, int x, int y)
{
    int current_x;
    int current_y;
    find_character_position(map, &current_x, &current_y);
    if (map->grid[y][x] == 'C')
            map->collectible -= 1;
    if (map->grid[y][x] == 'G')
        close_window(map);
    if (map->grid[y][x] == 'E' && map->collectible == 0)
        close_window(map);
    map->grid[current_y][current_x] = '0'; 
    map->grid[y][x] = 'P';
}



void	move_character(t_map *map, int keycode)
{
    int new_x;
    int new_y;

    int current_x;
    int current_y;
    find_character_position(map, &current_x, &current_y);
    int dx = 0;
    int dy = 0;
    if (keycode == KEY_W)
        dy = -1;
    else if (keycode == KEY_A)
        dx = -1;
    else if (keycode == KEY_S)
        dy = 1;
    else if (keycode == KEY_D)
        dx = 1;
    new_x = current_x + dx;
    new_y = current_y + dy;
    if (is_valid_move(map, new_x, new_y))
        move_player_to(map, new_x, new_y);
    
}

int key_hook(int keycode, t_map *map)
{
    map->counter += 1;
    if (keycode == KEY_W || keycode == 65362)
        w_fonction(map, keycode);
    
    else if (keycode == KEY_A || keycode == 65361)
    {
         a_fonction(map, keycode);
    }
    else if (keycode == KEY_S || keycode == 65364)
    {
        s_fonction(map, keycode);
    }
    else if (keycode == KEY_D || keycode == 65363)
    {
        d_fonction(map, keycode); 
    }
    else if (keycode == 65307)
        return(close_window(map), 1);
    return (0);
}
