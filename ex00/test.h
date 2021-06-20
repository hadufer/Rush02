/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:53:57 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/19 16:55:56 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "stack.h"
typedef struct s_diclist
{
	char	**key;
	char	**value;
	t_stack	*stack;
}			t_diclist;

#endif
