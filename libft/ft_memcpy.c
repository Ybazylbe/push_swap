/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:51:25 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:51:27 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	if (!dest && !src)
		return (dest);
	destination = (char *)dest;
	source = (char *)src;
	while (n != 0)
	{
		*destination++ = *source++;
		n--;
	}
	return (dest);
}
