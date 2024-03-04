/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:37:22 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/04 15:07:12 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// structure that acts as a counter for each element in the map
typedef struct s_elements
{
	int				wall;
	int				empty;
	int				collectible;
	int				exit;
	int				pos;
}					t_elements;

typedef struct s_coordinates
{
	int x; // line (row)
	int y; // character (col)
	char			error;
}					t_coordinates;

// typedef struct s_cross
// {
// 	t_coordinates	left;
// 	t_coordinates	right;
// 	t_coordinates	up;
// 	t_coordinates	down;
// }			t_cross;

#endif