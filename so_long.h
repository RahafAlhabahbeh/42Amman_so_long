/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-haba <ral-haba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:22:26 by ral-haba          #+#    #+#             */
/*   Updated: 2025/02/18 10:20:32 by ral-haba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "printf/ft_printf.h"

# define FACTOR 64

typedef struct s_var
{
	int		rows;
	int		cols;
	char	**map_copy;
	char	**map;
	char	*line;
	int		fd;
	int		collect;
	int		player;
	int		exit;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player;
	int		keep_exit;
	int		moves;
}	t_var;

void	is_map_rectangular(t_var *game);
void	is_valid_char(t_var *game);
void	check_char(t_var *game);
void	check_borders(t_var *game);
void	check_top_bottom_borders(t_var *game);
void	check_side_borders(t_var *game);
void	check_empty_lines(t_var *game);
void	validate_map_accessibility(t_var *game);
void	free_map(t_var *game);
void	free_map_copy(t_var *game);
void	free_exit(char *message, t_var *game);
void	free_close_exit(char *message, t_var *game, int fd);
void	close_exit(char *message, int fd);
void	read_map(char *file, t_var *game);
void	cols_rows(char *file, t_var *game);
void	init_struct(t_var *game);
void	check_extension(char *path);
void	duplicate_map(t_var *game);
void	fill_area(t_var *map, int x, int y);
void	count_char(t_var *game, int i, int j);
void	draw_map(t_var *game);
void	load_images(t_var *game);
void	initialize_game(char **av, t_var *game);
int		ft_key_hook(int key, t_var *game);
int		close_window(t_var *game);
void	ft_move_up(t_var *game, int key);
void	ft_complete_move(t_var *game, int key);
void	ft_print_movements(t_var *game);
void	ft_move_right(t_var *game, int key);
void	ft_move_left(t_var *game, int key);
void	ft_move_down(t_var *game, int key);
void	check_screen_size(t_var *game);
void	get_image_for_tile(t_var *game, char tile, void **img);
void	exit_str(void);
void	animation(t_var *game);
#endif
