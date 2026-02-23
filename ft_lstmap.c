/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:33:22 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/29 13:38:33 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*second_list;
	t_list	*temp;
	void	*changed_content;

	if (!lst || !f || !del)
		return (NULL);
	second_list = NULL;
	while (lst)
	{
		changed_content = f(lst->content);
		if (!changed_content)
			return (ft_lstclear(&second_list, del), NULL);
		temp = ft_lstnew(changed_content);
		if (!temp)
			return (del(changed_content), ft_lstclear(&second_list, del), NULL);
		ft_lstadd_back(&second_list, temp);
		lst = lst->next;
	}
	return (second_list);
}
