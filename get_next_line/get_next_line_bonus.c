/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:57:36 by ntalmon           #+#    #+#             */
/*   Updated: 2023/11/09 13:46:23 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX];
	char		*returnline;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		free(text[fd]);
		text[fd] = NULL;
		return (NULL);
	}
	text[fd] = readtext(fd, text[fd]);
	if (text[fd] == NULL)
		return (NULL);
	returnline = line(text[fd]);
	temp = next(text[fd]);
	free(text[fd]);
	if (!temp)
		text[fd] = NULL;
	text[fd] = temp;
	return (returnline);
}

char	*readtext(int fd, char *text)
{
	int		rtext;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	rtext = 1;
	while (rtext != 0 && ft_strchr(text, '\n') == NULL)
	{
		rtext = read(fd, buffer, BUFFER_SIZE);
		if (rtext == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[rtext] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*line(char *text)
{
	char	*singleline;
	int		i;

	i = 0;
	if (text[i] == '\0')
		return (NULL);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	singleline = malloc(sizeof(char) * (i + 2));
	if (singleline == NULL)
		return (NULL);
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
	{
		singleline[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		singleline[i] = text[i];
		i++;
	}
	singleline[i] = '\0';
	return (singleline);
}

char	*next(char *buffer)
{
	char	*nextline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(buffer))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!(buffer[i]) || !(buffer[i + 1]))
	{
		if (buffer != 0)
			return (NULL);
	}
	nextline = (char *)malloc ((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!(nextline))
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		nextline[j++] = buffer[i++];
	nextline[j] = '\0';
	return (nextline);
}
