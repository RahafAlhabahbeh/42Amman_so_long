/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:18:34 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/18 13:20:42 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int key, t_var *game)
{
	if (key == XK_Escape)
		close_window(game);
	if (key == XK_a || key == XK_Left)
		ft_move_left(game, key);
	if (key == XK_w || key == XK_Up)
		ft_move_up(game, key);
	if (key == XK_d || key == XK_Right)
		ft_move_right(game, key);
	if (key == XK_s || key == XK_Down)
		ft_move_down(game, key);
	return (0);
}

void	ft_move_up(t_var *game, int key)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& game->collect == 0)
		{
			game->moves++;
			ft_print_movements(game);
			ft_printf("you won!\n");
			close_window(game);
		}
		if (game->map[game->player_y - 1][game->player_x] == 'C')
			game->collect--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
			game->player_x * FACTOR, game->player_y * FACTOR);
		ft_complete_move(game, key);
	}
}

void	animation(t_var *game)
{
	if (game->collect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"textures/open_door.xpm", &game->exit_x, &game->exit_y);
	}
	if (!game->img_exit)
	{
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		close_window(game);
	}
}

void	ft_complete_move(t_var *game, int key)
{
	animation(game);
	if (game->keep_exit == 1 && game->collect >= 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			game->exit_x * FACTOR, game->exit_y * FACTOR);
		game->map[game->player_y][game->player_x] = 'E';
		game->keep_exit = 0;
	}
	if (key == XK_s || key == XK_Down)
		game->player_y++;
	else if (key == XK_a || key == XK_Left)
		game->player_x--;
	else if (key == XK_w || key == XK_Up)
		game->player_y--;
	else if (key == XK_d || key == XK_Right)
		game->player_x++;
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collect > 0)
		game->keep_exit = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->player_x * FACTOR, game->player_y * FACTOR);
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_print_movements(game);
}

void	ft_print_movements(t_var *game)
{
	char	*move;
	char	*win_move;
	char	*number;

	number = ft_itoa(game->moves);
	if (!number)
		return ;
	draw_map(game);
	move = ft_itoa(game->moves);
	win_move = ft_strjoin("movements: ", number);
	mlx_string_put(game->mlx, game->win, 12, 16, 0xFFFFFF, win_move);
	if (game->moves == 0)
	{
		free(move);
		free(number);
		free(win_move);
		return ;
	}
	ft_printf("movements %s\n", move);
	free(move);
	free(number);
	free(win_move);
}
// void	ft_print_movements(t_var *game)
// {
// 	char	*move;
// 	char	*win_move;

// 	draw_map(game);
// 	move = ft_itoa(game->moves);
// 	win_move = ft_strjoin("movements: ", ft_itoa(game->moves));
// 	mlx_string_put(game->mlx, game->win, 12, 16, 0xFFFFFF, win_move);
// 	if (game->moves == 0)
// 	{
// 		mlx_string_put(game->mlx, game->win, 12, 16, 0xFFFFFF, win_move);
// 		free(move);
// 		free(win_move);
// 		return ;
// 	}
// 	ft_printf("movements %s\n", move);
// 	free(move);
// 	free(win_move);
// 	if (game->moves == 0)
// 		return ;
// }
/*
void	ft_print_movements(t_var *game)
{
	char	*move;
	char	*win_move;
	char	*temp;

	draw_map(game);
	move = ft_itoa(game->moves);
	if (!move)
		return ;
	temp = ft_strjoin("movements: ", move);
	free(move);
	if (!temp)
		return ;
	win_move = temp;
	mlx_string_put(game->mlx, game->win, 12, 16, 0xFFFFFF, win_move);
	ft_printf("movements %s\n", move);
	free(win_move);
} */
/* void	ft_print_movements(t_var *game)
{
	char	*move;
	char	*win_move;

	draw_map(game);
	move = ft_itoa(game->moves);
	if (!move)
		return ;
	win_move = ft_strjoin("movements: ", move);
	free(move);
	if (!win_move)
		return ;
	mlx_string_put(game->mlx, game->win, 12, 16, 0xFFFFFF, win_move);
	if (game->moves == 0)
	{
		free(win_move);
		return ;
	}
	ft_printf("movements: %s\n", move);
	free(win_move);
} */
