/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:16:01 by nabil             #+#    #+#             */
/*   Updated: 2024/04/07 13:59:52 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define So_LONG_H
#include "../libft/libft.h"
#include <stdlib.h>
#include <time.h>

#define EMPTY_SPACE 0
#define WALL 1
#define START 'P'
#define ESCAP 'E'
#define COLLECTIBLE 'C'
#define NUM_IMAGES 20
#define INTERVAL_MS 1000
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_error
{
    int flag_exit;
    int flag_start;
} t_error;


typedef struct s_map
{
    int count_move_gobelin;
    int count_gobelin;
    int render_x;
    int render_y;
    int **grid_verif;
    int count_0;
    int collectible;
    int counter;
    int cell_size;
	int window_x;
    int window_y;
    int fd;
	int i;
	int j;
    int k;
	char *line;
    char *filename;
    int     map_y;
    int     map_x;
    int     flag;
    int     win_height;
    int     win_width;
    char    **grid;
    int     current_level;
    void    *images[NUM_IMAGES];
    void    *ptr_mlx;
    void    *ptr_windows;
    t_error error;
}t_map;

typedef struct s_basic
{
    char *basic_sprit[20];
}t_basic;

typedef struct s_player
{   
    int player_x;
    int player_y;
    
}t_player;

typedef struct s_collect
{   
    int collect_x;
    int collect_y;
    
}t_collect;

typedef struct s_gobelin
{   
    int gobelin_x;
    int gobelin_y;
    
}t_gobelin;

void    w_fonction(t_map *map, int keycode);
void    a_fonction(t_map *map, int keycode);
void    s_fonction(t_map *map, int keycode);
void    d_fonction(t_map *map, int keycode);
void	move_character(t_map *map, int keycode);
int chemin_valide(t_map *map);
int key_hook(int keycode, t_map *map);
void render_map(t_map *map, void *mlx, void *win, int keycode);
void render_map_bis(t_map *map, void *mlx, void *win, int keycode);
void	load_images(t_map *map, void *init);
int read_map(char *filename, t_map *map);
int	init_map(t_map *map);
int check_grid(t_map *map);
int	close_window(t_map *map);
int check_taille_map(char *filename, t_map *map);
int malloc_tab(t_map *map);
int update_goblins(t_map *map);






#endif