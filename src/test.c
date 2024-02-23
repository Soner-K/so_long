/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/02/23 19:30:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		find_len_strs(char **strs)
{
	int	i;

	i = 0;
	if (!(*strs) || !strs)
		return (0);
	while (strs[i])
		i++;
	return (i;)
}

char	is_rectangle(char **map)
{
	t_rectangle	check;
	
	check.down = ft_strlen(map[find_len_strs(map)] - 1);
	check.top = ft_strlen(*map);
}

char	*put_to_string(char *str, char *tmp, int fd)
{
	char	first_iteration;

	first_iteration = 1;
	while (tmp || first_iteration == 1)
	{
		if (tmp)
			free(tmp);
		tmp = get_next_line(fd, 0);
		// if (!tmp)
		// 	return (get_next_line(fd, 1), free(str), print_and_exit(MKO), NULL);
		str = ft_fuse(str, tmp);
		if (!str)
		{
			close(fd);
			if (tmp)
				free(tmp);
			get_next_line(fd, 1);
			print_and_exit(MKO);
		}
		first_iteration = 0;
	}
	if (tmp)
		free(tmp);
	close(fd);
	return (str);
}

char	**ber_to_map(int fd)
{
	char	**map;
	char	*str;

	if (fd < 0)
		print_and_exit("Not valid fd");
	str = put_to_string(NULL, NULL, fd); //no protect cuz if str is null, map also, whata about empty string?
	map = ft_split(str, '\n');
	if (!map)
	{
		if (str)
			free(str);
		print_and_exit("Failed to create map's array of strings");
	}
	free(str);
	return (map);
}

int	main(int argc, char **argv)
{
	// void *t;
	// char 	*s;
	char	**map;
	int 	fd;
	int		i;
	(void)argc;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	map = ber_to_map(fd);
	i = 0;
	while (map[i])
		printf("||%s||\n", map[i++]);
	free_arrs((void **)map);	
}