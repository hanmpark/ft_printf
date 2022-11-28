/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:22:47 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/26 18:03:17 by hanmpark         ###   ########.fr       */
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
