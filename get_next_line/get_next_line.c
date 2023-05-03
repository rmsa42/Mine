/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:05:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/05/03 15:34:59 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int		i;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (read(fd, buffer, 5) < BUFFER_SIZE)
	{
		printf("%c", buffer[i]);
		i++;
	}
	return (buffer);
}

int main()
{
	int fd;

	fd = open ("/nfs/homes/rumachad/42Curso/get_next_line/test.txt", O_RDWR);
	get_next_line(fd);
}