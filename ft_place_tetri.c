/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:19:32 by afougere          #+#    #+#             */
/*   Updated: 2016/03/28 14:44:25 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_i_place_tetri(char **tab_bis, char **tab, int x		, int y)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (i < 4 && tab_bis[y + i])
	{
		while (j < 4)
		{
			if (tab[i][j] != '.')
			{
				if (tab_bis[y + i][x + j] != '.')
					return (0);
				cpt++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (i != 4 && cpt != 4)
		return (0);
	return (1);
}

void	ft_place_tetri(char **tab_bis, char **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] != '.')
				tab_bis[y + i][x + j] = tab[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_remove_tetri(char **tab_bis, char **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] != '.')
				tab_bis[y + i][x + j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}
