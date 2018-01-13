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

	rd = read (fd, s, BUFF_SIZE);
	*line = ft_memalloc(1);
	while (ft_check_join(&*line, s) !=1 && rd > 0)
		rd = read (fd, s, BUFF_SIZE);
	return (rd);
}

// fonction creation de chaine 
//	la fonction controle la presence d'un \n dans la chaine 
//	si elle trouve un \n on cree la chaine a bonne dimension et on renvoie 1
//	si on ne trouve pas de \n on copie s a la suite de la chaine et on renvoie 0 

int		ft_check_join(char **line, char *s)
{
	int		n;
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*line) + BUFF_SIZE);
	tmp = ft_strjoin(*line, s);
	free(*line);
	*line = ft_strdup(tmp);
	free(tmp);
	if (!(ft_strchr(*line, '\n')))
		n = 0;
	else
	{
			
		n = 1;
	}	
	return (n);
}

//Fonction read

