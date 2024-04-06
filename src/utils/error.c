/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:16:58 by nabil             #+#    #+#             */
/*   Updated: 2024/04/06 15:11:52 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

int malloc_tab(t_map *map)
{
    int y;
    int x;
    
    map->grid_verif = malloc(sizeof(int *) * map->map_y);
    if (map->grid_verif == NULL)
        return (free(map->grid_verif), ft_dprintf(2, "Erreur: malloc_tab malloc en y\n"));
    y = 0;
    while (y < map->map_y)
    {
        x = 0;
        map->grid_verif[y] = malloc(sizeof(int) * (map->map_x - 1));
        if (map->grid_verif == NULL)
            return (ft_freetab_int(map->grid_verif, y), ft_dprintf(2,"Erreur: malloc_tab malloc en x\n"));
        while (x < map->map_x - 2)
        {
            map->grid_verif[y][x] = 0;
            ++x; 
        }
        ++y;
    }
    return(0);
}

int verif_path(t_map *map, int current_y, int current_x, int **verif_tab)
{
    if (current_y < 0 || current_y > map->map_y
        || current_x < 0 || current_x > map->map_x - 1
        || (map->grid[current_y][current_x] != '0' 
        && map->grid[current_y][current_x] != 'P')
        || verif_tab[current_y][current_x] == 1)
        return (1);
    
    
    map->count_0 += 1;
    verif_tab[current_y][current_x] = 1;
    verif_path(map, current_y + 1, current_x, map->grid_verif);
    verif_path(map, current_y, current_x + 1, map->grid_verif);
    verif_path(map, current_y - 1, current_x, map->grid_verif);
    verif_path(map, current_y, current_x - 1, map->grid_verif);
    return (0);
}

int chemin_valide(t_map *map)
{
    int y;
    int x;
    
    
    y = 0;
    while (y < map->map_y)
    {
        x = 0;
        while (x < map->map_x - 1)
        {
            if (map->grid[y][x] != 'P' && map->grid[y][x] != 'E'
            && map->grid[y][x] != 'C' && map->grid[y][x] != '1' && map->grid[y][x] != '0')
                return (ft_dprintf(2, "Erreur: Caractéres dans carte inconnu\n"), 1);
            if (map->grid[y][x] == 'P')
            {
                verif_path(map,y,x, map->grid_verif);
                if (map->count_0 < 4)
                    return (ft_dprintf(2, "Erreur: Pas de chemin viable pour le Héro\n"),1);
            }
            ++x;
        }
        ++y;
    }
    return (0);
}

int check_grid(t_map *map)
{
    int y;
    int x;
    map->error.flag_exit = 0;
    map->error.flag_start = 0;
    y = -1;
    while (y++ < map->map_y - 1) 
    {
        x = -1;
        while (x++ < map->map_x - 2)
        {  
            if (map->grid[0][x] != '1' || map->grid[y][0] != '1' ||
                map->grid[y][map->map_x - 2] != '1' ||
                map->grid[map->map_y - 1][x] != '1')
                        return (ft_dprintf(2, "Erreur: mur autour de la carte\n"));
            if (map->grid[y][x] == 'P')
                map->error.flag_start += 1;
            if (map->grid[y][x] == 'E')
                map->error.flag_exit += 1;
            if (map->grid[y][x] == 'C')
                map->collectible += 1;
        }
    }
    if (map->error.flag_exit != 1 || map->error.flag_start != 1 || map->collectible < 1)
        return (ft_dprintf(2, "Erreur: Probléme star/exit/collectible\n"));
    return (0);
}

int check_taille_map(char *filename, t_map *map)
{    
	map->fd = open(filename, O_RDONLY);
	if (map->fd == -1)
		return (ft_dprintf(2, "Erreur: Impossible d'ouvrir le fichier %s\n", filename), EXIT_FAILURE);
    map->line = get_next_line(map->fd);
    if (map->line == NULL)
		    return (close(map->fd), ft_dprintf(2,"Erreur: Impossible de lire le fichier %s\n", filename), EXIT_FAILURE);
	map->i = 0;
    map->k = 0;
	while (map->line != NULL)
	{
        map->j = 0;
        while (map->line[map->j])
		    ++map->j;
        free(map->line);
        if (map->k == 0)
            map->k = map->j;
        if (map->k != map->j)
            return (close(map->fd), ft_dprintf(2, "Erreur: La map n'est pas un rectangle\n"), EXIT_FAILURE);
		++map->i;
        map->line = get_next_line(map->fd);
	}
	map->map_y = map->i;
    map->map_x = map->j;
	return (close(map->fd), 0);
}
