/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:08:43 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/21 17:19:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	switch_instruction(
	char *instruction,
	t_d_list **stack_a,
	t_d_list **stack_b)
{
	if (!ft_strcmp(instruction, "pa"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(instruction, "pb"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "sa"))
		swap(*stack_a);
	else if (!ft_strcmp(instruction, "sb"))
		swap(*stack_b);
	else if (!ft_strcmp(instruction, "ss"))
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	else
		return (1);
	return (0);
}

int	read_instruction(t_d_list **stack_a, t_d_list **stack_b)
{
	int		instuction_err;
	int		gnl_status;
	char	*instuction;

	gnl_status = get_next_line(0, &instuction);
	while (gnl_status >= 0)
	{
		instuction_err = switch_instruction(instuction, stack_a, stack_b);
		free(instuction);
		if (instuction_err)
			return (0);
		print_stacks(*stack_a, *stack_b);
		if (gnl_status == 0)
			break ;
		gnl_status = get_next_line(0, &instuction);
	}
	return (1);
}
