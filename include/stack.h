/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:10:55 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/21 17:23:23 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

t_d_list	*create_stack_with_arg(int argc, char *argv[]);

void		push(t_d_list **from, t_d_list **to);
void		swap(t_d_list *stack);
void		rotate(t_d_list **stack);

void		print_stacks(t_d_list *stack_a, t_d_list *stack_b);
int			check_stack_sorted(t_d_list *stack_a, t_d_list *stack_b);

#endif
