/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:43:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/20 15:46:50 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs.h"

char			*put_to_string(char *str, char *tmp, int fd, char *path);
char			**ber_to_map(char *path);
void			check_if_ber(char *file);
char			check_one_element(char c, t_elements *elements);
void			compare_top_down(char **map);
void			check_map_elements(char **map, int i, int j);
void			set_elements(t_elements *elements);
void			free_imgs(t_data *mlx, t_xpm *sprites);
void			compare_sides(char **map);
char			**create_map(char *path, int i);
t_coordinates	find_initial_pos(char **map);
int				count_element(char **map, char c);
// void			flood_fill(char **map_cp, int x, int y);
void			check_for_path(char **map, char **map_cp);
char			check_assets(char **assets);
void			set_map(t_data *mlx, char **map);
void			put_element(t_data *mlx, char *file, int x, int y);
t_coordinates	screen_size(char **map);
#endif