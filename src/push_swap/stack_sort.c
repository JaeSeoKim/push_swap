/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:25:20 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/24 22:14:55 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_low_value(t_d_list *stack)
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


void	stack_sort(t_d_list **stack_a, t_d_list **stack_b)
{
	int		n;

	while (ft_d_lstsize(*stack_a) > 0)
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
	n = ft_d_lstsize(*stack_b);
	while (n-- > 0)
	{
		ft_putendl_fd("pa", 1);
		push(stack_b, stack_a);
	}
}
