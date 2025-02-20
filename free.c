/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:34:46 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/16 10:30:15 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_var *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_map_copy(t_var *game)
{
	int	i;

	if (!game->map_copy)
		return ;
	i = 0;
	while (game->map_copy[i])
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
}

void	free_exit(char *message, t_var *game)
{
	ft_putstr_fd(message, 2);
	free_map(game);
	exit(1);
}

void	free_close_exit(char *message, t_var *game, int fd)
{
	ft_putstr_fd(message, 2);
	free(game);
	close(fd);
	exit(1);
}

void	close_exit(char *message, int fd)
{
	ft_putstr_fd(message, 2);
	close(fd);
	exit(1);
}
