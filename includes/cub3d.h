/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:13:59 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/07 22:18:58 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

# define WIDTH 750
# define HEIGHT 700
# define WALL 40
# define MINIMAP_SCALE 0.2
# define COLLISION_BUFFER 0.5

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124

# define PI 3.14159265358979323846

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct s_game t_game;

typedef struct s_texture
{
	void	*img;
	char		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_rayhit
{
	float	x;
	float	y;
	float	distance;
	char	direction; // 'N', 'S', 'E', 'W'
}	t_rayhit;

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
    t_game *game;
}   t_player;

typedef struct s_game
{
    t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
    void *mlx;
    void *win;
    void *img;

    char *data;
    int bpp;
    int size_line;
    int endian;
    int floor_color;
    int ceiling_color;

    char **map;
    t_player player;
}   t_game;

// draw.c 
void put_pixel(int x, int y, int color, t_game *game);
void draw_square(int x, int y, int size, int color, t_game *game);
void draw_map(t_game *game);
void clear_trail(t_game *game);

// init.c
void init_game(t_game *game);
char **get_map(void);
void load_texture(t_game *game, t_texture *tex, char *path);

// moves.c
void	move_up(t_player *player, int speed, float cos_a, float sin_a);
void	move_down(t_player *player, int speed, float cos_a, float sin_a);
void	move_left(t_player *player, int speed, float cos_a, float sin_a);
void	move_right(t_player *player, int speed, float cos_a, float sin_a);

// player.c
void	init_player(t_player *player);
int     key_press(int keycode, t_player *player);
int     key_release(int keycode, t_player *player);
void	rotate_player(t_player *player);
void    move_player(t_player *player);

// raycast.c
int draw_loop(t_game *game);
void render_3d(t_game *game, int i, float dist, t_texture *tex, float tex_x);
void draw_lines(t_player *player, t_game *game, float start_x, int i);
void draw_floor_ceiling(t_game *game, int x, int wall_top, int wall_bottom, int floor_color, int ceiling_color);
void draw_minimap(t_game *game);

// texture.c
t_texture *get_wall_texture(t_game *game, float ray_x, float ray_y, float cos_a, float sin_a);
void draw_textured_wall_strip(t_game *game, int i, int start_y, int end_y, int height, t_texture *tex, float tex_x);
void project_wall_column(t_game *game, t_player *player, float ray_x, float ray_y, float cos_angle, float sin_angle, int x);

// utils.c
bool sensor(float px, float py, t_game *game);
bool is_colliding(float x, float y, t_game *game, float player_size);
float distance(float x1, float y1, float x2, float y2, t_game *game);
int	close_window(t_game *game);
size_t	ft_strlen(const char *str);

#endif