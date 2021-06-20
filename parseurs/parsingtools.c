/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:59:58 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 15:05:08 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "parsingtools.h"

char	*ft_strdup(char *src)
{
	char	*tab;
	int		i;
	int		lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	tab = (char *)malloc(sizeof(char *) * (lensrc + 1));
	while (i < lensrc)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

//Get the buffer lenght
int	ft_getfilelenght(char *namedic)
{
	int		lenbuffer;
	int		fd;
	char	c[1];

	lenbuffer = 0;
	fd = open(namedic, O_RDONLY);
	if (fd == -1)
		return (0);
	if (fd == 3)
	{
		while (read(fd, c, 1) > 0)
			lenbuffer++;
		if (close (fd) == -1)
			return (0);
	}
	return (lenbuffer);
}
