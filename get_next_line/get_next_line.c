/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:05:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/11 13:06:59 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*delete_line(char *tmp)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	while (tmp[i] != '\n' && tmp[i])
		i++;
	leftover = (char *)malloc((ft_strlen(tmp) - i + 1) * sizeof(char));
	if (leftover == NULL)
		return (NULL);
	j = 0;
	if (tmp[i] == '\n')
		i++;
	while (tmp[i] != '\0')
		leftover[j++] = tmp[i++];
	leftover[j] = '\0';
	free(tmp);
	return (leftover);
}

char	*line(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0')
		line = (char *)malloc(sizeof(char) * i + 1);
	else
		line = (char *)malloc(sizeof(char) * i + 2);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*readed(char *tmp, int fd)
{
	int		size;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	size = 1;
	while (ft_strchr(tmp, '\n') == NULL && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*fline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = readed(tmp, fd);
	if (tmp == NULL)
		return (NULL);
	fline = line(tmp);
	tmp = delete_line(tmp);
	return (fline);
}

int main()
{
	int 	fd;
	int		i = 0;
	char	*a;

	fd = open ("/nfs/homes/rumachad/42Curso/get_next_line/test.txt", O_RDWR);
	while (i < 6)
	{
		a = get_next_line(fd);
		printf("%s", a);
		free(a);
		i++;
	}
}