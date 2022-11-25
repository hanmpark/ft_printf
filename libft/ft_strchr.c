/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:04:09 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/18 00:30:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!c || c == 1024)
		return ((char *)s + ft_strlen(s));
	while (*s && (char)c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int	main()
{
	char	str[] = "test";
	char	*r;
	char	*caca;
	int		i = 'e' + 256;
	
	r = ft_strchr(str, i);
	caca = strchr(str, i);
	printf("|%s|\n",r);
	printf("|%s|\n", caca);
	return (0);
}*/