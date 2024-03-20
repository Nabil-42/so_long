/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:16:01 by nabil             #+#    #+#             */
/*   Updated: 2024/03/20 18:45:20 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define So_LONG_H
#include "libft/libft.h"

#define EMPTY_SPACE 0
#define WALL 1
#define START 2
#define ESCAP 3
#define COLLECTIBLE 4
#define TAILLE_CARTE 20
#define NUM_IMAGES 20
#define NUM_IMAGES_BASIC_CARACTER 2

typedef struct s_map
{
    int     height;
    int     width;
    char    **grid;
    int     current_level;
    void    *images[NUM_IMAGES];
}t_map;

// typedef struct s_basic_sprit
// {
//     char *basic_sprit[NUM_IMAGES_BASIC_CARACTER];
// } t_basic_sprit;

// t_basic_sprit basic_sprit = {
//     {
//         "sprit/Characters/basic_caracter_carot.png",
//         "sprit/Characters/basic_caracter.png"
//     }
// };






#endif