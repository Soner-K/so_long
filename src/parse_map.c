/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:41:47 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/01 18:15:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/**
 * @brief Compares the top and the bottom of the map. If they're different,
 *  or one of them contains something else than '1', the program quits.
 * @param map An array of strings, containing each line of the .ber file
 * acting as the map.
 * @returns top_size == 0. If top_size is 0, 
 * returns 1 (top and bottom are valid). Returns 0 otherwise
 * (top and/or bottom aren´t valid).
 */
char	compare_top_down(char **map)
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
	while (map[0][++i] && map[last][++j] && map[0][i] == '1'
		&& map[last][j] == '1' && top_size > 0)
		top_size--;
	return (top_size == 0);
}

char	compare_sides(char **map)
{
	int	top_size;
	int	bottom_size;
	int	len_strs;
	
	len_strs = find_len_strs(map); //no need to check for 0 cuz ber_to_map handles it.
	top_size = ft_strlen(*map);
	bottom_size = ft_strlen(map[len_strs - 1]);
	while (len_strs--)
	{
		
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
char	check_one_element(char c, t_elements *elements)
{
	if (c == '1')
		return (elements->wall++, 1);
	if (c == '0')
		return (elements->empty++, 1);
	if (c == 'E')
	{
		elements->exit++;
		if (elements->exit > 1)
			return (TOO_MANY_EXIT);
		return (1);
	}
	if (c == 'C')
		return (elements->collectible++, 1);
	if (c == 'P')
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
void	check_map_elements(char **map, int i, int j)
{
	t_elements	elements;
	char		check;

	set_elements(&elements);
	while (map[++i])
	{
		while (map[i][++j])
		{
			check = check_one_element(map[i][j], &elements);
			if (check == 0)
				free_and_quit("Unrecognized element in map", map); // free
			if (check == TOO_MANY_EXIT)
				free_and_quit("More than one exit found", map); // free
			if (check == TOO_MANY_POS)
				free_and_quit("More than one initial position found", map); // free
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
