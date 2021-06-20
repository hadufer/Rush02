/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:37:46 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 23:00:59 by hadufer          ###   ########.fr       */
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
		return (NULL);
	fd = open(namedic, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (fd == 3)
	{
		buffer = malloc(sizeof(char) * (lenbuffer + 1));
		read(fd, buffer, lenbuffer);
		buffer[lenbuffer] = '\0';
		if (close (fd) == -1)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (buffer);
}

void	initstructvar(struct s_getvars *var)
{
	var->ibuf = 0;
	var->i = 0;
	var->newline = 0;
}

void	parsekey(struct s_getvars *var, char *buffer)
{
	while (is_number(buffer[var->ibuf]))
		var->tmpbuf[var->i++] = buffer[var->ibuf++];
	while (((is_printable(buffer[var->ibuf])) || (is_space(buffer[var->ibuf])) \
			|| (buffer[var->ibuf] == ':')) && !(buffer[var->ibuf] == '\n'))
		var->ibuf++;
	if (buffer[var->ibuf] == '\n')
	{
		var->newline = 0;
		var->tmpbuf[var->i] = buffer[var->ibuf];
		var->ibuf++;
		var->i++;
	}
}

//Clean first part and return KEY - it free the buffer and do new realloc
char	**ft_getkey(char *buffer)
{
	struct s_getvars	var;

	initstructvar(&var);
	var.tmpbuf = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	while (var.newline == 0)
	{
		var.newline = 1;
		while (buffer[var.ibuf] == '\n')
			var.ibuf++;
		if (is_printable(buffer[var.ibuf]) && !(is_number(buffer[var.ibuf])))
			return (NULL);
		parsekey(&var, buffer);
	}
	var.tmpbuf[var.i] = '\0';
	free(buffer);
	var.key = strtotab(var.tmpbuf);
	free(var.tmpbuf);
	return (var.key);
}

//trim and get last part of list
char	**ft_getvalue(char *buffer)
{
	struct s_getvars	var;

	initstructvar(&var);
	var.tmpbuf = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	while (var.newline == 0)
	{
		var.newline = 1;
		while (((is_printable(buffer[var.ibuf])) || \
				(is_space(buffer[var.ibuf]))) && (buffer[var.ibuf] != ':'))
			var.ibuf++;
		while (is_space(buffer[var.ibuf]) || (buffer[var.ibuf] == ':'))
			var.ibuf++;
		while (is_printable(buffer[var.ibuf]))
			var.tmpbuf[var.i++] = buffer[var.ibuf++];
		if (buffer[var.ibuf] == '\n')
		{
			var.newline = 0;
			var.tmpbuf[var.i++] = buffer[var.ibuf++];
		}
	}
	var.tmpbuf[var.i] = '\0';
	free(buffer);
	var.value = strtotab(var.tmpbuf);
	free(var.tmpbuf);
	return (var.value);
}
