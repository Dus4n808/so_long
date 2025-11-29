/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:43:21 by dufama            #+#    #+#             */
/*   Updated: 2025/11/29 15:07:30 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (0);
	return (ft_strncmp(dot, ".ber", 5) == 0);
}

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

static char	**fill_map(int fd, int lines)
{
	char	**map;
	char	*tmp;
	int		i;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		tmp = get_next_line(fd);
		map[i] = ft_strtrim(tmp, "\n");
		free(tmp);
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
	close(fd);
	return (map);
}

char	**read_and_stock_map(char *filename)
{
	char	**map;

	if (!check_extension(filename))
	{
		ft_putstr_fd("Erreur de format\n", 2);
		exit (1);
	}
	map = read_map(filename);
	if (!map)
		error_msg_and_free("Erreur lors du chargement de la map\n", map);
	return (map);
}
