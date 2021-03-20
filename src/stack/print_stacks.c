/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:42:23 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/20 15:46:32 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_stacks(t_d_list *stack_a, t_d_list *stack_b)
{
	ft_putendl_fd("[STACK_A]", 1);
	while (stack_a)
	{
		ft_putnbr_fd((int)stack_a->content, 1);
		ft_putchar_fd('\n', 1);
		stack_a = stack_a->next;
	}
	ft_putendl_fd("[STACK_B]", 1);
	while (stack_b)
	{
		ft_putnbr_fd((int)stack_b->content, 1);
		ft_putchar_fd('\n', 1);
		stack_b = stack_b->next;
	}
}