/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:33:36 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 20:16:49 by abittel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
typedef struct s_stack{
	char			*data;
	struct s_stack	*next;
}					t_stack;
t_stack	*push_stack(t_stack *stack, char *data);
t_stack	*pop_stack(t_stack *stack);
t_stack	*init(void);
int		print_tab_clear(t_stack *stack);
#endif
