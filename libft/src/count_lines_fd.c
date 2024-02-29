/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:31:07 by sokaraku          #+#    #+#             */
/*   Updated: 2024/02/29 16:07:13 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	count_lines_fd(int fd, char *path)
{
	int	i;
	int	tmp_fd;

	i = 0;
	if (path)
	{
		tmp_fd = open(path, O_RDONLY);
		if (tmp_fd == -1)
			return (-1);
		while (get_next_line(tmp_fd, 0))
			i++;
		get_next_line(tmp_fd, 1);
		close(tmp_fd);
		return (i);
	}
	while (get_next_line(fd, 0))
		i++;
	get_next_line(fd, 1);
	close(fd);
	return (i);
}
