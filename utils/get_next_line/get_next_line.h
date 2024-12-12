/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:29:13 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/04 22:38:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef enum s_opt
{
	O_NONE = 0,
	O_READ,
}			t_opt;
typedef enum s_err
{
	E_NONE = 0,
	E_READ,
	E_ALLOCATE,
	END_LINE,
	END_FILE,
}			t_err;

typedef struct s_str
{
	char	*base;
	ssize_t	size;
	ssize_t	index;
}			t_str;
char		*get_next_line(int fd);
t_err		process_char(t_str *buf, t_str *line, int fd);
t_err		allocate(t_str *str, t_opt opt, int fd);
t_err		reallocate(t_str *str);
void		release(t_str *str);
#endif