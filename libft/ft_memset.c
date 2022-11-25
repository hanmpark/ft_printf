/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:47:19 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/10 15:37:08 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str++ = c;
		len--;
	}
	return (b);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "Hello World!";
	
	printf("%s\n", str);
	printf("%s\n", ft_memset(str, '7', 4));
	return (0);
}*/