/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:36:59 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/27 18:06:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef LENGTH
#  define LENGTH 1000
# endif

# ifndef ASSETS
#  define ASSETS "Error\n"
# endif

# ifndef BONUS
#  define BONUS -1
# endif

// #ifndef NB_ASSETS
// # define NB_ASSETS 0
// #endif

# define NB_ASSETS 9
# define TRUE 1
# define FALSE 0
# define LEFT 1
# define UP_DOWN 1
# define LEFT_RIGHT 2
# define RIGHT 3
# define DOWN 4
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define ENEMY 'V'
# define MKO "Allocation issue"
# define TOO_MANY_EXIT -1
# define TOO_MANY_POS -2
# define PLAYER_U "assets/xpm/player_up.xpm"
# define PLAYER_R "assets/xpm/player_right.xpm"
# define PLAYER_D "assets/xpm/player_down.xpm"
# define PLAYER_L "assets/xpm/player_left.xpm"
# define CARD "assets/xpm/card.xpm"
# define GROUND "assets/xpm/ground.xpm"
# define HELICOPTER "assets/xpm/helicopter.xpm"
# define TRASH_BIN "assets/xpm/trash_bin.xpm"
# define YELLOW_VEST "assets/xpm/yellow_vest.xpm"
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define END_GAME -1
#endif