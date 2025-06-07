/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:02:20 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/07 15:55:54 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if a given point (px, py) is inside a wall or out of bounds.
 * 
 * @param px The x-coordinate of the point to check.
 * @param py The y-coordinate of the point to check.
 * @param game Pointer to the game structure containing the map.
 * @return true If the point is inside a wall or out of bounds.
 * @return false If the point is valid and not inside a wall.
 */
bool sensor(float px, float py, t_game *game)
{
    int x;
    int y;

    x = (int)(px / WALL);
    y = (int)(py / WALL);
    
    if (x < 0 || y < 0 || !game->map[y]) // Check if point is out of bounds
        return (true); // Out of bounds
    if (x >= (int)ft_strlen(game->map[y])) // Check if x exceeds the row length
        return (true); 
    return (game->map[y][x] == '1');
}

/** * @brief Checks all the 4 player corners if it's colliding with a wall.
 * @param x Player's x position.
 * @param y Player's y position.
 * @param game Pointer to the game struct.
 * @param player_size Size of the player (for collision detection).
 * @return true if collision detected, false no collision.
 */

bool is_colliding(float x, float y, t_game *game, float player_size)
{
    if (sensor(x - player_size, y - player_size, game)) // Top-left
        return true; 
    if (sensor(x + player_size, y - player_size, game)) // Top-right
        return true;
    if (sensor(x - player_size, y + player_size, game)) // Bottom-left
        return true;
    if (sensor(x + player_size, y + player_size, game)) // Bottom-right
        return true;
    return false;
}

float distance(float x1, float y1, float x2, float y2, t_game *game)
{
    float delta_x;
    float delta_y;
    float angle;
    float fix_dist;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    angle = atan2(delta_y, delta_x) - game->player.angle;
    fix_dist = sqrt(delta_x * delta_x + delta_y * delta_y) * cos(angle);
    return (fix_dist);
}

int	close_window(t_game *game) // Close window
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}