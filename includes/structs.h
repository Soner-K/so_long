/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:37:22 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/01 14:12:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_rectangle
{
	int	top;
	int	left;
	int	down;
	int	right;
	int	last;
}		t_rectangle;

typedef struct s_elements
	// structure that acts as a counter for each element in the map
{
	int wall;
	int empty;
	int collectible;
	int exit;
	int pos;
}		t_elements;

#endif