/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:40:03 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/17 14:31:56 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_var *game)
{
	int	img_width;
	int	img_height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&img_width, &img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&img_width, &img_height);
	if (!game->img_wall || !game->img_floor || !game->img_collectible
		|| !game->img_exit || !game->img_player)
	{
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		close_window(game);
	}
}

void	get_image_for_tile(t_var *game, char tile, void **img)
{
	if (tile == '1')
		*img = game->img_wall;
	else if (tile == '0')
		*img = game->img_floor;
	else if (tile == 'C')
		*img = game->img_collectible;
	else if (tile == 'E')
		*img = game->img_exit;
	else if (tile == 'P')
		*img = game->img_player;
}

void	draw_map(t_var *game)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			get_image_for_tile(game,
				game->map[i][j], &img);
			mlx_put_image_to_window(game->mlx, game->win,
				img, j * FACTOR, i * FACTOR);
			j++;
		}
		i++;
	}
}
