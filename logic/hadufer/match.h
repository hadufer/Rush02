/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:33:59 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 20:17:23 by abittel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATCH_H
# include "struct.h"
# define MATCH_H
int		ft_strcmp(char *str1, char *str2);
char	*match(t_diclist *diclist, char *search);
#endif
