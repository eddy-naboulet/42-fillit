/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:19:52 by afougere          #+#    #+#             */
/*   Updated: 2016/03/25 16:05:24 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_car(char *file)
{
	int		car;
	int		fd;
	char	buf[BUF_SIZE];

	fd = open(file, O_RDONLY);
	car = read(fd, buf, BUF_SIZE);
	close(fd);
	return (car);
}

char	**ft_read_map(char *file)
{
	char	**tab;
	int		fd;
	char	buf[BUF_SIZE + 1];
	char	**tab_bis;
	int		i;

	tab_bis = NULL;
	fd = open(file, O_RDONLY);
	if ((i = read(fd, buf, BUF_SIZE + 1)) > BUF_SIZE)
	{
		aff_error();
		return (NULL);
	}
	buf[i] = '\0';
	tab = ft_strsplit(buf, '\n');
	if (ft_error(tab) == 0 || ft_error_bis(buf, file) == 0
		|| ft_verif_next_bis(tab) == 0)
		aff_error();
	else
	{
		ft_switch_letter(tab);
		ft_all_form(tab);
		tab_bis = ft_malloc_tab(tab, file);
	}
	return (tab_bis);
}

int		main(int argc, char **argv)
{
	char	**tb;
	int		i;

	i = 0;
	if (argc == 2)
	{
		tb = ft_read_map(argv[1]);
		while (tb && tb[i])
		{
			ft_putstr(tb[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		write(2, "usage: .fillit source_file\n", 27);
	return (0);
}
