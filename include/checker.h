/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:31:47 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/21 22:38:57 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "stack.h"

t_list	*read_instruction(void);
int		exec_instruction(
			t_list *instructions,
			t_d_list **stack_a,
			t_d_list **stack_b);

#endif
