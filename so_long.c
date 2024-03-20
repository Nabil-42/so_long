/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:11:07 by nabil             #+#    #+#             */
/*   Updated: 2024/03/20 18:48:55 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	init_map(t_map *map)
{
	int	i;
	
	map->width = 800;
	map->height = 800;
	map->grid = (char **)malloc(sizeof(char *) * TAILLE_CARTE);
	if (map->grid == NULL)
		return(free(map->grid), ft_dprintf(2, "Erreur pour Y map->grid\n"));
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = (char *)(malloc(sizeof(char) * TAILLE_CARTE));
		if (map->grid[i] == NULL)
			return(ft_freetab_char(map->grid),
			ft_dprintf(2, "Erreur pour X map->grid\n"));
		++i;
	}
	return (0);
}

int read_map(const char *filename, t_map *map)
{
	int fd;
	int i;
	int j;
	char *line;
	
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Erreur: Impossible d'ouvrir le fichier %s\n", filename));
	i = 0;
	while (i < TAILLE_CARTE)
	{
		j = 0;
		line = get_next_line(fd);
		if (line == NULL)
			return (ft_dprintf(2,"Erreur: Impossible de lire le fichier %s\n", filename));
		while (line[j])
		{
			map->grid[i][j] = line[j];
			++j;
		}
		
		++i;
	}
	return (close(fd), 0);
}

char	*all_map(int current_level)
{
	char	*maps[]=
	{
		"carte_00.txt",
		"carte_01.txt",
		"carte_02.txt",
	};
	
	return (maps[current_level]);
}

void	load_images(t_map *map, void *init)
{
	int i;
	char	*basic_sprit[]=
	{
		"carot.png",
		"sprit/c/basic_caracter.png",
	};
	
	i = 0;
	while (i < NUM_IMAGES_BASIC_CARACTER)
	{
		map->images[i] = mlx_xpm_file_to_image(init,basic_sprit[i], &map->width, &map->height);
		if (map->images[i] == NULL)
		{
			ft_dprintf(2, "Error: Failed to load image %s\n", basic_sprit[i]);
			exit(EXIT_FAILURE);
		}
	}
}

int	main()
{
    t_map map;
	map.current_level = 0;
	void *init;
    void *windows;
    
	init = mlx_init();
    if (init == NULL)
        return (ft_dprintf(2, "Error: MinilibX initialisation failed\n"), EXIT_FAILURE);
    
    if (init_map(&map))
       return (ft_dprintf(2, "Error: Failed to initialize the map\n"), EXIT_FAILURE);
    
    if (read_map(all_map(map.current_level), &map))
        return (ft_freetab_char(map.grid),ft_dprintf(2, "Error: Failed to read the map\n"), EXIT_FAILURE);
    load_images(&map, init);
	    
    windows = mlx_new_window(init,map.width, map.height, "MAMAMIA !");
    if (windows == NULL)
        return (ft_freetab_char(map.grid), ft_dprintf(2, "Error: Failed to creat windows\n"), EXIT_FAILURE);
    
    // render_map(&map);
    
    mlx_loop(init);

    ft_freetab_char(map.grid);
}
