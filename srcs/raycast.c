/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:04:18 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/11 14:03:08 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/** 
 * @brief Shoots a ray from the player and calculates where it hits a wall.
 * @note Minimap scale is to size down in minimap position (top left)
 * @note Calls 3d rendering in the end.
 */
void	draw_lines(t_player *player, t_game *game, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
    float   prev_x;
    float   prev_y;
	float	dist;
    int     tex;
    float   tex_pos;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
    prev_x = ray_x;
    prev_y = ray_y;
	while (!sensor(ray_x, ray_y, game))
	{
		put_pixel(ray_x * MINIMAP_SCALE, ray_y * MINIMAP_SCALE, 0xFF00FF, game);
        prev_x = ray_x;
        prev_y = ray_y;
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	dist = distance(player->x, player->y, ray_x, ray_y, game);
    if ((int)(prev_x / WALL) != (int)(ray_x / WALL))
    {
        tex = cos_angle < 0 ? 0 : 1;
        tex_pos = fmodf(prev_y, WALL) / WALL;
    }
    else
    {
        tex = sin_angle < 0 ? 2 : 3;
        tex_pos = fmodf(prev_x, WALL) / WALL;
    }
    render_3d(game, i, dist, tex, tex_pos);
}

/**
 * @brief Renders the 3D vertical projection of the walls and colors the floor and ceiling.
 * @param game Pointer to the game struct (render data).
 * @param i Index of the vertical wall strip being drawn.
 * @param dist Distance from player to wall intersection.
 * 
 * @note Calls draw_floor_ceiling to draw the floor and ceiling.
 */
void render_3d(t_game *game, int i, float dist, int tex, float tex_pos)
{
    int height;
    int start_y;
    int end;
    float step;
    float tex_y;
    int tex_x;
    int color;
    t_texture *t;

    height = (WALL / dist) * (WIDTH / 2);
    start_y = (HEIGHT - height) / 2;
    end = start_y + height;
    draw_floor_ceiling(game, i, start_y, end, game->floor_color, game->ceiling_color);
    t = &game->textures[tex];
    step = (float)t->height / height;
    tex_y = 0;
    tex_x = (int)(tex_pos * t->width);
    while (start_y < end)
    {
            int ty = (int)tex_y;
            int index = ty * t->size_line + tex_x * (t->bpp / 8);
            color = (unsigned char)t->data[index] |
                    ((unsigned char)t->data[index + 1] << 8) |
                    ((unsigned char)t->data[index + 2] << 16);
            put_pixel(i, start_y, color, game);
            tex_y += step;
            start_y++;
    }
}

/**
 * @brief Draws the ceiling and floor colors for a vertical column.
 * @param game Pointer to game struct.
 * @param x Column index on screen.
 * @param wall_top Starting pixel of wall on screen (lower bound of ceiling).
 * @param wall_bottom Ending pixel of wall on screen (upper bound of floor).
 * @param floor_color RGB color of floor.
 * @param ceiling_color RGB color of ceiling.
 */
void draw_floor_ceiling(t_game *game, int x, int wall_top, int wall_bottom, int floor_color, int ceiling_color)
{
    int y;

    y = 0;
    while (y < wall_top)
    {
        put_pixel(x, y, ceiling_color, game);
        y++;
    }
    y = wall_bottom;
    while (y < HEIGHT)
    {
        put_pixel(x, y, floor_color, game);
        y++;
    }
}

/**
 * @brief Draws the minimap top left corner of the game window.
 * @note Draws a square on the minimap at the specified position.
*/
void draw_minimap(t_game *game)
{
    int tile_size;
    int x;
    int y;
    
    tile_size = 8; // size of square on minimap
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                draw_square(x * tile_size, y * tile_size, tile_size, 0xAAAAAA, game);
            x++;
        }
        y++;
    }
    // Draw player on minimap
    draw_square(game->player.x / WALL * tile_size, game->player.y / WALL * tile_size, tile_size / 2, 0x00FF00, game);
}

/**
 * @brief Draws the full screen frame including all rays (walls), floor/ceiling, and minimap.
 * @param game Pointer to game struct.
 * @return Always returns 0 (used by mlx_loop_hook).
 * 
 * @note This is the the main game loop; it updates movement, clears
 *       the image, performs raycasting, and displays the result.
 * @note The coded part is responsible for drawing multiple rays with setting 
 *       the FOV and starting angle.
 */
int draw_loop(t_game *game)
{
    float fraction;
    float start_x;
    int i;
    t_player *player;
    
    player = &game->player;
    move_player(player);
    clear_trail(game);

    fraction = PI / 3 / WIDTH;
    start_x = player->angle - PI / 6;
    i = 0;
    while(i < WIDTH)
    {
        draw_lines(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    draw_minimap(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}
