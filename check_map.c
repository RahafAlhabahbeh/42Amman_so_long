/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:26:19 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/17 14:38:49 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_rectangular(t_var *game)
{
	int	i;

	i = 0;
	if (!game->map[0][0] || game->map[0][0] == '\n')
		free_exit("ERROR\nmap is not correct\n", game);
	while (i < game->rows)
	{
		if ((int)ft_strlen(game->map[i]) != game->cols)
			free_exit("Error\nMap is not rectangular.\n", game);
		i++;
	}
}

void	is_valid_char(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != '\n')
				free_exit("Error\nInvalid character in map.\n", game);
			j++;
		}
		i++;
	}
}

void	check_char(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != '\n')
				free_exit("Error\nInvalid char\n", game);
			count_char(game, i, j);
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->exit != 1 || game->collect < 1)
		free_exit("Error\nwith char\n", game);
}

void	validate_map_accessibility(t_var *game)
{
	int	i;
	int	j;

	duplicate_map(game);
	fill_area(game, game->player_x, game->player_y);
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map_copy[i][j] == 'C' || game->map_copy[i][j] == 'E')
			{
				free_map_copy(game);
				free_exit("Error\nUnreachable collectibles or exit.\n", game);
			}
			j++;
		}
		i++;
	}
	free_map_copy(game);
}
