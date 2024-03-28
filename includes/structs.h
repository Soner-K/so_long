/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:37:22 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/28 12:08:15 by sokaraku         ###   ########.fr       */
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
	int		ennemy;
}			t_elements;

typedef struct s_coordinates
{
	int		x;
	int		y;
}			t_coordinates;

typedef struct s_xpm
{
	void	*player_u;
	void	*player_r;
	void	*player_d;
	void	*player_l;
	void	*wall;
	void	*card;
	void	*heli;
	void	*ground;
	void	*vest;
}			t_xpm;

typedef struct s_cross
{
	char	up;
	char	right;
	char	down;
	char	left;
}			t_cross;

typedef struct s_enemies
{
	int		x;
	int		y;
	int		x_prev;
	int		y_prev;
	char	up;
	char	right;
	char	down;
	char	left;
	// t_cross	*moves;	
}				t_enemies;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		collectibles;
	int		x;
	int		y;
	t_xpm	*xpm;
}			t_data;
#endif