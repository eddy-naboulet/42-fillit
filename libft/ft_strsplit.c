/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:54:01 by afougere          #+#    #+#             */
/*   Updated: 2016/01/27 17:36:32 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

static int		nombre_mots(char const *s, char c)
{
	int i;
	int nb_mot;

	nb_mot = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i + 1] != '\0' && s[i])
			nb_mot++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb_mot);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_mot;
	char	**tab;
	char	*len;

	nb_mot = nombre_mots(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (nb_mot + 1))) == NULL)
		return (NULL);
	tab[nb_mot] = NULL;
	i = -1;
	while (++i < nb_mot)
	{
		while (*s == c)
			s++;
		len = ft_strchr(s, c);
		if (len != NULL)
			tab[i] = ft_strsub(s, 0, len - s);
		else
			tab[i] = ft_strsub(s, 0, ft_strlen(s));
		while (*s != c && *s)
			s++;
	}
	return (tab);
}
