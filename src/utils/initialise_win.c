/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:51:11 by nabil             #+#    #+#             */
/*   Updated: 2024/04/07 13:51:43 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

int	init_map(t_map *map)
{
	int	i;
	
	if (check_taille_map(map->filename, map))
		return (ft_dprintf(2, "Erreur: Fonction check_taille_map\n"));
	map->grid = (char **)malloc(sizeof(char *) * (map->map_y + 1));
	if (map->grid == NULL)
		return(free(map->grid), ft_dprintf(2, "Erreur pour Y map->grid\n"));
	i = 0;
	while (i < (map->map_y))
	{
		map->grid[i] = (char *)malloc(sizeof(char) * (map->map_x + 1));
		if (map->grid[i] == NULL)
			return(ft_freetab_char(map->grid),
			ft_dprintf(2, "Erreur pour X map->grid\n"));
		++i;
	}
	map->grid[map->map_y] = NULL;
	map->win_width = 40 * map->map_x;
	map->win_height = 40 * map->map_y;
	malloc_tab(map);
	return (0);
}

int read_map(char *filename, t_map *map)
{
	int fd;
	int y;
	int x;
	char *line;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Erreur: Readmap = %s\n",filename), 1);
	y = 0;
	while (y < map->map_y)
	{
		x = 0;
		line = get_next_line(fd);
		if (line == NULL)
			return (ft_dprintf(2,"Erreur: Impossible de lire le fichier %s\n", filename), 1);
		while (line[x])
		{
			map->grid[y][x] = line[x];
			++x;
		}
		(free(line), map->grid[y][x - 1] = '\0', ++y);
	}
	if (check_grid(map) || chemin_valide(map))
		return (close(fd), EXIT_FAILURE);
	return (close(fd), 0);
}

void initialise_basic_images(t_basic *basic)
{
		basic->basic_sprit[0]= "src/sprite/herbe.xpm";
		basic->basic_sprit[1]= "src/sprite/border.xpm";
		basic->basic_sprit[2]= "src/sprite/mush.xpm";
		basic->basic_sprit[3]= "src/sprite/exit.xpm";
		basic->basic_sprit[4]= "src/sprite/front_warrior_R.xpm";
		basic->basic_sprit[5]= "src/sprite/front_warrior_L.xpm";
		basic->basic_sprit[6]= "src/sprite/right_warrior_R.xpm";
		basic->basic_sprit[7]= "src/sprite/right_warrior_L.xpm";
		basic->basic_sprit[8]= "src/sprite/left_warrior_R.xpm";
		basic->basic_sprit[9]= "src/sprite/left_warrior_L.xpm";
		basic->basic_sprit[10]= "src/sprite/back_warrior_R.xpm";
		basic->basic_sprit[11]= "src/sprite/back_warrior_L.xpm";
		basic->basic_sprit[12]= "src/sprite/front_gobelin_R.xpm";
		basic->basic_sprit[13]= "src/sprite/front_gobelin_L.xpm";
		basic->basic_sprit[14]= "src/sprite/right_gobelin_R.xpm";
		basic->basic_sprit[15]= "src/sprite/right_gobelin_L.xpm";
		basic->basic_sprit[16]= "src/sprite/left_gobelin_R.xpm";
		basic->basic_sprit[17]= "src/sprite/left_gobelin_L.xpm";
		basic->basic_sprit[18]= "src/sprite/back_gobelin_R.xpm";
		basic->basic_sprit[19]= "src/sprite/back_gobelin_L.xpm";
}
void	load_images(t_map *map, void *init)
{
	t_basic basic;
	int i;
	int width;
	int height;
	
	initialise_basic_images(&basic);
	width = 40;
	height = 40;
	i = 0;
	while (i < NUM_IMAGES)
	{
		map->images[i] = mlx_xpm_file_to_image(init,basic.basic_sprit[i], &width, &height);
		if (map->images[i] == NULL)
		{
			ft_dprintf(2, "Error: Failed to load image %s\n",basic.basic_sprit[i]);
			exit(EXIT_FAILURE);
		}
		++i;
	}
}

