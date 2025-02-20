/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:26:06 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/17 14:39:30 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_var	game;

	if (ac != 2)
		exit_str();
	initialize_game(av, &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		free_exit("Error\nMiniLibX initialization failed\n", &game);
	check_screen_size(&game);
	game.win = mlx_new_window(game.mlx, (game.cols - 1) * FACTOR,
			game.rows * FACTOR, "So Long");
	if (!game.win)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free_exit("Error\nFailed to create window\n", &game);
	}
	load_images(&game);
	draw_map(&game);
	game.moves = 0;
	ft_print_movements(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
