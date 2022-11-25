/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:37:33 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/21 16:07:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	i = 0;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*#include <stdio.h>
int	main()
{
	int	source[10] = {1,2,3,4,5,6,7,8,9,10};
	int	destination[10];

	ft_memmove(source + 2, source, sizeof(int) * 8);
	for (int i = 0; i < 10; i++)
		printf("destination[%d]=%d\n", i, destination[i]);
	for (int i = 0; i < 10; i++)
		printf("source[%d]=%d\n", i, destination[i]); 
	return (0);
}*/