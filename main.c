/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:26 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/03 22:34:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//int	d = 0;
	//char	str[] = "Hello World !";
	printf(" og = %d\n", printf("<%-.d>", 0));
	printf(" mf = %d\n", ft_printf("<%-.d>", 0));
	//system("leaks a.out");
	return (0);
}