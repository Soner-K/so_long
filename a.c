/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:55:54 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/12 17:38:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/structs.h"
#include <stdio.h>

void call_2(t_coordinates *i)
{
	i->x += 3;
	i->y += 3;

}

void	call_it(void)
{
	static t_coordinates i;

	i.x++;
	i.y++;
	printf("x=%d y=%d\n", i.x, i.y);
	call_2(&i);
}

int main(void)
{
	call_it();
	call_it();
	call_it();
}