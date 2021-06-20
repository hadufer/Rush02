/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abittel <abittel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:01:31 by abittel           #+#    #+#             */
/*   Updated: 2021/06/20 18:57:37 by abittel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CHECK_NUMBER_H
# define CHECK_NUMBER_H
char	**cut_str_blocks3(char *str);
int		get_size(char *str);
int		ft_strlen(char *str);
int		is_good_number(char *str);
int	free_blocks(char **blocks);
#endif
