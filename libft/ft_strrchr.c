/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:53:30 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:53:31 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*string;
	int			index;

	string = s;
	index = ft_strlen(s);
	if ((unsigned char)c == 0)
		return ((char *)(s + index));
	while (&s[index] >= string)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)(s + index));
		index--;
	}
	return (0);
}
