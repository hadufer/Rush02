/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:37:46 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 14:54:42 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsingtools.h"
#include "utils.h"

//Return buffer of dictionnary - FREE MALLOC AFTER USE
char	*ft_readdic(char *namedic)
{
	int		fd;
	int		lenbuffer;
	char	*buffer;

	buffer = NULL;
	lenbuffer = ft_getfilelenght(namedic);
	if (lenbuffer == 0)
		ft_putstr("Dict Error\n");
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

//Clean first part and return to struct KEY 
char	**ft_getkey(char *buffer)
{
	char		*tmpbuf;
	int			ibuf;
	int			i;
	int			newline;
	char		**key;

	tmpbuf = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ibuf = 0;
	newline = 0;
	i = 0;
	while (newline == 0)
	{
		newline = 1;
		if (is_printable(buffer[ibuf]) && !(is_number(buffer[ibuf]))) 
		{
			ft_putstr("Dict Error\n");
			return (0);
		}
		while (is_number(buffer[ibuf]))
		{
			tmpbuf[i] = buffer[ibuf];
			i++;
			ibuf++;
		}
		while ((is_space(buffer[ibuf])) || (buffer[ibuf] == ':'))
			ibuf++;
		while (is_printable(buffer[ibuf]))
			ibuf++;
		if (buffer[ibuf] == '\n')
		{
			newline = 0;
			tmpbuf[i] = buffer[ibuf];
			ibuf++;
			i++;
		}
	}
	tmpbuf[i] = '\0';
	free(buffer);
	key = strtotab(tmpbuf);
	free(tmpbuf);
	return (key);
}

//trim and get last part of list
char	**ft_getvalue(char *buffer)
{
	char		*tmpbuf;
	int			ibuf;
	int			i;
	int			newline;
	char		**value;

	tmpbuf = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ibuf = 0;
	newline = 0;
	i = 0;
	while (newline == 0)
	{
		newline = 1;
		while ((is_number(buffer[ibuf])) || (is_space(buffer[ibuf])) \
				|| (buffer[ibuf] == ':'))
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
	tmpbuf[i] = '\0';
	free(buffer);
	value = strtotab(tmpbuf);
	free(tmpbuf);
	return (value);
}

char	**strtotab(char *buffer)
{
	int		i;
	int		imax;
	int		j;
	int		ibuf;
	int		icount;
	int		lenbuf;
	char	**tbl;

	i = 0;
	imax = 0;
	j = 0;
	ibuf = 0;
	icount = 0;
	lenbuf = 0;
	while (buffer[ibuf])
	{
		if (buffer[ibuf] == '\n')
			imax++;
		ibuf++;
	}
	imax++;
	ibuf = 0;
	tbl = malloc(sizeof(char *) * (imax + 1));
	while (i < imax - 1)
	{
		while (buffer[icount] != '\n')
		{
			lenbuf++;
			icount++;
		}
		lenbuf++;
		icount++;
		tbl[i] = malloc(sizeof(char) * (lenbuf + 1));
		while (buffer[ibuf] != '\n')
		{
			tbl[i][j] = buffer[ibuf];
			j++;
			ibuf++;
		}
		tbl[i][j] = '\0';
		i++;
		j = 0;
		ibuf++;
		lenbuf = 0;
	}
	tbl[i] = NULL;
	return (tbl);
}
