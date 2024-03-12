/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:36:59 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/12 17:33:08 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef XPM_FILES
#  define XPM_FILES "ouat"
# endif

# ifndef NB_SPRITES
#  define NB_SPRITES 0
# endif

// typedef enum
// {
// 	FACE_U,
// 	CARD,
// 	FACE_D,
// 	FACE_L,
// 	FACE_R,
// 	GROUND,
// 	HELICOPTER,
// 	WALL_SIDES,
// 	WALL_UP_DOWN,
// 	YELLOW_VEST
// }	t_files

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
# define WALL_SIDES "assets/xpm/spikes_sides.xpm"
# define WALL_UP_DOWN "assets/xpm/spikdes_up_down.xpm"
# define YELLOW_VEST "assets/xpm/yellow_vest.xpm"

#endif