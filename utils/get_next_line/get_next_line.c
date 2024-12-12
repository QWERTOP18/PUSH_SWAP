/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:47:25 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/04 22:36:49 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_err	process_char(t_str *buf, t_str *line, int fd)
{
	char	ch;
	t_err	err;

	err = E_NONE;
	if (buf->index >= buf->size)
		err = allocate(buf, O_READ, fd);
	if (line->index >= line->size)
		err = reallocate(line);
	if (err)
		return (err);
	ch = buf->base[buf->index];
	buf->index++;
	line->base[line->index] = ch;
	line->index++;
	line->base[line->index] = '\0';
	if (ch == '\n')
		return (END_LINE);
	return (E_NONE);
}

char	*get_next_line(int fd)
{
	t_str			line;
	static t_str	buf;
	t_err			err;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line.base = NULL;
	err = allocate(&line, O_NONE, fd);
	if (!buf.base)
		err = allocate(&buf, O_READ, fd);
	while (err == E_NONE)
	{
		err = process_char(&buf, &line, fd);
	}
	if (((err == END_LINE || err == END_FILE)) && line.index != 0)
	{
		return (line.base);
	}
	release(&buf);
	release(&line);
	return (NULL);
}

// #ifdef TEST
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("s.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("line=%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
// #endif