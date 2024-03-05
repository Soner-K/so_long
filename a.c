/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:04 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/05 17:23:27 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>

// Function to swap values at two pointers
void	ft_swap(char *x, char *y)
{
	char	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

// Recursive function to generate permutations using backtracking
void	permute(char *a, int l, int r)
{
	if (l == r)
		printf("%s\n", a);
	else
		for (int i = l; i <= r; i++)
		{
			ft_swap((a + l), (a + i));
			permute(a, l + 1, r);
			ft_swap((a + l), (a + i)); // backtrack
		}
}

// Driver program to test the above functions
int	main(void)
{
	char str[] = "1234";
	permute(str, 0, ft_strlen(str) - 1);
	return (0);
}