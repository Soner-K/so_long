/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:41:47 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/22 11:37:39 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Compares the top and the bottom of the map. If they're different,
 *  or one of them contains something else than WALL, the program quits.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @returns top_size == 0. If top_size is 0,
 * returns 1 (top and bottom are valid). Returns 0 otherwise
 * (top and/or bottom aren´t valid).
 */

static void	compare_top_down(char **map)
{
	int	last;
	int	top_size;
	int	i;
	int	j;

	i = -1;
	j = -1;
	last = find_len_strs(map) - 1;
	if (last == -1)
		free_and_quit("Empty map", map);
	top_size = ft_strlen(*map);
	if (top_size != ft_strlen(map[last]))
		free_and_quit("Uneven top and bottom sides", map);
	while (map[0][++i] && map[last][++j] && map[0][i] == WALL
		&& map[last][j] == WALL && top_size > 0)
		top_size--;
	if (top_size == 0)
		return ;
	free_and_quit("Issue with top and/or bottom of the map", map);
}
/**
 * @brief Checks if the sides of the map are even, and closed by walls.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @returns void. Exits the program if maps' sides aren't event or not closed
 * by walls, freeing map.
 */
static void	compare_sides(char **map)
{
	int	len_strs;
	int	len;
	int	i;

	len_strs = find_len_strs(map);
	i = 0;
	len = ft_strlen(map[0]);
	if (len < 3)
		free_and_quit("Map not long enough", map);
	while (len_strs--)
	{
		if (!(map[i][0] && map[i][0] == WALL && map[i][len - 1] && map[i][len
				- 1] == WALL))
			free_and_quit("Map not closed by walls", map);
		i++;
		if (map[i] && ft_strlen(map[i]) != len)
			free_and_quit("Uneven sides", map);
	}
}

/**
 * @brief Checks one element's validity in the map.
 * @param c The element to check.
 * @param elements An adress of a structure containing the number of times
 * an element is found inside a map.
 * @returns 1 if the element is valid, 0 if it is not. If there is more than
 * one exit or initial position, -1 or -2 is returned.
 */
static char	check_one_element(char c, t_elements *elements)
{
	if (c == WALL)
		return (elements->wall++, 1);
	if (c == EMPTY)
		return (elements->empty++, 1);
	if (c == EXIT)
	{
		elements->exit++;
		if (elements->exit > 1)
			return (TOO_MANY_EXIT);
		return (1);
	}
	if (c == COLLECTIBLE)
		return (elements->collectible++, 1);
	if (c == PLAYER)
	{
		elements->pos++;
		if (elements->pos > 1)
			return (TOO_MANY_POS);
		return (1);
	}
	return (0);
}

/**
 * @brief Check each element's validity inside the map.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @param i Acts as an incrementer for a string in the array of strings.
 * @param j Acts as an incrementer for a character in a given string.
 * @returns void. If an error in the map is found,
 * the function frees map and then exits the program.
 */
static void	check_map_elements(char **map, int i, int j, char check)
{
	t_elements	elements;

	set_elements(&elements);
	while (map[++i])
	{
		while (map[i][++j])
		{
			check = check_one_element(map[i][j], &elements);
			if (check == 0)
				free_and_quit("Unrecognized element in map", map);
			if (check == TOO_MANY_EXIT)
				free_and_quit("More than one exit found", map);
			if (check == TOO_MANY_POS)
				free_and_quit("More than one initial position found", map);
			if (!ft_strlen(map[i]))
				free_and_quit("Empty space in map", map);
		}
		j = 0;
	}
	if (elements.collectible < 1)
		free_and_quit("Not enough collectibles", map);
	if (elements.pos == 0)
		free_and_quit("Initial position not found", map);
	if (elements.exit == 0)
		free_and_quit("Exit not found", map);
}

char	**create_map(char *file, int i)
{
	char	**map;
	char	**map_cp;

	check_if_ber(file);
	map = ber_to_map(file);
	if (!map && i == 0)
		print_and_exit(MKO);
	else if (!map && i == 1)
		return (NULL);
	map_cp = NULL;
	compare_top_down(map);
	compare_sides(map);
	check_map_elements(map, -1, -1, 0);
	if (i == 1)
		return (map);
	if (i == 0)
	{
		map_cp = create_map(file, 1);
		if (!map_cp)
			return (free_arrs((void **)map), NULL);
	}
	check_for_path(map, map_cp);
	return (map);
}
