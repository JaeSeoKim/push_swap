/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:10:59 by jaeskim           #+#    #+#             */
/*   Updated: 2021/06/12 21:57:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	data;

	if (argc < 2)
		return (0);
	ft_memset(&data, 0, sizeof(data));
	if (!ft_strcmp(argv[1], "-v"))
	{
		data.visualizer = 1;
		data.a = create_stack_with_arg(--argc, ++argv);
	}
	else
		data.a = create_stack_with_arg(argc, argv);
	data.b = NULL;
	stack_sort(&data);
	stack_clear(&data.a);
	stack_clear(&data.b);
	return (0);
}
