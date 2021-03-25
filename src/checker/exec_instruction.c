/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:08:43 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/24 22:12:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	switch_instruction_2(
	char *instruction,
	t_d_list **stack_a,
	t_d_list **stack_b)
{
	if (!ft_strcmp(instruction, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(instruction, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(instruction, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(instruction, "rra"))
		rrotate(stack_a);
	else if (!ft_strcmp(instruction, "rrb"))
		rrotate(stack_b);
	else if (!ft_strcmp(instruction, "rrr"))
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
	else
		return (1);
	return (0);
}

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
		return (switch_instruction_2(instruction, stack_a, stack_b));
	return (0);
}

int	exec_instruction(
	t_list *instructions,
	t_d_list **stack_a,
	t_d_list **stack_b)
{
	int		instruction_err;

	while (instructions)
	{
		instruction_err = switch_instruction(\
			instructions->content, stack_a, stack_b);
		ft_putendl_fd(instructions->content, 1);
		if (instruction_err)
			return (0);
		instructions = instructions->next;
	}
	return (1);
}
