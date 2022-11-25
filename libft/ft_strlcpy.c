/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:25:40 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/11 17:01:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if ((!dst || !src) && !dstsize)
		return (i);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "Hello there";
	char	buffer[19] = "I don't care dude";
	int		r;

	r = strlcpy(buffer, str, 10);
	printf("Copied '%s' into '%s', length %d\n", str, buffer, r);
	r = ft_strlcpy(buffer, str, 10);
	printf("Copied '%s' into '%s', length %d\n", str, buffer, r);
	return (0);
}*/