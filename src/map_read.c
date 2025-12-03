/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:43:21 by dufama            #+#    #+#             */
/*   Updated: 2025/12/03 12:07:47 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	count_line(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	*fill_line(int fd, char **map, int i)
{
	char	*tmp;
	char	*line;

	tmp = get_next_line(fd);
	if (!tmp)
	{
		map[i] = NULL;
		free_map(map);
		return (NULL);
	}
	line = ft_strtrim(tmp, "\n");
	free(tmp);
	if (!line)
	{
		map[i] = NULL;
		free_map(map);
	}
	return (line);
}

static char	**fill_map(int fd, int lines)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = fill_line(fd, map, i);
		if (!map[i])
			return (NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static char	**read_map(char *file)
{
	int		fd;
	int		lines;
	char	**map;

	lines = count_line(file);
	if (lines <= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = fill_map(fd, lines);
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}

char	**read_and_stock_map(char *filename)
{
	char	**map;

	if (!check_extension(filename))
	{
		ft_putstr_fd("Error format (.ber)\n", 2);
		exit (1);
	}
	map = read_map(filename);
	if (!map)
	{
		ft_putstr_fd("Error load map\n", 2);
		exit(1);
	}
	return (map);
}
