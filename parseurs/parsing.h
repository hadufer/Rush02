/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:35:30 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/19 22:26:24 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>

typedef struct s_diclist
{
	char	**key;
	char	**value;
}	t_diclist;

char	*ft_readdic(char *namedic);
char	**ft_getkey(char *buffer);
char	**ft_getvalue(char *buffer);
char	**strtotab(char *buffer);

#endif
