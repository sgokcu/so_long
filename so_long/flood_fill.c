/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:11 by sgokcu            #+#    #+#             */
/*   Updated: 2024/02/13 16:51:43 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_fill(char **tab, t_point size, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= size.y || x >= size.x)
		return ;
	if (tab[y][x] == 'S' || tab[y][x] == '1')
		return ;
	tab[y][x] = 'S';
	f_fill(tab, size, y - 1, x);
	f_fill(tab, size, y + 1, x);
	f_fill(tab, size, y, x - 1);
	f_fill(tab, size, y, x + 1);
}
