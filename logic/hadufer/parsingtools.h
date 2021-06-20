/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingtools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 19:00:07 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 17:51:43 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSINGTOOLS_H
# define PARSINGTOOLS_H

struct s_countvars
{
	int		i;
	int		imax;
	int		j;
	int		ibuf;
	int		icount;
	int		lenbuf;
	char	**tbl;
};

int		ft_getfilelenght(char *namedic);
char	**strtotab(char *buffer);
char	*ft_strdup(char *str);

#endif
