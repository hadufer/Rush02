/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:37:46 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 12:09:48 by rahmed           ###   ########.fr       */
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
	cft_getkey(str);har		**key;

	tmpbuf = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ibuf = 0;
	newline = 0;
	i = 0;
	while (newline == 0)
	{
		newline = 1;
		//AJOUTER GESTION TYPE ATOI '-' ou letters 
		if (is
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
	char	**tbl;
	int		i;
	int		imax;
	int		j;
	int		ibuf;
	int		icount;
	int		lenbuf;

	icount = 0;
	lenbuf = 0;
	i = 0;
	j = 0;
	imax = 0;
	ibuf = 0;
/*COUNT lines */
	while (buffer[ibuf])
	{
		if (buffer[ibuf] == '\n')
			imax++;
		ibuf++;
	}
	imax++; // pour la derniere ligne
	ibuf = 0;
	tbl = malloc(sizeof(char *) * (imax + 1));
	//ft_putstr("JE SUIS : apres malloc i STRTOTAB !\n"); // TEST
	while (i < imax - 1)
	{
		while (buffer[icount] != '\n')
		{
			lenbuf++;
			icount++;
		}
		lenbuf++;
		icount++; //passer le \n
		tbl[i] = malloc(sizeof(char) * (lenbuf + 1));
	//ft_putstr("JE SUIS : apres malloc J STRTOTAB !\n"); // TEST
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
	//ft_putstr("JE SUIS : apres BOUCLE -- i++ --  STRTOTAB !\n"); // TEST
	}
	//ft_putstr("JE SUIS : FIN BOUCLE -- i --  STRTOTAB !\n"); // TEST
	//tbl[i] = malloc(sizeof(char));
	tbl[i] = NULL; // mettre a null?
	//ft_putstr("JE SUIS : fin STRTOTAB !\n"); // TEST
	return (tbl);
}

/*Bkp
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
*/
