/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:39:14 by sokaraku          #+#    #+#             */
/*   Updated: 2024/03/23 12:46:34 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Checks for a line containing only a line return in the file's map.
 * Iterates through str, and checks if a '\n' is followed by another one.
 * @param str The map put to a string.
 * @returns void. Exits the program if two '\n' breaks in succession.
 */
static void	check_empty(char *str)
{
	int	i;

	i = -1;
	if (!str)
		print_and_exit("Empty file");
	while (str[++i])
	{
		if (str[i] == '\n' && i != 0 && str[i - 1] == '\n')
		{
			free(str);
			print_and_exit("Empty space in file.");
		}
	}
}

/**
 * @brief Puts the content of a file inside a string.
 * @param str The returned string.
 * @param tmp Temporary string, where one line of the file is stored.
 * @param fd The map's file descriptor.
 * @param path The path to the map's file.
 * @returns The fused string, containing all the map.
 */
static char	*put_to_string(char *str, char *tmp, int fd, char *path)
{
	int	line_count;

	line_count = count_lines_fd(path);
	while (line_count--)
	{
		if (tmp)
			free(tmp);
		tmp = get_next_line(fd, 0);
		if (!tmp && line_count != 0)
			return (get_next_line(fd, 1), close(fd), free(str),
				print_and_exit(MKO), NULL);
		str = ft_fuse(str, tmp);
		if (!str)
		{
			if (tmp)
				free(tmp);
			get_next_line(fd, 1);
			close(fd);
			print_and_exit(MKO);
		}
	}
	if (tmp)
		free(tmp);
	get_next_line(fd, 1);
	return (close(fd), str);
}

char	**ber_to_map(char *path)
{
	char	**map;
	char	*str;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_and_exit("Not valid fd");
	str = put_to_string(NULL, NULL, fd, path);
	close(fd);
	check_empty(str);
	map = ft_split(str, '\n');
	if (!map)
	{
		if (str)
			free(str);
		print_and_exit("Failed to create map's array of strings");
	}
	if (find_len_strs(map) < 3)
	{
		free(str);
		free_and_quit("Map too small", map);
	}
	free(str);
	return (map);
}

void	check_if_ber(char *file)
{
	int	i;

	if (!file || !file[0])
		print_and_exit("No file found");
	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (!file[i])
		print_and_exit("No file extension");
	if (ft_strncmp(&file[i], ".ber", 4) == 0 && ft_strlen(&file[i]) == 4)
		return ;
	else
		print_and_exit("Invalid file extension");
}
