/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:25:20 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/11 18:20:38 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_low_value(t_stack *stack)
{
	int		n;

	n = (int)stack->content;
	while (stack)
	{
		if (n > (int)stack->content)
			n = (int)stack->content;
		stack = stack->next;
	}
	return (n);
}

void	stack_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		n;

	while (stack_size(*stack_a) > 0)
	{
		if (check_stack_sorted(*stack_a, *stack_b))
			return ;
		if ((int)(*stack_a)->content == get_low_value(*stack_a))
		{
			ft_putendl_fd("pb", 1);
			push(stack_a, stack_b);
		}
		else
		{
			ft_putendl_fd("ra", 1);
			rotate(stack_a);
		}
	}
	n = stack_size(*stack_b);
	while (n-- > 0)
	{
		ft_putendl_fd("pa", 1);
		push(stack_b, stack_a);
	}
}
