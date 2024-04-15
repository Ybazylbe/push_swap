/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:53:24 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:53:25 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	index;

	if (!ft_strlen(little))
		return ((char *)big);
	if (!ft_strlen(big) || len < ft_strlen(little))
		return (NULL);
	little_len = ft_strlen(little);
	index = 0;
	while (big[index] && len >= little_len)
	{
		if (ft_strncmp((big + index), little, little_len) == 0)
			return ((char *)(big + index));
		index++;
		len--;
	}
	return (NULL);
}
