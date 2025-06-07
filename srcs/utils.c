/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:02:20 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/07 15:37:23 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool sensor(float px, float py, t_game *game)
{
    int x;
    int y;

    x = (int)(px / WALL);
    y = (int)(py / WALL);
    
    if (x < 0 || y < 0 || !game->map[y])
        return (true); // Out of bounds
    if (x >= (int)ft_strlen(game->map[y])) // Protection
        return (true);
    return (game->map[y][x] == '1');
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