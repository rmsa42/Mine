/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:05:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/10 16:01:27 by rumachad         ###   ########.fr       */
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
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	leftover = (char *)malloc((ft_strlen(tmp) - i + 1) * sizeof(char));
	if (leftover == NULL)
		return (NULL);
	j = 0;
	if (tmp[i] == '\n')
		i++;
	while (tmp[i] != '\0')
	{
		leftover[j] = tmp[i];
		i++;
		j++;
	}
	leftover[j] = '\0';
	free(tmp);
	return (leftover);
}

char	*line(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	int			size;
	char		*fline;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (size != 0)
	{
		if (ft_strchr(tmp, '\n') != NULL)
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == 0)
		{
		
			return (NULL);
		}
		buffer[size] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
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