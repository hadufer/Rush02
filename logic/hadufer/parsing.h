/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:35:30 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 15:22:12 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>

struct s_getvars
{
	char	*tmpbuf;
	int		ibuf;
	int		i;
	int		newline;
	char	**key;
	char	**value;
};

char	*ft_readdic(char *namedic);
char	**ft_getkey(char *buffer);
char	**ft_getvalue(char *buffer);

#endif
