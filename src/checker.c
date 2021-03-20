/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:32:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/20 14:46:53 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_d_list	*stack_a;
	t_d_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = create_stack_with_arg(argc, argv);
	stack_b = NULL;
	ft_d_lstclear(&stack_a, NULL);
	ft_d_lstclear(&stack_b, NULL);
	system("leaks checker");
	return (0);
}
