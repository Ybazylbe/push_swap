/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:51:10 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:51:12 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sptr;

	sptr = s;
	while (n-- > 0)
	{
		if ((const unsigned char)*sptr == (unsigned char)c)
			return ((unsigned char *)sptr);
		sptr++;
	}
	return (NULL);
}
