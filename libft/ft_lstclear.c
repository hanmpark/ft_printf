/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:32:18 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/26 15:19:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*theone;
	t_list	*next;

	if (lst && del)
	{
		theone = *lst;
		while (theone)
		{
			next = theone->next;
			ft_lstdelone(theone, del);
			theone = next;
		}
		*lst = NULL;
	}
}
