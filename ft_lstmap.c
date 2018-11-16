/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:40:52 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/15 20:34:08 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*list;
	t_list	*elem2;
	t_list	*list2;

	elem = lst;
	while (elem)
	{
		f(elem);
		elem = elem->next;
	}
	list = ft_lstnew(lst->content, lst->content_size);
	if (list == NULL)
		return (NULL);
	elem2 = list;
	while (lst->next)
	{
		list2 = ft_lstnew((lst->next)->content, (lst->next)->content_size);
		if (list2 == NULL)
			return (NULL);
		list->next = list2;
		lst = lst->next;
	}
	return (elem2);
}
