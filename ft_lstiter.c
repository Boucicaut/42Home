#include "libft.h"

void	ft_lstiter(t_list *lst, void(*f)(t_list *elem))
{
	t_list	*elem;

	if ((elem = malloc(sizeof(t_list))) == NULL)
		return;
	elem = lst->next;
	while (elem != NULL)
	{
		f(elem);
		elem = elem->next;
	}
}
