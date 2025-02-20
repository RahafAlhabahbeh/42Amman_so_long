/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:24 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/16 10:35:31 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_down(t_var *game, int key)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& game->collect == 0)
		{
			game->moves++;
			ft_print_movements(game);
			ft_printf("you won!\n");
			close_window(game);
		}
		if (game->map[game->player_y + 1][game->player_x] == 'C')
			game->collect--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->player_x * FACTOR, game->player_y * FACTOR);
		ft_complete_move(game, key);
	}
}

void	ft_move_left(t_var *game, int key)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& game->collect == 0)
		{
			game->moves++;
			ft_print_movements(game);
			ft_printf("you won!\n");
			close_window(game);
		}
		if (game->map[game->player_y][game->player_x - 1] == 'C')
			game->collect--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->player_x * FACTOR, game->player_y * FACTOR);
		ft_complete_move(game, key);
	}
}

void	ft_move_right(t_var *game, int key)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& game->collect == 0)
		{
			game->moves++;
			ft_print_movements(game);
			ft_printf("you won!\n");
			close_window(game);
		}
		if (game->map[game->player_y][game->player_x + 1] == 'C')
			game->collect--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->player_x * FACTOR, game->player_y * FACTOR);
		ft_complete_move(game, key);
	}
}
