/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:06:27 by ntalmon           #+#    #+#             */
/*   Updated: 2023/11/09 14:56:52 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*returnline;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	text = readtext(fd, text);
	if (text == NULL)
		return (NULL);
	returnline = line(text);
	temp = next(text);
	free(text);
	if (!temp)
		text = NULL;
	text = temp;
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

// int	main(void)
// {
// 	char	*line;
// 	int		fd1;
// 	char	*filename1 = "testfile1.txt";

// 	fd1 = open( filename1, O_RDONLY);
	// fd1 = 10;
	// line = get_next_line(0);
	// printf("%s\n", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("%s\n", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("%s\n", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("%s\n", line);
	// free(line);
// 	return (0);
// }
