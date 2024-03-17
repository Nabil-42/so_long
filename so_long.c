/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:11:07 by nabil             #+#    #+#             */
/*   Updated: 2024/03/16 14:36:48 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{  
    t_map map;
	void *init;
    void *windows;
    
    if (argc != 2)
        return (ft_printf("Error: argument\n"), EXIT_FAILURE);
    
	init = mlx_init();
    if (init == 0)
        return (ft_printf("Error: MinilibX initialisation failed\n"), EXIT_FAILURE);
    
    if (!init_map(&map))
       return (ft_printf("Error: Failed to initialize the map\n\n"), EXIT_FAILURE);
    
    if (read_map(argv[1], &map))
        return (ft_printf("Error: Failed to read the map\n\n"), EXIT_FAILURE);
        
    windows = mlx_new_window(init,map.width * TILE_SIZE, map.height * TILE_SIZE, "MAMAMIA !");
    if (windows == NULL)
        return (EXIT_FAILURE);
    
    render_map(&map);
    
    mlx_loop(init);

    free_map(&map);
}