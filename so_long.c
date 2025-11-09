/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:34:20 by dufama            #+#    #+#             */
/*   Updated: 2025/11/09 18:00:04 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(void)
{
	char	**testmap;

	testmap = read_map("map/map.ber");
	if (!testmap)
	{
		ft_printf("Error\nMap not found or invalid\n");
		return (1);
	}
	if (!is_valid_map(testmap))
		return (1);
	ft_printf("Map is valid ✅\n");
	return (0);
}
