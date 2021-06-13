/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:32:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/14 00:19:12 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_sort(t_push_swap data)
{
	if (check_stack_sorted(data.a, data.b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char *argv[])
{
	t_list		*instructions;
	t_push_swap	data;

	if (argc < 2)
		return (0);
	ft_memset(&data, 0, sizeof(data));
	if (!ft_strcmp(argv[1], "-v"))
	{
		data.visualizer = VISUAL;
		--argc;
		++argv;
	}
	data.a = create_stack_with_arg(argc, argv);
	instructions = read_instruction();
	if (!exec_instruction(instructions, &data))
		ft_putendl_fd("ERROR", 2);
	else
		check_sort(data);
	stack_clear(&data.a);
	stack_clear(&data.b);
	ft_lstclear(&instructions, free);
	return (0);
}
