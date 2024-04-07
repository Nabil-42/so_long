/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:11:07 by nabil             #+#    #+#             */
/*   Updated: 2024/04/07 14:15:55 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../src/so_long.h"
#include "../minilibx-linux/mlx.h"

void map_map(t_map *map, char **argv)
{
    map->count_gobelin = 0;
    map->count_0 = 0;
    map->counter = 0;
    map->collectible = 0;
    map->cell_size = 40;
    map->filename = argv[1];
	map->ptr_mlx = mlx_init();
}

void free_images(t_map *map)
{
    int i;
    i = 0;
    while (i < 20)
    {
        mlx_destroy_image(map->ptr_mlx,map->images[i]);
        ++i;
    }
}

int	close_window(t_map *map)
{
    ft_freetab_char(map->grid);
    ft_freetab_int(map->grid_verif, map->map_y);
	free_images(map);
	mlx_destroy_window(map->ptr_mlx, map->ptr_windows);
	mlx_destroy_display(map->ptr_mlx);
	free(map->ptr_mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int timer_callback(t_map *map)
{
    update_goblins(map);
    usleep(INTERVAL_MS * 200); // Attente de 1 seconde
    mlx_loop_hook(map->ptr_mlx, timer_callback, map); 

    return 0;
}

int	main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc != 2)
        return (ft_dprintf(2, "Error: Missing the map in argument\n"), 0);
    t_map map;
    map_map(&map, argv);
    if (map.ptr_mlx == NULL)
        return (ft_dprintf(2, "Error: MinilibX initialisation failed\n"), EXIT_FAILURE);
    
    if (init_map(&map))
       return (ft_dprintf(2, "Error: Failed to initialize the map\n"), EXIT_FAILURE);
    
    if (read_map(argv[1], &map))
        return (ft_dprintf(2, "Error: Failed to read the map\n"), EXIT_FAILURE);
    load_images(&map, map.ptr_mlx);
	    
    map.ptr_windows = mlx_new_window(map.ptr_mlx, map.win_width, map.win_height, "MAMAMIA !");
    if (map.ptr_windows == NULL)
        	return (ft_freetab_char(map.grid), ft_dprintf(2, "Error: Failed to creat windows\n"), EXIT_FAILURE);
    render_map(&map, map.ptr_mlx, map.ptr_windows, KEY_S);
    mlx_hook(map.ptr_windows, 17, 0, close_window, &map);
	mlx_hook(map.ptr_windows, 2, 1L << 0, &key_hook, &map);
	mlx_loop_hook(map.ptr_mlx, timer_callback, &map);
    mlx_loop(map.ptr_mlx);
}
