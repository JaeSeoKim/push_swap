/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:25:20 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/24 15:36:57 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_d_list *stack_a, t_d_list *stack_b)
{
	int i = 0;
	while (!check_stack_sorted(stack_a, stack_b)&& ++i < 100)
	{
		if ((int)stack_a->content > (int)stack_a->next->content)
		{
			ft_putendl_fd("sa", 1);
			swap(stack_a);
		}
		ft_putendl_fd("rra", 1);
		rrotate(&stack_a);
	}
}
