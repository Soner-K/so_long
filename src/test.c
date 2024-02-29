/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/02/29 16:02:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int		find_len_strs(char **strs)
// {
// 	int	i;

// 	i = 0;
// 	if (!(*strs) || !strs)
// 		return (0);
// 	while (strs[i])
// 		i++;
// 	return (i);
// }

// char	compare_top_down(char **map, int i, int j)
// {
// 	int	last;
// 	int	top_size;

// 	last = find_len_strs(map) - 1;
// 	if (last == -1)
// 		exit(EXIT_FAILURE); // faire fct erreur
// 	top_size = ft_strlen(*map);
// 	while (map[0][++i] && map[last][++j] && map[0][i] == '1'
// 		&& map[last][j] == '1' && top_size > 0)
// 		top_size--;
// 	return (top_size == 0);
// }

char	compare_top_down(char **map, int i, int j)
{
	int	last;
	int	top_size;
	
	last = find_len_strs(map) - 1;
	if (last == -1) 
		exit(EXIT_FAILURE); //faire fct erreur
	top_size = ft_strlen(*map);
	if (top_size != ft_strlen(map[last]))
	{
		ft_putstr_fd("sdlksd\n", 2);
		exit(EXIT_FAILURE); //faire fct erreur
	}
	while (map[0][++i] && map[last][++j] && map[0][i] == '1' && map[last][j] == '1' && top_size > 0)
		top_size--;
	return (top_size == 0);
}

// char	is_rectangle(char **map)
// {
// 	t_rectangle	check;
	
// 	check.down = ft_strlen(map[find_len_strs(map)] - 1);
// 	check.top = ft_strlen(*map);
// }

//faire premier gnl pour taille de fichier pus deuxieme pour stocker

// char	*put_to_string(char *str, char *tmp, int fd)
// {
// 	char	first_iteration;

// 	first_iteration = 1;
// 	while (tmp || first_iteration == 1)
// 	{
// 		if (tmp)
// 			free(tmp);
// 		tmp = get_next_line(fd, 0);
// 		// if (!tmp )
// 		// 	return (get_next_line(fd, 1), free(str), print_and_exit(MKO), NULL);
// 		str = ft_fuse(str, tmp);
// 		if (!str)
// 		{
// 			close(fd);
// 			if (tmp)
// 				free(tmp);
// 			get_next_line(fd, 1);
// 			print_and_exit(MKO);
// 		}
// 		first_iteration = 0;
// 	}
// 	if (tmp)
// 		free(tmp);
// 	return (close(fd), str);
// }

char	*put_to_string(char *str, char *tmp, int fd, char *path)
{
	int	line_count;

	line_count = count_lines_fd(fd, path);
	while (line_count--)
	{
		if (tmp)
			free(tmp);
		tmp = get_next_line(fd, 0);
		// printf("line = %s, line_count = %d", tmp, line_count);
		if (!tmp && line_count != 0)
			return (get_next_line(fd, 1), free(str), print_and_exit(MKO), NULL);
		str = ft_fuse(str, tmp);
		if (!str)
		{
			close(fd);
			if (tmp)
				free(tmp);
			get_next_line(fd, 1);
			print_and_exit(MKO);
		}
	}
	if (tmp)
		free(tmp);
	return (close(fd), str);
}

char	**ber_to_map(char *path)
{
	char	**map;
	char	*str;
	int		fd;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		print_and_exit("Not valid fd");
	str = put_to_string(NULL, NULL, fd, path); //no protect cuz if str is null, map also, whata about empty string?
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
	// int 	fd;
	int		i;
	(void)argc;

	// fd = open(argv[1], O_RDONLY);
	// if (fd == -1)
	// 	exit(EXIT_FAILURE);
	map = ber_to_map(argv[1]);
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	// printf("\n%d\n", compare_top_down(map, -1, -1));
	// printf("map is %s\n", *map);
	free_arrs((void **)map);	
}