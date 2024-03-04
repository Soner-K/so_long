/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:04 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/04 15:54:14 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	back_track(int tab[], int size)
{
	if (size < 1)
		return ;
	printf("%d ", tab[0]);
	back_track(tab + 1, size - 1);
}

int main(void)
{
	int tab[] = {1, 2, 3, 4 , 5, 6, 7};
	back_track(tab, 7);
}