/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:14:29 by ialashqa          #+#    #+#             */
/*   Updated: 2025/05/19 16:45:38 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	close_window(t_game *game) // close window
// {
// 	mlx_destroy_image(game->mlx, game->img);
// 	mlx_destroy_window(game->mlx, game->win);
// 	exit(EXIT_SUCCESS);
// }

void put_pixel(int x, int y, int color, t_game *game)
{
    int index;

    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
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

char **get_map(void)
{
    char **map;
    
    map = malloc(sizeof(char *) * 13);
    map[0] = "111111111111111111";
    map[1] = "100010000000000001";
    map[2] = "100010000000010001";
    map[3] = "100000000000000001";
    map[4] = "100000001110000001";
    map[5] = "100000001110000001";
    map[6] = "100000001110000001";
    map[7] = "100000100000100001";
    map[8] = "101000000000000101";
    map[9] = "100000100000100001";
    map[10] = "100000000000000001";
    map[11] = "111111111111111111";
    map[12] = NULL;
    return (map);
}

void init_game(t_game *game)
{
    init_player(&game->player);
    game->map = get_map();
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Halo Infinite");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

bool sensor(float px, float py, t_game *game)
{
    int x;
    int y;

    x = px / WALL;
    y = py / WALL;
    if(game->map[y][x] == '1')
        return (true);
    return (false);
}

void draw_lines(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle;
    float sin_angle;
    float ray_x;
    float ray_y;
    (void)i;
    
    cos_angle = cos(start_x);
    sin_angle = sin(start_x);
    ray_x = player->x;
    ray_y = player->y;
    while(!sensor(ray_x, ray_y, game))
    {
        put_pixel(ray_x, ray_y, 0xFF0000, game);
        ray_x += cos_angle;
        ray_y += sin_angle;
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
    draw_square(player->x, player->y, 10, 0x00FF00, game);
    draw_map(game);
    
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

int main(void)
{
    t_game  game;

    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
    // mlx_hook(game.win, 17, 1L << 17, close_window, &game.player); // close windw
    
    mlx_loop_hook(game.mlx, draw_loop, &game);

    mlx_loop(game.mlx);

    return 0;
}
