/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:01:57 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/11 17:00:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;

	if ((!dst || !src) && !size)
		return (0);
	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	i = 0;
	while (src[i] && dsize + i < size - 1)
	{
		dst[dsize + i] = src[i];
		i++;
	}
	dst[dsize + i] = '\0';
	return (dsize + ssize);
}
/*#include <stdio.h>
#include <unistd.h>
void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}
int	main()
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, '\0', 15);
	memset(dest, 'r', 6);
	memset(dest, 'r', 14);
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
	write(1, "\n", 1);
	write(1, dest, 15);
	return (0);
}*/