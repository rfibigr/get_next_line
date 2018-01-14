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
	int				rd; 
	static char		s[BUFF_SIZE + 1]; 
	char 			*tmp;
	char 			*buff;

	if (fd == -1)
		return (-1);
	*line = ft_memalloc(1);
	buff = ft_strnew(BUFF_SIZE);
	if (ft_strchr(s, '\n'))
	{
		ft_strcpy(buff, s);
		ft_check_join(&*line, buff);
		rd = 1;
	}
	else 
	{
	*line = ft_strdup(s); 
	rd = read (fd, buff, BUFF_SIZE);
	while (ft_check_join(&*line, buff) && rd >= 1)
		rd = read (fd, buff, BUFF_SIZE);
	}
	if ((tmp = ft_strchr(buff, '\n')))
		ft_strcpy(s, tmp + 1);
	free(buff);
	return (rd);
}

/*
** fonction creation de chaine 
**	la fonction controle la presence d'un \n dans la chaine 
**	si elle trouve un \n on cree la chaine a bonne dimension et on renvoie 0
**	si on ne trouve pas de \n on copie s a la suite de la chaine et on renvoie 1
*/

int		ft_check_join(char **line, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(*line, buff);
	free(*line);
	*line = ft_strdup(tmp);
	free(tmp);
	if (!(ft_strchr(*line, '\n')))
		return (1);
	ft_strclr(ft_strchr(*line, '\n') + 1);
	return (0);
}
