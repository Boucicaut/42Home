#include "libft.h"

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list	*elem;

	if ((elem = (t_list*)malloc(sizeof(*elem))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if ((elem->content = malloc(sizeof(content_size))) == NULL)
		{
			free(elem);
			return (NULL);
		}
		ft_memcpy(elem->content ,content ,content_size);
		elem->content = content;
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
