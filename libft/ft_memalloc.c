/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:39:13 by afougere          #+#    #+#             */
/*   Updated: 2016/01/27 16:55:04 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (size == 0)
		return (NULL);
	mem = (void *)malloc(sizeof(void) * size);
	if (mem == NULL)
		return (NULL);
	bzero(mem, size);
	return (mem);
}
