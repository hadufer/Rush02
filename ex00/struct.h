/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:53:57 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 17:06:22 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "stack.h"
typedef struct s_diclist
{
	char	**key;
	char	**value;
	t_stack	*stack;
}			t_diclist;

#endif
