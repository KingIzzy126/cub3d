/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:30:00 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/13 14:31:05 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_draw(t_draw *draw, t_player *player, float start_x)
{
    draw->cos_angle = cos(start_x);
    draw->sin_angle = sin(start_x);
    draw->ray_x = player->x;
    draw->ray_y = player->y;
    draw->prev_x = draw->ray_x;
    draw->prev_y = draw->ray_y;
}

void    change_name_function(t_draw *draw)
{
    if ((int)(draw->prev_x / WALL) != (int)(draw->ray_x / WALL))
    {
        if (draw->cos_angle < 0)
            draw->tex = 0;
        else
            draw->tex = 1;
        draw->tex_pos = fmodf(draw->prev_y, WALL) / WALL;
    }
    else
    {
         if (draw->sin_angle < 0)
            draw->tex = 2;
         else
            draw->tex = 3;
        draw->tex_pos = fmodf(draw->prev_x, WALL) / WALL;
    }
}