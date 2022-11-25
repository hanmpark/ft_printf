/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:40:07 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/21 09:32:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str++ = 0;
		n--;
	}
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "Hello World";
	ft_bzero(str, 3);
	printf("%s\n", str);
	return (0);
}*/