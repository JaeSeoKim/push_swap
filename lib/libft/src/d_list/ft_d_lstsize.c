/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:19:28 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/24 20:38:37 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_d_lstsize(t_d_list *lst)
{
	int		cnt;

	cnt = 0;
	while (lst)
	{
		lst = lst->next;
		++cnt;
	}
	return (cnt);
}
