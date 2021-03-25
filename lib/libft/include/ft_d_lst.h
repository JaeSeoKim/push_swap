/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:46:37 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/24 20:38:49 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_D_LST_H
# define FT_D_LST_H

# include "libft.h"
# include "ft_d_lst_type.h"

t_d_list	*ft_d_lstnew(void	*content);
void		ft_d_lstadd_front(t_d_list **lst, t_d_list *new_list);
void		ft_d_lstadd_back(t_d_list **lst, t_d_list *new_list);

int			ft_d_lstsize(t_d_list *lst);
t_d_list	*ft_d_lstlast(t_d_list *lst);

void		ft_d_lstdelone(t_d_list *lst, void (*del)(void*));
void		ft_d_lstclear(t_d_list **lst, void (*del)(void*));

#endif
