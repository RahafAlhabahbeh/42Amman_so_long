/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:19:15 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/17 14:37:08 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_top_bottom_borders(t_var *game)
{
	int	j;

	j = 0;
	while (j < game->cols - 1)
	{
		if (game->map[0][j] != '1' || game->map[game->rows - 1][j] != '1')
			free_exit("Error\nMap borders must be enclosed by walls.\n", game);
		j++;
	}
}

void	check_side_borders(t_var *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 2] != '1')
			free_exit("Error\nMap borders must be enclosed by walls.\n", game);
		i++;
	}
}

void	check_empty_lines(t_var *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (ft_strlen(game->map[i]) == 0)
			free_exit("Error\nMap contains an empty line.\n", game);
		i++;
	}
}

void	check_borders(t_var *game)
{
	check_top_bottom_borders(game);
	check_side_borders(game);
	check_empty_lines(game);
}
