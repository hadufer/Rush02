/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 22:55:26 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 22:55:30 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CHECK_NUMBER_H
# define CHECK_NUMBER_H
char	**cut_str_blocks3(char *str);
int		get_size(char *str);
int		ft_strlen(char *str);
int		get_good_number(char *str);
int		free_blocks(char **blocks);
#endif
