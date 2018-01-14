/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */

/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				rd; 
	static char		s[BUFF_SIZE + 1]; 
	char 			*tmp;
	char 			*buff;

	buff = ft_strnew(BUFF_SIZE);
	rd = read (fd, buff, BUFF_SIZE);
	if (*s)
		*line = ft_strdup(s);
	else 
		*line = ft_memalloc(1);
	while (ft_check_join(&*line, buff) && rd > 1)
		rd = read (fd, buff, BUFF_SIZE);
	if ((tmp = ft_strchr(*line, '\n')))
	{
		tmp = tmp + 1;
		ft_strcpy(s, tmp);
	}

	return (rd);
}

// fonction creation de chaine 
//	la fonction controle la presence d'un \n dans la chaine 
//	si elle trouve un \n on cree la chaine a bonne dimension et on renvoie 1
//	si on ne trouve pas de \n on copie s a la suite de la chaine et on renvoie 0 

int		ft_check_join(char **line, char *buff)
{
	int		n;
	char	*tmp;

	tmp = ft_strjoin(*line, buff);
	free(*line);
	*line = ft_strdup(tmp);
	free(tmp);
	if (!(ft_strchr(*line, '\n')))
		n = 1;
	else
	{
		
		n = 0;
	}
	return (n);
}
