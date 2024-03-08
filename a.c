/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:04 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/08 10:09:15 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		;
	return (i);
}

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
	char str[] = "123";
	permute(str, 0, ft_strlen2(str) - 1);
	return (0);
}