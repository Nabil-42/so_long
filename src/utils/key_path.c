/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:38:52 by nabil             #+#    #+#             */
/*   Updated: 2024/04/07 14:01:39 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

void    w_fonction(t_map *map, int keycode)
{
        move_character(map, 119);
        if (map->counter % 2 == 0)
            render_map(map, map->ptr_mlx, map->ptr_windows, keycode);
        else render_map_bis(map, map->ptr_mlx, map->ptr_windows, keycode);
}

void    a_fonction(t_map *map, int keycode)
{
        move_character(map, 97);
        if (map->counter % 2 == 0)
            render_map(map, map->ptr_mlx, map->ptr_windows, keycode);
        else render_map_bis(map, map->ptr_mlx, map->ptr_windows, keycode);
}

void    s_fonction(t_map *map, int keycode)
{
        move_character(map, 115);
        if (map->counter % 2 == 0)
            render_map(map, map->ptr_mlx, map->ptr_windows, keycode);
        else render_map_bis(map, map->ptr_mlx, map->ptr_windows, keycode);
}

void    d_fonction(t_map *map, int keycode)
{
        move_character(map, 100);
        if (map->counter % 2 == 0)
            render_map(map, map->ptr_mlx, map->ptr_windows, keycode);
        else render_map_bis(map, map->ptr_mlx, map->ptr_windows, keycode);
}
