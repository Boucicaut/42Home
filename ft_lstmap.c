/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:45:03 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/10 19:45:04 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*one;
	t_list	*new;
	t_list	*act;

	if (lst == NULL || f == NULL)
		return (NULL);
	one = NULL;
	while (lst)
	{
		new = (*f)(lst);
		if (one != NULL)
		{
			act->next = new;
			act = act->next;
		}
		else
		{
			one = new;
			act = one;
		}
		lst = lst->next;
	}
	return (one);
}
