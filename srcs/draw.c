/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:03:15 by ismailalash       #+#    #+#             */
/*   Updated: 2025/05/20 20:51:08 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void put_pixel(int x, int y, int color, t_game *game) // Draw pixel
{
    int index;

    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0) // Bounds check
        return;
    index = y * game->size_line + x * game->bpp / 8;
    game->data[index] = color & 0xFF;
    game->data[index + 1] = (color >> 8) & 0xFF;
    game->data[index + 2] = (color >> 16) & 0xFF;
}

void draw_square(int x, int y, int size, int color, t_game *game)
{
    int i;

    i = -1;
    while (++i < size)
        put_pixel(x + i, y, color, game);
    i = -1;
    while (++i < size)
        put_pixel(x, y + i, color, game);
    i = -1;
    while (++i < size)
        put_pixel(x + size, y + i, color, game);
    i = -1;
    while (++i < size)
        put_pixel(x + i, y + size, color, game);
}

void draw_map(t_game *game)
{
    int i;
    int y;
    char **map;
    int color;

    y = 0;
    map = game->map;
    color = 0xFFFFFF;
    while (map[y])
    {
        i = 0;
        while (map[y][i])
        {
            if (map[y][i] == '1')
                draw_square(i * WALL, y * WALL, WALL, color, game);
            i++;
        }
        y++;
    }
}

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

void clear_trail(t_game *game)
{
    int x;
    int y;

    y= 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            put_pixel(x, y, 0x000000, game);
            x++;
        }
        y++;
    }
}