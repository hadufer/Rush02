/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:37:46 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/19 18:25:08 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

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
		ft_putstr("Dict Error\n");
	if (fd == 3)
	{
		while (read(fd, c, 1) > 0)
			lenbuffer++;
		if (close (fd) == -1)
			ft_putstr("Dict Error\n");
	}
	return (lenbuffer);
}

//Return buffer of dictionnary - FREE MALLOC AFTER USE
char	*ft_readdic(char *namedic)
{
	int		fd;
	int		lenbuffer;
	char	*buffer;

	lenbuffer = ft_getfilelenght(namedic);
	fd = open(namedic, O_RDONLY);
	if (fd == -1)
		ft_putstr("Dict Error\n");
	if (fd == 3)
	{
		buffer = malloc(sizeof(char) * (lenbuffer + 1));
		read(fd, buffer, lenbuffer);
		buffer[lenbuffer] = '\0';
		if (close (fd) == -1)
			ft_putstr("Dict Error\n");
	}
	return (buffer);
}

//Clean Whitespaces
char	*ft_trimspaces(char *buffer)
{
	char	*tmpbuf;
	int		ibuf;
	int		i;
	int		newline;

	tmpbuf = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ibuf = 0;
	newline = 0;
	i = 0;
	while (newline == 0)
	{
		newline = 1;
		while (is_number(buffer[ibuf])) //AJOUTER GESTION TYPE ATOI '-' ou letters 
		{
			tmpbuf[i] = buffer[ibuf];
			i++;
			ibuf++;
		}
		while (is_space(buffer[ibuf]))
			ibuf++;
		if (buffer[ibuf] == ':')
		{
			tmpbuf[i] = buffer[ibuf];
			ibuf++;
			i++;
		}
		while (is_space(buffer[ibuf]))
			ibuf++;
		while (is_printable(buffer[ibuf]))
		{
			tmpbuf[i] = buffer[ibuf];
			ibuf++;
			i++;
		}
		if (buffer[ibuf] == '\n')
		{
			newline = 0;
			tmpbuf[i] = buffer[ibuf];
			ibuf++;
			i++;
		}
	}
	free(buffer);
	buffer = ft_strdup(tmpbuf);
	free(tmpbuf);
	return (buffer);
}
