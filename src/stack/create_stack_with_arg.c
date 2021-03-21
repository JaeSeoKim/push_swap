/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_with_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:24:57 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/21 21:26:38 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	put_error_with_clear(t_d_list *result)
{
	ft_d_lstclear(&result, NULL);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	duplicate_check(t_d_list *result, void *content)
{
	t_d_list	*curr;

	curr = result;
	while (curr)
	{
		if (curr->content == content)
			put_error_with_clear(result);
		curr = curr->next;
	}
}

static long	atoi_check(char *s, t_d_list *result)
{
	char	flag;
	t_ll	n;

	flag = 0;
	n = 0;
	((*s == '-') && (flag = 1) && (++s));
	if (ft_strlen(s) > 10)
		put_error_with_clear(result);
	while (ft_isdigit(*s))
	{
		n *= 10;
		n += *s++ - '0';
	}
	((flag == 1) && (n *= -1));
	if (*s != '\0' || (n < FT_INT_MIN) || (n > FT_INT_MAX))
		put_error_with_clear(result);
	duplicate_check(result, (void *)n);
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
		tmp = ft_d_lstnew((void *)atoi_check(argv[i], result));
		if (tmp == NULL)
			put_error_with_clear(result);
		ft_d_lstadd_back(&result, tmp);
	}
	return (result);
}
