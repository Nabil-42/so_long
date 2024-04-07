/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:04:37 by nabil             #+#    #+#             */
/*   Updated: 2024/04/07 14:27:40 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

void render_map_gobelin_bis(t_map *map, void *mlx, void *win, int keycode)
{
    int x;
    int y;
    map->cell_size = 40;
    y = 0;
    while (y < map->map_y)
    {
        x = 0;
        while (x < map->map_x)
        {
			map->window_x = x * map->cell_size;
			map->window_y = y * map->cell_size;
			if (map->grid[y][x] == 'G' && (keycode == 0 || keycode == 65362))
            	mlx_put_image_to_window(mlx, win, map->images[19], map->window_x, map->window_y);
			if (map->grid[y][x] == 'G' && (keycode == 1 || keycode == 65361))
            	mlx_put_image_to_window(mlx, win, map->images[17], map->window_x, map->window_y);
			if (map->grid[y][x] == 'G' && (keycode == 2 || keycode == 65364))
            	mlx_put_image_to_window(mlx, win, map->images[13], map->window_x, map->window_y);
			if (map->grid[y][x] == 'G' && (keycode == 3 || keycode == 65363))
            	mlx_put_image_to_window(mlx, win, map->images[15], map->window_x, map->window_y);
            ++x;
        }
        ++y;
    }
}

void render_map_gobelin(t_map *map, void *mlx, void *win, int keycode)
{
    int x;
    int y;
    map->cell_size = 40;
    y = 0;
    while (y < map->map_y)
    {
        x = 0;
        while (x < map->map_x)
        {
			map->window_x = x * map->cell_size;
			map->window_y = y * map->cell_size;
			if (map->grid[y][x] == 'G' && (keycode == 0 || keycode == 65362))
            	mlx_put_image_to_window(mlx, win, map->images[18], map->window_x, map->window_y);
			if (map->grid[y][x] == 'G' && (keycode == 1 || keycode == 65361))
            	mlx_put_image_to_window(mlx, win, map->images[16], map->window_x, map->window_y);
			if (map->grid[y][x] == 'G' && (keycode == 2 || keycode == 65364))
            	mlx_put_image_to_window(mlx, win, map->images[12], map->window_x, map->window_y);
			if (map->grid[y][x] == 'G' && (keycode == 3 || keycode == 65363))
            	mlx_put_image_to_window(mlx, win, map->images[14], map->window_x, map->window_y);
            ++x;
        }
        ++y;
    }
}

void render_map_hero_bis(t_map *map, void *mlx, void *win, int keycode)
{
    int x;
    int y;
    map->cell_size = 40;
    y = 0;
    while (y < map->map_y)
    {
        x = 0;
        while (x < map->map_x)
        {
			map->window_x = x * map->cell_size;
			map->window_y = y * map->cell_size;
			if (map->grid[y][x] == 'P' && (keycode == KEY_W || keycode == 65362))
            	mlx_put_image_to_window(mlx, win, map->images[11], map->window_x, map->window_y);
			if (map->grid[y][x] == 'P' && (keycode == KEY_A || keycode == 65361))
            	mlx_put_image_to_window(mlx, win, map->images[9], map->window_x, map->window_y);
			if (map->grid[y][x] == 'P' && (keycode == KEY_S || keycode == 65364))
            	mlx_put_image_to_window(mlx, win, map->images[5], map->window_x, map->window_y);
			if (map->grid[y][x] == 'P' && (keycode == KEY_D || keycode == 65363))
            	mlx_put_image_to_window(mlx, win, map->images[7], map->window_x, map->window_y);
            ++x;
        }
        ++y;
    }
}

void render_map_hero(t_map *map, void *mlx, void *win, int keycode)
{
    int x;
    int y;
    map->cell_size = 40;
    y = 0;
    while (y < map->map_y)
    {
        x = 0;
        while (x < map->map_x)
        {
			map->window_x = x * map->cell_size;
			map->window_y = y * map->cell_size;
			if (map->grid[y][x] == 'P' && (keycode == KEY_W || keycode == 65362))
            	mlx_put_image_to_window(mlx, win, map->images[10], map->window_x, map->window_y);
			if (map->grid[y][x] == 'P' && (keycode == KEY_A || keycode == 65361))
            	mlx_put_image_to_window(mlx, win, map->images[8], map->window_x, map->window_y);
			if (map->grid[y][x] == 'P' && (keycode == KEY_S || keycode == 65364))
            	mlx_put_image_to_window(mlx, win, map->images[4], map->window_x, map->window_y);
			if (map->grid[y][x] == 'P' && (keycode == KEY_D || keycode == 65363))
            	mlx_put_image_to_window(mlx, win, map->images[6], map->window_x, map->window_y);
            ++x;
        }
        ++y;
    }
}


void if_render(t_map *map, void *mlx, void *win, int keycode)
{
            char *str;
            
            str =ft_itoa(map->counter);
            if (map->grid[map->render_y][map->render_x] == '1')
            	mlx_put_image_to_window(mlx, win, map->images[1], map->window_x, map->window_y);
			if (map->grid[map->render_y][map->render_x] == '0')
            	mlx_put_image_to_window(mlx, win, map->images[0], map->window_x, map->window_y);
			if (map->grid[map->render_y][map->render_x] == 'C')
            	mlx_put_image_to_window(mlx, win, map->images[2], map->window_x, map->window_y);
			if (map->grid[map->render_y][map->render_x] == 'E' && map->collectible > 0)
            	mlx_put_image_to_window(mlx, win, map->images[1], map->window_x, map->window_y);
            if (map->grid[map->render_y][map->render_x] == 'E' && map->collectible == 0)
            	mlx_put_image_to_window(mlx, win, map->images[3], map->window_x, map->window_y);
			if (map->grid[map->render_y][map->render_x] == 'P')
            	render_map_hero(map, map->ptr_mlx, map->ptr_windows, keycode);
            if (map->grid[map->render_y][map->render_x] == 'G')
            	render_map_gobelin(map, map->ptr_mlx, map->ptr_windows, keycode);
            mlx_string_put(map->ptr_mlx, map->ptr_windows, 10, 10, 0xFFFFFF, str);
            free(str);
}

void if_render_bis(t_map *map, void *mlx, void *win, int keycode)
{
     char *str;
            
    str = ft_itoa(map->counter);
    if (map->grid[map->render_y][map->render_x] == '1')
            mlx_put_image_to_window(mlx, win, map->images[1], map->window_x, map->window_y);
	if (map->grid[map->render_y][map->render_x] == '0')
            mlx_put_image_to_window(mlx, win, map->images[0], map->window_x, map->window_y);
	if (map->grid[map->render_y][map->render_x] == 'C')
            mlx_put_image_to_window(mlx, win, map->images[2], map->window_x, map->window_y);
	if (map->grid[map->render_y][map->render_x] == 'E' && map->collectible == 0)
            mlx_put_image_to_window(mlx, win, map->images[3], map->window_x, map->window_y);
	if (map->grid[map->render_y][map->render_x] == 'P')
            render_map_hero_bis(map, map->ptr_mlx, map->ptr_windows, keycode);
    if (map->grid[map->render_y][map->render_x] == 'G')
            render_map_gobelin_bis(map, map->ptr_mlx, map->ptr_windows, keycode);
    mlx_string_put(map->ptr_mlx, map->ptr_windows, 10, 10, 0xFFFFFF, str);
    free(str);
}

void render_map(t_map *map, void *mlx, void *win, int keycode)
{
    map->render_y = 0;
    while (map->render_y < map->map_y)
    {
        map->render_x = 0;
        while (map->render_x < map->map_x)
        {
			map->window_x = map->render_x * map->cell_size;
			map->window_y = map->render_y * map->cell_size;
            if_render(map, mlx, win, keycode);
            ++map->render_x;
        }
        ++map->render_y;
    }
}

void render_map_bis(t_map *map, void *mlx, void *win, int keycode)
{
     map->render_y = 0;
    while (map->render_y < map->map_y)
    {
        map->render_x = 0;
        while (map->render_x < map->map_x)
        {
			map->window_x = map->render_x * map->cell_size;
			map->window_y = map->render_y * map->cell_size;
            if_render_bis(map, mlx, win, keycode);
            ++map->render_x;
        }
        ++map->render_y;
    }
}