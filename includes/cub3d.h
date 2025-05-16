/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:13:59 by ismailalash       #+#    #+#             */
/*   Updated: 2025/05/15 15:50:53 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

# define WIDTH 800
# define HEIGHT 800
# define WALL 35

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

# define PI 3.14159265358979323846

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct s_player
{
    float x;
    float y;
    float angle;

    bool key_up;
    bool key_down;
    bool key_left;
    bool key_right;
    bool left_rotate;
    bool right_rotate; 
}   t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    void *img;

    char *data;
    int bpp;
    int size_line;
    int endian;
    t_player player;

    char **map;
}   t_game;

// player.c
void    init_player(t_player *player);
int     key_press(int keycode, t_player *player);
int     key_release(int keycode, t_player *player);
void    move_player(t_player *player);


#endif