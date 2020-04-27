/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_fillit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:19:38 by afougere          #+#    #+#             */
/*   Updated: 2016/03/28 14:46:20 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_resolve_tetri(char **tab_bis, char **tab, int x, int y)
{
	if (*tab == NULL)
		return (1);
	while (tab_bis && tab_bis[y] != NULL)
	{
		if (ft_can_i_place_tetri(tab_bis, tab, x, y) == 1)
		{
			ft_place_tetri(tab_bis, tab, x, y);
			if (ft_resolve_tetri(tab_bis, tab + 4, 0, 0) == 0)
				ft_remove_tetri(tab_bis, tab, x, y);
			else
				return (1);
		}
		x++;
		if (tab_bis[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	return (0);
}

void	ft_free_malloc(char **tab_bis)
{
	int i;

	i = 0;
	if (tab_bis != NULL)
	{
		while (tab_bis[i])
		{
			free(tab_bis[i]);
			i++;
		}
		free(tab_bis);
	}
}

int		ft_sqrt_fillit(int i)
{
	double		res;
	double		sv;

	res = 1;
	sv = 0;
	while (sv != res)
	{
		sv = res;
		res = 0.5 * (res + i / res);
	}
	if ((int)res > res)
		return ((int)res + 1);
	return ((int)res);
}

char	**ft_malloc_tab(char **tab, char *file)
{
	char	**tab_bis;
	int		col;
	int		i;

	col = ft_sqrt_fillit(((ft_count_car(file) + 1) / 21) * 4);
	tab_bis = NULL;
	while (tab_bis == NULL || ft_resolve_tetri(tab_bis, tab, 0, 0) == 0)
	{
		ft_free_malloc(tab_bis);
		if ((tab_bis = (char **)malloc(sizeof(char *) * (col + 1))) == NULL)
			return (NULL);
		tab_bis[col] = NULL;
		i = -1;
		while (++i < col)
		{
			if ((tab_bis[i] = (char *)malloc(sizeof(char) * (col + 1))) == NULL)
				return (NULL);
			tab_bis[i][col] = '\0';
			ft_memset(tab_bis[i], '.', col);
		}
		col += 1;
	}
	return (tab_bis);
}

void	ft_switch_letter(char **tab)
{
	int		i;
	int		j;
	char	c;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	c = 'A';
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				tab[i][j] = c;
				if ((k = (k + 1) % 4) == 0)
					c++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
