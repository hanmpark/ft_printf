/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:56:44 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/08 16:57:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	while (*av[1])
		printf("%d\n", ft_isalnum((int)*av[1]++));
	return (0);
}*/