/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:08:43 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/21 22:38:56 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	put_error_with_clear(t_list *result, char *instruction)
{
	if (instruction)
		free(instruction);
	ft_lstclear(&result, free);
	ft_putendl_fd("Error", 2);
	exit(1);
}

t_list	*read_instruction(void)
{
	int		gnl_status;
	char	*instruction;
	t_list	*instructions;
	t_list	*tmp;

	instructions = NULL;
	gnl_status = get_next_line(0, &instruction);
	instructions = ft_lstnew(instruction);
	if (instructions == NULL)
		put_error_with_clear(instructions, instruction);
	while (gnl_status > 0)
	{
		tmp = ft_lstnew(instruction);
		if (tmp == NULL)
			put_error_with_clear(instructions, instruction);
		ft_lstadd_back(&instructions, tmp);
		gnl_status = get_next_line(0, &instruction);
	}
	if (gnl_status == -1)
		put_error_with_clear(instructions, NULL);
	free(instruction);
	return (instructions);
}
