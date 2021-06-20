/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 09:23:38 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 22:56:27 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

bool	is_space(char c);
bool	is_number(char c);
bool	is_printable(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

#endif
