/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:22:47 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/21 15:23:59 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tb;

	if (count > 4294967295)
		return (NULL);
	tb = malloc(count * size);
	if (!tb)
		return (NULL);
	ft_bzero(tb, count * size);
	return (tb);
}
/*#include <stdio.h>
int	main()
{
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	int lol = memcmp(d1, d2, size * sizeof(int));
	if (lol)
		printf("%d, dommage\n", lol);
	else
		printf("No problem");
	free(d1);
	free(d2);
	return (0);
}*/