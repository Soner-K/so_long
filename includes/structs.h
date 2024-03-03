/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:37:22 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/03 23:07:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// structure that acts as a counter for each element in the map
typedef struct s_elements
{
	int	wall;
	int	empty;
	int	collectible;
	int	exit;
	int	pos;
}		t_elements;

typedef struct s_coordinates
{
	int	x;
	int	y;
}		t_coordinates;

#endif