/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:36:59 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/21 15:24:21 by sokaraku         ###   ########.fr       */
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
# define ASSETS "Error\n"
#endif

// #ifndef NB_ASSETS
// # define NB_ASSETS 0
// #endif

# define NB_ASSETS 9
# define TRUE 1
# define FALSE 0
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define MKO "Allocation issue"
# define TOO_MANY_EXIT -1
# define TOO_MANY_POS -2
# define FACE_U "assets/xpm/face_up.xpm"
# define FACE_R "assets/xpm/face_right.xpm"
# define FACE_D "assets/xpm/face_down.xpm"
# define FACE_L "assets/xpm/face_left.xpm"
# define CARD "assets/xpm/card.xpm"
# define GROUND "assets/xpm/ground.xpm"
# define HELICOPTER "assets/xpm/helicopter.xpm"
# define TRASH_BIN	"assets/xpm/trash_bin.xpm"
# define YELLOW_VEST "assets/xpm/yellow_vest.xpm"
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

#endif