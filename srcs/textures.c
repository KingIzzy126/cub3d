/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:49:37 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/11 15:15:36 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void select_texture(float cos_a, float sin_a, float ray_x, float prev_x, float prev_y, int *tex, float *tex_pos)
{
    // Determine which texture to use based on the direction of the ray
    if ((int)(prev_x / WALL) != (int)(ray_x / WALL))
    {
        *tex = cos_a < 0 ? 0 : 1; // Vertical wall hit
        *tex_pos = fmodf(prev_y, WALL) / WALL; // Vertical texture position
    }
    else
    {
        *tex = sin_a < 0 ? 2 : 3; // Horizontal wall hit
        *tex_pos = fmodf(prev_x, WALL) / WALL; // Horizontal texture position
    }
}

void cast_ray(t_player *player, t_game *game, float start_x, float *dist, int *tex, float *tex_pos)
{
    float cos_angle;
    float sin_angle;
    float ray_x;
    float ray_y;
    float prev_x;
    float prev_y;

    cos_angle = cos(start_x);
    sin_angle = sin(start_x);
    ray_x = player->x;
    ray_y = player->y;

    while (!sensor(ray_x, ray_y, game))
    {
        put_pixel(ray_x * MINIMAP_SCALE, ray_y * MINIMAP_SCALE, 0xFF00FF, game);
        prev_x = ray_x;
        prev_y = ray_y;
        ray_x += cos_angle;
        ray_y += sin_angle;
    }
    *dist = distance(player->x, player->y, ray_x, ray_y, game);
    select_texture(cos_angle, sin_angle, ray_x, prev_x, prev_y, tex, tex_pos);
}

void render_wall_texture(t_game *game, int i, int start_y, int end, int height, int tex, float tex_pos)
{
    float step;
    float tex_y;
    int tex_x;
    int color;
    int ty;
    int index;
    t_texture *t;


    t = &game->textures[tex];
    step = (float)t->height / height;
    tex_y = 0;
    tex_x = (int)(tex_pos * t->width);

    while (start_y < end)
    {
        ty = (int)tex_y;
        index = ty * t->size_line + tex_x * (t->bpp / 8);
        color = (unsigned char)t->data[index] |
                ((unsigned char)t->data[index + 1] << 8) |
                ((unsigned char)t->data[index + 2] << 16);
        put_pixel(i, start_y, color, game);
        tex_y += step;
        start_y++;
    }
}
