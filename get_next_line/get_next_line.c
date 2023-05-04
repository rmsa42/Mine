/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:05:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/04 16:31:43 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static int		temp;
	char			c;
	static char		*buffer;

	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	temp = 0;
	while (read(fd, &c, 1) == 1 && temp < BUFFER_SIZE)
	{
		buffer[temp] = c;
		if (c == '\n')
		{
			buffer = (char *)realloc(buffer, (temp + 1) * sizeof(char));
			if (buffer == NULL)
				return (NULL);
			buffer[temp + 1] = '\0';
			return (buffer);
		}
		temp++;
	}
	buffer = (char *)realloc(buffer, (0) * sizeof(char));
	return (NULL);
}

/* int main()
{
	int fd;
	int	i;
	char	*a;

	fd = open ("/nfs/homes/rumachad/42Curso/get_next_line/test.txt", O_RDWR);
	i = 0;
	while (i < 5)
	{
		a = get_next_line(fd);
		printf("%s", a);
		free(a);
		i++;
	}
} */