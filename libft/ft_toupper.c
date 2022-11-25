/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:10 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/11 11:57:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int character)
{
	if (character >= 97 && character <= 122)
		character -= 32;
	return (character);
}
/*#include <stdio.h>
int	main()
{
	char	c = 'a';
	printf("%c\n", ft_toupper(c));
	return (0);
}*/