/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:36:31 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/18 10:57:53 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_char(t_var *game, int i, int j)
{
	if (game->map[i][j] == 'C')
		game->collect++;
	if (game->map[i][j] == 'P')
	{
		game->player++;
		game->player_x = j;
		game->player_y = i;
	}
	if (game->map[i][j] == 'E')
	{
		game->exit++;
		game->exit_x = j;
		game->exit_y = i;
	}
}

void	fill_area(t_var *map, int x, int y)
{
	if (x < 0 || y < 0
		|| map->map_copy[y][x] == '1' || map->map_copy[y][x] == 'F')
		return ;
	map->map_copy[y][x] = 'F';
	fill_area(map, x + 1, y);
	fill_area(map, x - 1, y);
	fill_area(map, x, y + 1);
	fill_area(map, x, y - 1);
}

void	duplicate_map(t_var *game)
{
	int		i;

	game->map_copy = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map_copy)
		free_exit("Error\nMemory allocation failed.\n", game);
	i = 0;
	while (i < game->rows)
	{
		if (!game->map[i])
			free_exit("Error\nNull row in map.\n", game);
		game->map_copy[i] = ft_strdup(game->map[i]);
		if (!game->map_copy[i])
		{
			free_map_copy(game);
			free_exit("Error\nMemory allocation failed.\n", game);
		}
		i++;
	}
	game->map_copy[i] = NULL;
}

void	exit_str(void)
{
	ft_putstr_fd("Error\nYou have assign two argument\n", 2);
	exit(1);
}
