/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:42:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/03 23:04:13 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize the elements of a structure.
 * @param elements An adress of a structure containing the number of times
 * an element is found inside a map.
 * @returns void.
 */
void	set_elements(t_elements *elements)
{
	elements->empty = 0;
	elements->wall = 0;
	elements->collectible = 0;
	elements->pos = 0;
	elements->exit = 0;
}

/**
 * @brief Prints a message to STD_ERROR, frees an array of string
 * and then exit the program.
 * @param msg The message to print.
 * @param strs An array of strings.
 * @returns void.
 */
void	free_and_quit(char *msg, char **strs)
{
	free_arrs((void **)strs);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
