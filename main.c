/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:26 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/28 21:03:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello World !";
	//int		x = -5;
	printf(" og = %d\n", printf("<%-14.10s>", str));
	printf(" mf = %d\n", ft_printf("<%-.10s>", str));
	//ft_printf("\n");
	//ft_printf("count: %d\n", ft_printf("mf: %p%%\n", str));
	//printf(" og = %d\n", printf("<%015s>", str));
	return (0);
}