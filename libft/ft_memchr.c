/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:36:26 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/21 15:26:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	ch;
	char	*str;
	int		i;

	ch = (char)c;
	i = 0;
	str = (char *)s;
	while (n--)
	{
		if (str[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int	main()
{
	const unsigned int	size = 0;
	int					source[10] = {1,2,3,4,5,6,7,8,9,10};
	int					novalue = 1;
	int					value = 1;
	void				*found = memchr(source, novalue, size);
	
	printf("%d is %s\n", novalue, (found != NULL ? "found" : "not found"));
	found = ft_memchr(source, value, size);
	printf("%d is %s\n", value, (found != NULL ? "found" : "not found"));
	return (0);
}*/