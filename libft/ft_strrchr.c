/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:13:37 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/18 00:34:08 by hanmpark         ###   ########.fr       */
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
/*#include <stdio.h>
int	main()
{
	char	str[] = "abbbbbbbb";
	char	str1[] = "abbbbbbbb";
	char	*r;
	char	*o;
	char	ch = 'a';

	r = ft_strrchr(str, ch);
	o = strrchr(str1, ch);
	printf("String after |%c| is - |%s|\n", ch, r);
	printf("String after |%c| is - |%s|\n", ch, o);
	return (0);
}*/