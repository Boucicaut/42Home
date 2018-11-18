/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:32:51 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/06 16:16:58 by ademenet         ###   ########.fr       */
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
