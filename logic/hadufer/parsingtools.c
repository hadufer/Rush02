/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:59:58 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 17:51:10 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsingtools.h"
#include "utils.h"
#include <stdlib.h>

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

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i])
		i++;
	ret = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void	initstruct(struct s_countvars *cvar)
{
	cvar->i = 0;
	cvar->imax = 0;
	cvar->j = 0;
	cvar->ibuf = 0;
	cvar->icount = 0;
	cvar->lenbuf = 0;
}

void	pushtab(struct s_countvars *cvar, char *buffer)
{
	while (buffer[cvar->icount++] != '\n')
		cvar->lenbuf++;
	cvar->icount++;
	cvar->tbl[cvar->i] = malloc(sizeof(char) * (cvar->lenbuf + 2));
	while (buffer[cvar->ibuf] != '\n')
		cvar->tbl[cvar->i][cvar->j++] = buffer[cvar->ibuf++];
	cvar->tbl[cvar->i++][cvar->j] = '\0';
	cvar->j = 0;
	cvar->ibuf++;
	cvar->lenbuf = 0;
}

char	**strtotab(char *buffer)
{
	struct s_countvars	cvar;

	initstruct(&cvar);
	while (buffer[cvar.ibuf])
	{
		if (buffer[cvar.ibuf++] == '\n')
			cvar.imax++;
	}
	cvar.imax++;
	cvar.ibuf = 0;
	cvar.tbl = malloc(sizeof(char *) * (cvar.imax + 1));
	while (cvar.i < cvar.imax - 1)
		pushtab(&cvar, buffer);
	cvar.tbl[cvar.i] = NULL;
	return (cvar.tbl);
}
