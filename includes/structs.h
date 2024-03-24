/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:37:22 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/24 18:51:52 by sokaraku         ###   ########.fr       */
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
	int	x;
	int	y;
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