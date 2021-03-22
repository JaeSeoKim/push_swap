/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:32:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/22 20:10:42 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list		*instructions;
	t_d_list	*stack_a;
	t_d_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = create_stack_with_arg(argc, argv);
	stack_b = NULL;
	instructions = read_instruction();
	if (!exec_instruction(instructions, &stack_a, &stack_b))
		ft_putendl_fd("ERROR", 2);
	else
	{
		if (check_stack_sorted(stack_a, stack_b))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	ft_d_lstclear(&stack_a, NULL);
	ft_d_lstclear(&stack_b, NULL);
	return (0);
}
