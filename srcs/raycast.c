/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:04:18 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/07 21:33:16 by ismailalash      ###   ########.fr       */
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

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
	while (!sensor(ray_x, ray_y, game))
	{
		put_pixel(ray_x * MINIMAP_SCALE, ray_y * MINIMAP_SCALE, 0xFF00FF, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
    project_wall_column(game, player, ray_x, ray_y, cos_angle, sin_angle, i);
}

/**
 * @brief Renders the 3D vertical projection of the walls and colors the floor and ceiling.
 * @param game Pointer to the game struct (render data).
 * @param i Index of the vertical wall strip being drawn.
 * @param dist Distance from player to wall intersection.
 * 
 * @note Calls draw_floor_ceiling to draw the floor and ceiling.
 */
void render_3d(t_game *game, int i, float dist, t_texture *tex, float tex_x)
{
	int height;
	int start_y;
	int end;

	height = (WALL / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	draw_floor_ceiling(game, i, start_y, end, game->floor_color, game->ceiling_color);
    draw_textured_wall_strip(game, i, start_y, end, height, tex, tex_x);
	// while (start_y < end)
	// {
	// 	put_pixel(i, start_y, 200, game);
	// 	start_y++;
	// }
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
