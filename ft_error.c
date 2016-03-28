/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:19:20 by afougere          #+#    #+#             */
/*   Updated: 2016/03/28 14:45:31 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	aff_error(void)
{
	write(1, "error\n", 6);
}

int		ft_error(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) != 4)
			return (0);
		i++;
	}
	if (i % 4 != 0)
		return (0);
	return (1);
}

int		nb_form(char **tab)
{
	int i;
	int j;
	int car;

	car = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == '#')
				car++;
			j++;
		}
		i++;
		j = 0;
	}
	if (car == 4)
		return (1);
	return (0);
}

int		ft_error_bis(char *buf, char *file)
{
	int i;
	int cpt;
	int j;

	cpt = 0;
	i = 0;
	while (buf[cpt])
	{
		if (buf[cpt] != '.' && buf[cpt] != '#' && buf[cpt] != '\n')
			return (0);
		if (buf[cpt] == '\n')
			i++;
		cpt++;
	}
	j = (ft_count_car(file) + 1) / 21;
	if (j * 5 - 1 != i)
		return (0);
	return (i);
}
