/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:19:15 by afougere          #+#    #+#             */
/*   Updated: 2016/03/28 14:45:20 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 545

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_error(char **tab);
void	aff_error();
int		ft_sqrt_fillit(int i);
int		ft_count_car(char *file);
char	**ft_read_map(char *file);
int		ft_error_bis(char *buf, char *file);
int		ft_verif_next(char **tab, int i, int j, int voisin);
int		ft_verif_next_bis(char **tab);
int		nb_form(char **tab);
void	ft_switch_letter(char **tab);
char	**ft_malloc_tab(char **tab, char *file);
void	ft_move_form(char **tab);
void	ft_move_form_bis(char **tab);
void	ft_all_form(char **tab);
int		ft_resolve_tetri(char **tab_bis, char **tab, int x, int y);
void	ft_place_tetri(char **tab_bis, char **tab, int x, int y);
int		ft_can_i_place_tetri(char **tab_bis, char **tab, int x, int y);
void	ft_remove_tetri(char **tab_bis, char **tab, int x, int y);
void	ft_free_malloc(char **tab_bis);
char	**ft_malloc_tab(char **tab, char *file);

#endif
