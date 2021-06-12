/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:10:55 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/12 21:51:36 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				content;
}				t_stack;

t_stack	*create_stack_with_arg(int argc, char *argv[]);

void	push(t_stack **from, t_stack **to);
void	swap(t_stack *stack);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		check_stack_sorted(t_stack *stack_a, t_stack *stack_b);
t_stack	*stack_new(int content);
void	stack_add_front(t_stack **lst, t_stack *new_list);
void	stack_add_back(t_stack **lst, t_stack *new_list);

int		stack_size(t_stack *lst);
t_stack	*stack_last(t_stack *lst);

void	stack_clear(t_stack **lst);

#endif
