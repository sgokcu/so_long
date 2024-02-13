/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:08 by sgokcu            #+#    #+#             */
/*   Updated: 2024/02/12 19:07:13 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_solong *map)
{
	int	i;

	i = 0;
	while (i <= map->mapy)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	freemapcpy(t_solong *map)
{
	int	i;

	i = 0;
	while (i <= map->mapy)
	{
		free(map->mapcopy[i]);
		i++;
	}
	free(map->mapcopy);
}

int	closebutton(t_solong *chr)
{
	freemap(chr);
	mlx_destroy_window(chr->mlx, chr->mlx_win);
	ft_printf("Successfully Closed\n");
	exit(0);
}

void	errorm(char c, t_solong *chr)
{
	if (c == 'm')
		ft_printf("Map Error\n");
	if (c == 's')
		ft_printf("Congratulations on collecting all the mouses\n");
	if (c == 't')
		ft_printf("Textures Error\n");
	if (c == 'e')
		ft_printf("Successfully Closed\n");
	if (c == 'f')
	{
		ft_printf("Map Error\n");
		freemapcpy(chr);
	}
	if (c != 't')
		freemap(chr);
	if (c != 'm' && c != 't' && c != 'f')
		mlx_destroy_window(chr->mlx, chr->mlx_win);
	exit(1);
}
