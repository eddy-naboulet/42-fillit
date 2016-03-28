/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_voisin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:19:44 by afougere          #+#    #+#             */
/*   Updated: 2016/03/28 14:45:42 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif_next_bis(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (i % 4 == 0 && ft_verif_next(&tab[i], 0, 0, 0) == 0)
			return (0);
		if (i % 4 == 0 && nb_form(&tab[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_verif_next(char **tab, int i, int j, int voisin)
{
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				if (i > 0 && tab[i - 1][j] == '#')
					voisin++;
				if (i < 3 && tab[i + 1][j] == '#')
					voisin++;
				if (j > 0 && tab[i][j - 1] == '#')
					voisin++;
				if (j < 3 && tab[i][j + 1] == '#')
					voisin++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (voisin >= 5)
		return (1);
	return (0);
}
