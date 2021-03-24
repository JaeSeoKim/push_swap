/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_with_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:24:57 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/24 20:30:40 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_split_clean(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static void	put_error_with_clear(t_d_list *result, char **split)
{
	ft_d_lstclear(&result, NULL);
	ft_putendl_fd("Error", 2);
	ft_split_clean(split);
	exit(1);
}

static long	atoi_check(char *s, t_d_list *result, char **split)
{
	t_d_list	*curr;
	char		flag;
	t_ll		n;

	flag = 0;
	n = 0;
	((*s == '-') && (flag = 1) && (++s));
	if (ft_strlen(s) > 10 || ft_strlen(s) == 0)
		put_error_with_clear(result, split);
	while (ft_isdigit(*s))
	{
		n *= 10;
		n += *s++ - '0';
	}
	((flag == 1) && (n *= -1));
	if (*s != '\0' || (n < FT_INT_MIN) || (n > FT_INT_MAX))
		put_error_with_clear(result, split);
	curr = result;
	while (curr)
	{
		if (curr->content == (void *)n)
			put_error_with_clear(result, split);
		curr = curr->next;
	}
	return (n);
}

t_d_list	*create_stack_with_arg(int argc, char *argv[])
{
	int			rv[2];
	char		**split;
	t_d_list	*result;
	t_d_list	*tmp;

	result = NULL;
	rv[0] = 0;
	while (++rv[0] < argc)
	{
		split = ft_split(argv[rv[0]], ' ');
		if (split == NULL)
			put_error_with_clear(result, split);
		rv[1] = -1;
		while (split[++rv[1]])
		{
			tmp = ft_d_lstnew((void *)atoi_check(split[rv[1]], result, split));
			if (tmp == NULL)
				put_error_with_clear(result, split);
			ft_d_lstadd_back(&result, tmp);
		}
		ft_split_clean(split);
	}
	return (result);
}
