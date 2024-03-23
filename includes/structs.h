/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:37:22 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/23 12:54:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// structure that acts as a counter for each element in the map
typedef struct s_elements
{
	int		wall;
	int		empty;
	int		collectible;
	int		exit;
	int		pos;
}			t_elements;

typedef struct s_coordinates
{
	int x; // line (row)
	int y; // character (col)
}			t_coordinates;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		collectibles;
}			t_data;

typedef struct s_xpm
{
	void	*face_u;
	void	*face_r;
	void	*face_d;
	void	*face_l;
	void	*wall;
	void	*card;
	void	*heli;
	void	*ground;
	void	*vest;
}			t_xpm;

#endif