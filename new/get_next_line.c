/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:03:50 by rfibigr           #+#    #+#             */
/*   Updated: 2018/01/14 19:17:51 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int		get_next_line(const int fd, char **line)
{

	static char str[1024][BUFF_SIZE + 1];
	char *buff;
	char *str_end[1024];
	int	bufflen;
	int	strlen;

	bufflen = 0;
	buff = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!(ft_memchr(str[fd], '\n', ft_strlen(str[fd]))))
		bufflen = ft_read_to_space(fd, &buff);
	if (bufflen == -1)
		return (-1);
	strlen = ft_strlen(str[fd]);
	if (!(*line = ft_memcat(str[fd], strlen, buff, bufflen)))
		return (0);
	free (buff);
	if (!(str_end[fd] = ft_strcut(&*line, bufflen + strlen)))
		return (0);
	ft_strcpy(str[fd], str_end[fd]);
	free (str_end[fd]);
	return (1);
}

int ft_read_to_space(int fd, char**buff)
{
	int rd;
	char *sread;
	char *tmp;
	int	i;
	
	i = 0;
	sread = ft_strnew(BUFF_SIZE);
	while ((rd = read(fd, sread, BUFF_SIZE)) > 0)
	{
		if (rd == -1)
			return (-1);
		tmp = ft_memcat(*buff, BUFF_SIZE * i, sread, rd);
		ft_bzero(sread, BUFF_SIZE);
		free (*buff);
		*buff = ft_strnew(BUFF_SIZE * i + rd);
		ft_memcpy(*buff, tmp, BUFF_SIZE * i + rd + 1);
		free(tmp);
		if ((ft_memchr(*buff, '\n', BUFF_SIZE * i + rd)))
			return (BUFF_SIZE * i + rd);
		i++;
	}
	free (sread);
	return (BUFF_SIZE * i + rd);
}

char	*ft_strcut(char **line, int linelen)
{
	char *str;
	char *tmp;
	int cspace;
	int cend;	

	cspace = 0;
	while ((*line)[cspace] != '\n' && cspace < (linelen))
		cspace++;
	cend = linelen - cspace;
	str = ft_strnew(cend);
	tmp = ft_strnew(cspace);
	ft_memcpy(str, *line + cspace + 1, cend);
	ft_memccpy(tmp, *line, '\n', linelen);
	free (*line);
	*line = ft_strnew(cspace);
	ft_memcpy(*line, tmp, cspace);
	free (tmp);
	
	return (str);
}

char	*ft_memcat(char *buff, size_t bufflen, char *sread, size_t rd)
{
	size_t i;
	size_t j;
	char *tmp;

	if (bufflen + rd == 0)
		return NULL;
	tmp = ft_strnew(bufflen + rd);
	i = 0;
	while (i < bufflen)
	{
		tmp[i] = buff[i];
		i++;
	}
	j=0;
	while (i < (bufflen + rd))
	{
		tmp[i] = sread[j];
		j++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}


