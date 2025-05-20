/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:14:29 by ialashqa          #+#    #+#             */
/*   Updated: 2025/05/20 18:05:07 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(void)
{
    t_game  game;

    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
    mlx_hook(game.win, 17, 1L << 17, close_window, &game); // close window
    
    mlx_loop_hook(game.mlx, draw_loop, &game);

    mlx_loop(game.mlx);

    return 0;
}
