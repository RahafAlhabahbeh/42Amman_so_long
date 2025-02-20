/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:23:43 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/17 14:38:58 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_var *game)
{
	if (game->map)
		free_map(game);
	if (game->line)
		free(game->line);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
	return (0);
}

void	check_screen_size(t_var *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(game->mlx, &height, &width);
	if ((game->cols - 1) * FACTOR > height || game->rows * FACTOR > width)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_exit("ERROR\nthe map is too big\n", game);
	}
}
