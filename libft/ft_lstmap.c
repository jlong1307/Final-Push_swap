/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:58:56 by jlong             #+#    #+#             */
/*   Updated: 2021/04/16 15:01:21 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*ss;

	newlst = NULL;
	while (lst)
	{
		ss = ft_lstnew((*f)(lst ->content));
		if (ss == NULL)
		{
			ft_lstclear(&ss, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, ss);
		lst = lst ->next;
	}
	return (newlst);
}
