/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:00:30 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/11 12:03:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
		character += 32;
	return (character);
}
/*#include <stdio.h>
int	main()
{
	char	c = 'a';
	printf("%c\n", ft_tolower(c));
	return (0);
}*/