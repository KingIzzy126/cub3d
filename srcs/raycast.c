/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:04:18 by ismailalash       #+#    #+#             */
/*   Updated: 2025/05/20 18:04:59 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_lines(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle;
    float sin_angle;
    float ray_x;
    float ray_y;
    float dist;
    float height;
    int start_y;
    int end;
    (void)i;
    
    cos_angle = cos(start_x);
    sin_angle = sin(start_x);
    ray_x = player->x;
    ray_y = player->y;
    while(!sensor(ray_x, ray_y, game))
    {
        // put_pixel(ray_x, ray_y, 0xFF00FF, game);
        ray_x += cos_angle;
        ray_y += sin_angle;
    }
    dist = distance(player->x, player->y, ray_x, ray_y, game);
    height = (WALL / dist) * (WIDTH / 2);
    start_y = (HEIGHT - height) / 2;
    end = start_y + height;
    while(start_y < end)
    {
        put_pixel(i, start_y, 255, game);
        start_y++;
    }
}

int draw_loop(t_game *game)
{
    float fraction;
    float start_x;
    int i;
    t_player *player;
    
    player = &game->player;
    move_player(player);
    clear_trail(game);
    // draw_square(player->x, player->y, 10, 0x00FF00, game);
    // draw_map(game);
    
    fraction = PI / 3 / WIDTH;
    start_x = player->angle - PI / 6;
    i = 0;
    while(i < WIDTH)
    {
        draw_lines(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}
