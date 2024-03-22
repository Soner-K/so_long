/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:43:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/22 11:55:31 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs.h"

// 							--> create_map.c
/**
 * @brief Creates the map, from a .ber file, and checks its validity.
 * @param file 
 * @param i Acts as an incrementer.
 * @returns The map if the file is valid. Exits the program otherwise
 * (through the other functions).
 */
char			**create_map(char *path, int i);



// 							--> parse_map.c
/**
 * @brief Transforms a string into a map array.
 * @param path The path to the map's file.
 * @returns An array of strings (i.e. the copy of the file).
 */
char			**ber_to_map(char *path);

/**
 * @brief Checks if a file's extension is ".ber".
 * @param file The path to the file.
 * @returns void. Exits the program if the file's extension isn't ".ber".
 */
void			check_if_ber(char *file);


//								--> utils.c
/**
 * @brief Initialize the elements of a structure.
 * @param elements An adress of a structure containing the number of times
 * an element is found inside a map.
 * @returns void.
 */
void			set_elements(t_elements *elements);

/**
 * @brief Finds the initial position of the player in the map.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @returns The coordinates of the player in the map.
 */
t_coordinates	find_initial_pos(char **map);

/**
 * @brief Counts a the number of times a given element appears in the map.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @param c The element to count.
 * @returns The number of times the element appears.
 */
int				count_element(char **map, char c);

/**
 * @brief Frees the pointers to the images' files.
 * @param mlx Adress of a structure containing a pointer to the mlx's adress
 * and the window's adress.
 * @param sprites Adress of a structure containing pointers to all the images'
 * files.
 * @param bonus A boolean variable to check if the program was launched
 * with bonuses (bonus == 1) or not.
 * @returns void.
 */
void			free_imgs(t_data *mlx, t_xpm *sprites, char bonus);



void			check_for_path(char **map, char **map_cp);
void			check_assets(char bonus, int i, int f[NB_ASSETS]);
t_coordinates	screen_size(t_data *mlx, char **map);
void			set_map(t_data *mlx, char **map);
void			put_element(t_data *mlx, char *file, int x, int y);
#endif