/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:06 by sgokcu            #+#    #+#             */
/*   Updated: 2024/02/13 16:53:06 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_floodcheck(t_solong *solong)
{
	int	y;
	int	x;

	y = 0;
	while (y < solong->mapy)
	{
		x = 0;
		while (x < solong->mapx)
		{
			if (ft_strchr("PEC", solong->mapcopy[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_flood2(t_solong *solong)
{
	t_point	map;
	t_point	character;

	map.x = solong->mapx;
	map.y = solong->mapy;
	character.x = solong->chrx;
	character.y = solong->chry;
	f_fill(solong->mapcopy, map, character.y, character.x);
}

void	ft_flood(t_solong *solong)
{
	int	i;
	int	c;
	int	fd;

	i = 0;
	fd = open(solong->map_name, O_RDONLY);
	solong->mapcopy = malloc(sizeof(char *) * (solong->mapy + 1));
	while (i < solong->mapy)
	{
		solong->mapcopy[i] = get_next_line(fd);
		i++;
	}
	solong->mapcopy[i] = NULL;
	ft_flood2(solong);
	c = ft_floodcheck(solong);
	if (c == 1)
		errorm('f', solong);
	else
		freemapcpy(solong);
}
