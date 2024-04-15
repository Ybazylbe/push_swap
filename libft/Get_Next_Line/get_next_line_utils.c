/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:54:56 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:54:57 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

char	*gnl_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index])
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index++;
	}
	if ((char)c == '\0')
		return ((char *)&str[index]);
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	int		index;
	int		str_len;
	char	*str;

	index = 0;
	str_len = gnl_strlen(s);
	str = (char *)malloc(sizeof(*str) * (str_len + 1));
	if (!str)
		return (NULL);
	while (index < str_len)
	{
		str[index] = s[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*gnl_strjoin(char *buffer, char *content)
{
	size_t	index;
	size_t	sec_index;
	char	*result;

	if (!buffer)
		return (gnl_strdup(content));
	if (!content)
		return (gnl_strdup(buffer));
	index = 0;
	result = (char *)malloc(sizeof(char) * (gnl_strlen(buffer)
				+ gnl_strlen(content)) + 1);
	if (!result)
		return (NULL);
	while (buffer && buffer[index])
	{
		result[index] = buffer[index];
		index++;
	}
	sec_index = 0;
	while (content && content[sec_index])
		result[index++] = content[sec_index++];
	result[index] = '\0';
	free(buffer);
	return (result);
}
