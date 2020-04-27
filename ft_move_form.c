/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:19:26 by afougere          #+#    #+#             */
/*   Updated: 2016/02/08 19:28:24 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_move_form(char **tab)
{
	int i;
	int j;
	int decal_pas_decal;
	int k;

	k = -1;
	while (++k <= 3)
	{
		i = 0;
		while (tab[i] && tab[i][0] == '.')
			i++;
		decal_pas_decal = (i > 3) ? 1 : 0;
		if (decal_pas_decal == 1)
		{
			i = -1;
			while (++i < 4)
			{
				j = -1;
				while (++j < 4)
					tab[i][j] = (j == 3) ? '.' : tab[i][j + 1];
			}
		}
	}
}

void	ft_move_form_bis(char **tab)
{
	int i;
	int j;
	int decal_pas_decal;
	int k;

	k = -1;
	while (++k < 3)
	{
		j = 0;
		while (tab[0][j] == '.')
			j++;
		decal_pas_decal = (tab[0][j] == '\0') ? 1 : 0;
		if (decal_pas_decal == 1)
		{
			j = -1;
			while (++j < 4)
			{
				i = -1;
				while (++i < 4)
					tab[i][j] = (i == 3) ? '.' : tab[i + 1][j];
			}
		}
	}
}

void	ft_all_form(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (i % 4 == 0)
		{
			ft_move_form(&tab[i]);
			ft_move_form_bis(&tab[i]);
		}
		i++;
	}
}
