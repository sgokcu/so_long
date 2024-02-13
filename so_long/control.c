/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:03 by sgokcu            #+#    #+#             */
/*   Updated: 2024/02/13 17:44:28 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countline(int fd)
{
	char	*temp;
	int		i;

	i = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	return (i);
}

void	mapcheck3(t_solong *solong)
{
	if (solong->pcount != 1 || solong->ccount < 1 || solong->ecount != 1)
		errorm('m', solong);
	if (solong->mapx >= 41 || solong->mapy >= 22)
		errorm('m', solong);
}

void	mapcheck2(t_solong *solong, int x, int y)
{
	while (y < solong->mapy)
	{
		x = 0;
		while (x < solong->map[y][x])
		{
			if (solong->map[y][x] == 'P')
			{
				solong->pcount += 1;
				solong->chrx = x;
				solong->chry = y;
			}
			if (solong->map[y][x] == 'E')
				solong->ecount += 1;
			if (solong->map[y][x] == 'C')
				solong->ccount += 1;
			if (x >= solong->mapx || y >= solong->mapy)
				errorm('m', solong);
			x++;
		}
		y++;
	}
	mapcheck3(solong);
}

void	mapcheck(t_solong *solong)
{
	int	y;
	int	x;

	y = 0;
	while (y < solong->mapy)
	{
		x = 0;
		while (solong->map[y][x])
		{
			if ((y == 0 || y == solong->mapy - 1)
				|| (x == 0 || x == solong->mapx - 1))
			{
				if (solong->map[y][x] != '1')
					errorm('m', solong);
			}
			if (!ft_strchr("10PEC", solong->map[y][x]))
				errorm('m', solong);
			x++;
		}
		if (x != solong->mapx)
			errorm('m', solong);
		y++;
	}
	mapcheck2(solong, 0, 0);
}

void	ft_getmap(t_solong *solong)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(solong->map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Can't openable file!\n");
		exit(1);
	}
	solong->mapy = countline(fd);
	solong->map = malloc(sizeof(char *) * (solong->mapy + 1));
	close(fd);
	fd = open(solong->map_name, O_RDONLY);
	while (i < solong->mapy)
	{
		solong->map[i] = get_next_line(fd);
		i++;
	}
	solong->map[i] = NULL;
	solong->mapx = ft_strlen(solong->map[0]);
	solong->ccount = 0;
	solong->ecount = 0;
	solong->pcount = 0;
	close(fd);
}
