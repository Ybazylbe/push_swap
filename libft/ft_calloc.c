/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:47:47 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:47:49 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*memory;
	unsigned long long	total;

	if (nmemb == 0 || size == 0)
	{
		memory = malloc(1);
		if (memory == NULL)
			return (NULL);
		ft_bzero(memory, 1);
		return (memory);
	}
	total = size * nmemb;
	if (total / size == nmemb)
	{
		memory = malloc(total);
		if (memory == NULL)
			return (NULL);
		ft_bzero(memory, total);
		return (memory);
	}
	return (NULL);
}
