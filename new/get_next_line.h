/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:12:43 by rfibigr           #+#    #+#             */
/*   Updated: 2018/01/14 19:25:14 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int	get_next_line(const int fd, char **line);
char	*ft_strcut(char **line);
int 	ft_read_to_space(int fd, char **buff);
char	*ft_memcat(char *buff, size_t bufflen, char *sread, size_t rd);

#endif
