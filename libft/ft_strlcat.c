/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:52:41 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:52:43 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_index;

	dst_index = 0;
	while (dst[dst_index] != '\0' && dst_index < size)
		dst_index++;
	index = dst_index;
	while (src[dst_index - index] && dst_index + 1 < size)
	{
		dst[dst_index] = src[dst_index - index];
		dst_index++;
	}
	if (index < size)
		dst[dst_index] = '\0';
	return (index + ft_strlen(src));
}
