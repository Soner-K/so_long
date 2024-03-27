/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:43:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/27 11:22:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs.h"

// 								--> create_map.c

/**
 * @brief Creates the map, from a .ber file, then calls itself again to create
 * a copy of the map, to check for a valid path.
 * @param path Path to the map's file.
 * @param i Acts as a binary (in first call, i is 0, in the second i is  1).
 * @returns The map if the file is valid. Exits the program otherwise.
 */
char			**create_map(char *path, char i);

//								--> events.c

/**
 * @brief
 * @param
 * @returns
 */
int				player_movement(int keyhook, t_data *mlx);

//								--> flood_fill.c

/**
 * @brief Checks if it is possible to reach all collectibles
 * and the exit in a map.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @param map_cp A copy of map.
 * @returns void. Exits the program and frees map and map_cp if a valid
 * path doesn't exist.
 */
void			check_for_path(char **map, char **map_cp);

// 								--> parse_map.c

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

//								--> set_map.c

/**
 * @brief Prints the map to the screen.
 * @param mlx Adress of a structure containing a pointer to the mlx's adress
 * and the window's adress.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @returns void.
 */
void			set_map(t_data *mlx, char **map);

/**
 * @brief Puts one element to the window.
 * @param data Adress of a structure containing a pointer to the mlx's adress,
 * the window's adress, the map array and the number of collectibles.
 * @param file The xpm file corresponding to the character of the map.
 * @param x Position in the row.
 * @param y Position in the column.
 * @returns void.
 */
void			put_element(t_data *mlx, char *file, int x, int y);

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
 * @param c The character to look for.
 * @returns The coordinates of the player in the map.
 */
t_coordinates	find_pos(char **map, char c);

/**
 * @brief Counts the number of times a given element appears in the map.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @param c The element to count.
 * @returns The number of times the element appears.
 */
int				count_element(char **map, char c);

/**
 * @brief Frees mlx, window and images.
 * @param data Adress of a structure containing a pointer to the mlx's adress,
 * the window's adress, the map array and the number of collectibles.
 * @param sprites Adress of a structure containing pointers to all the images'
 * files.
 * @returns void.
 */
void			free_mlx(t_data *data, t_xpm *sprites);

/**
 * @brief Checks if all the xpm files needed for the game exist
 * and can be opened.
 * @param i Acts as an incrementer.
 * @param f An array of size NB_ASSETS to store all the fd of the opened files.
 * @returns void. Exits the program if at least one file can't be opened.
 */
void			check_assets(int i, int f[NB_ASSETS]);

//								--> utils2.c

/**
 * @brief Returns the screen size needed to represent a given map,
 * while checking if the map isn'too big for the screen's size.
 * @param data Adress of a structure containing a pointer to the mlx's adress,
 * the window's adress, the map array and the number of collectibles.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @returns The length and width needed to represent the map in the screen.
 * Exits the program if the map is too big for the screen.
 */
t_coordinates	screen_size(t_data *data, char **map);

int				player_movement(int key, t_data *data);

/**
 * @brief Quits the game and frees all allocated memory.
 * @param data Adress of a structure containing a pointer to the mlx's adress,
 * the window's adress, the map array and the number of collectibles..
 * @returns void.
 */
int				end_game(t_data *data);

int				close_game(t_data *data);
#endif