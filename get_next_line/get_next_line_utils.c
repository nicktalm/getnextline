/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:45:10 by ntalmon           #+#    #+#             */
/*   Updated: 2023/11/09 12:19:51 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count ++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*con_str;
	size_t	j;
	size_t	i;

	if (s1 == NULL)
		s1 = ft_strempty(s1);
	if (s2 == NULL)
		return (NULL);
	con_str = malloc (sizeof(char) * (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (con_str == NULL)
	{
		free (s1);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (s1[j] != '\0')
		con_str[i++] = s1[j++];
	j = 0;
	free (s1);
	while (s2[j] != '\0')
		con_str[i++] = s2[j++];
	con_str[i] = '\0';
	return (con_str);
}

char	*ft_strchr(const char *s, int c)
{
	int		len;

	len = 0;
	if (s == NULL)
		return (NULL);
	while (s[len] != (char)c)
	{
		if (s[len] == '\0')
			return (0);
		len++;
	}
	return ((char *)s + len);
}

char	*ft_strempty(char *str)
{
	str = malloc(1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		str[0] = '\0';
	return (str);
}
