/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:43:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/01 16:05:09 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs.h"

char	*put_to_string(char *str, char *tmp, int fd, char *path);
char	**ber_to_map(char *path);
void	check_if_ber(char *file);
char	check_one_element(char c, t_elements *elements);
char	compare_top_down(char **map);
void	check_map_elements(char **map, int i, int j);
void	set_elements(t_elements *elements);
void	free_and_quit(char *msg, char **strs);

#endif