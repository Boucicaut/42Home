#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;

	new = NULL;
	list = NULL;
	while (lst != NULL)
	{
		if (new == NULL)
		{
			new = f(lst);
			list = new;
		}
		else
			list->next = f(lst);
		lst = lst->next;
	}
	return (new);
}
