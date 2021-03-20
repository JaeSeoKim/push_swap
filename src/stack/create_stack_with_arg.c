/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_with_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:24:57 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/20 14:32:22 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

static long	atoi_check(char *s)
{
	char	flag;
	t_ll	n;

	flag = 0;
	n = 0;
	((*s == '-') && (flag = 1) && (++s));
	if (ft_strlen(s) > 10)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	while (ft_isdigit(*s))
	{
		n *= 10;
		n += *s++ - '0';
	}
	((flag == 1) && (n *= -1));
	if (*s != '\0' || (n < FT_INT_MIN) || (n > FT_INT_MAX))
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	return (n);
}

t_d_list	*create_stack_with_arg(int argc, char *argv[])
{
	int			i;
	t_d_list	*result;
	t_d_list	*tmp;

	result = NULL;
	i = 0;
	while (++i < argc)
	{
		tmp = ft_d_lstnew((void *)atoi_check(argv[i]));
		if (tmp == NULL)
		{
			ft_d_lstclear(&result, NULL);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		ft_d_lstadd_back(&result, tmp);
	}
	return (result);
}
