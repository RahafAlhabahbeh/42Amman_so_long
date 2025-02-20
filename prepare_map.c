/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:14:41 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/18 10:57:05 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("ERROR\nInvalid extension\n", 2);
		exit(1);
	}
}

void	init_struct(t_var *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->rows = 0;
	game->cols = 0;
	game->fd = -1;
	game->collect = 0;
	game->player = 0;
	game->exit = 0;
	game->player_x = -1;
	game->player_y = -1;
	game->exit_x = -1;
	game->exit_y = -1;
	game->line = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->img_player = NULL;
	game->keep_exit = 0;
	game->moves = 0;
}

void	cols_rows(char *file, t_var *game)
{
	char	*line;
	int		i;

	i = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		close_exit("ERROR\nfile not open\n", game->fd);
	line = get_next_line(game->fd);
	if (!line)
		close_exit("ERROR\nempty map!\n", game->fd);
	game->cols = (int)ft_strlen(line);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->rows = i;
	close(game->fd);
}

void	read_map(char *file, t_var *game)
{
	char	*line;
	int		i;

	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		exit(1);
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
		free_exit("Error\ncann't open the file\n", game);
	i = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		game->map[i] = line;
		i++;
		line = get_next_line(game->fd);
	}
	game->map[i] = NULL;
	close(game->fd);
}

void	initialize_game(char **av, t_var *game)
{
	check_extension(av[1]);
	init_struct(game);
	cols_rows(av[1], game);
	read_map(av[1], game);
	is_map_rectangular(game);
	is_valid_char(game);
	check_borders(game);
	check_char(game);
	validate_map_accessibility(game);
}
