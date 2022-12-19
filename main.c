/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:26 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/19 19:05:55 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello World !";
	int		x = 365;
	//printf("count: %d\n", printf("og: %-p%%\n", &str));
	//ft_printf("\n");
	//ft_printf("count: %d\n", ft_printf("mf: %p%%\n", &str));
	printf("<%.2s> this is a test\n", str);
	ft_printf("<%.2s> this is a test\n", str);
	return (0);
}