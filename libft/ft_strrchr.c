/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:13:37 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/26 18:08:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	if (!c || c == 1024)
		return ((char *)s + ft_strlen(s));
	ptr = NULL;
	while (*s && (char)c)
	{
		if (*s == (char)c)
			ptr = ((char *)s);
		s++;
	}
	return (ptr);
}
