/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 12:10:35 by rojones           #+#    #+#             */
/*   Updated: 2016/07/29 17:31:31 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int ft_inc_word(char *line, int *i, int *qut)
{
	int end;
	int dig;
	int op; 

	end = 0;
	op = 0;
	dig = 1;
	while (line[*i] && end == 0)
	{
		if (ft_isop(line[*i]) != 0 && *qut == 0)
			op = 1;
		if (ft_isdigit(line[*i]) == 0 && ft_isop(line[*i]) == 0)
			dig = 0;
		ft_check_arg_case_len(line, qut, i); 
		if (line[*i] == '\0' || (ft_isspace(line[*i]) == 1 && *qut == 0) ||
				(ft_isop(line[*i]) == 1 && *qut == 0 && dig == 0) ||
				(op == 1 && ft_isop(line[*i]) == 0)) 
			end = 1;
		else
			*i = *i + 1;
	} 
	return (op);
}

static char *ft_get_qut(char *line)
{
	char    *line2;
	char    *temp;
	char	*re; 

	temp = NULL;
	line2 = NULL;
	ft_putstr("quote>");
	if (get_next_line(0, &line2) > 0)
	{   
		temp = ft_strjoin(line, line2);
	}
	re =  ft_get_redir(temp);
	if (temp)
		free(temp);
	if (line2)
		free(line2);
	return (re);
}

static char	*ft_extract_redir(char *line, char *redir, int st, int end)
{
	printf("ext redir ented |%s| |%s| st:%d end:%d",line, redir, st, end);
	puts("");
	int		i;
	int		qut;
	char	*re;
	char	*temp;
	char	*temp2;
	char	*temp3;
	char	*temp4;

	re = NULL;
	temp = NULL;
	temp2 = NULL;
	temp3 = NULL;
	temp4 = NULL;
	i = end;
	qut = 0;
	if (redir)
		temp = ft_strjoin(redir, " ");
	printf("char at end |%c|\n", line[end]);
	if(ft_isop(line[end]) == 0)
	{
		temp2 = ft_strsub(line, st, end);
		puts("pased substr");
		if (temp)
			re = ft_strjoin(temp, temp2);
		else
			re = ft_strjoin("", temp2);
		puts("passed strjoin");
		puts("end second if");
	}
	else
	{
		temp2 = ft_strsub(line, st, end);
		if (temp)
			temp3 = ft_strjoin(temp, temp2);
		else
			temp3 = ft_strjoin("", temp2);
		ft_skip_space(line, &i);
		end = i;
		if (ft_inc_word(line, &i, &qut) == 0)
		{
			temp4 = ft_strsub(line, end, i);
			re = ft_strjoin(temp3, temp4);
		}
		else
			ft_putstr("error: redirrection");
	}
	if (temp)
		free(temp);
	if (temp2)
		free(temp2);
	if (temp3)
		free(temp3);
	if (temp4)
		free(temp4);
	return (re);
}

char	*ft_get_redir(char *line)
{
	char	*re; 
	int     qut;
	int     i;
	int		j;

	i = 0;
	qut = 0;
	re = NULL;
	while (line[i] != '\0')
	{   
		j = i;
		ft_skip_space(line, &i);
		if (ft_inc_word(line, &i, &qut))
			re = ft_extract_redir(line, re, j, i - 1);
	}   
	if (qut == 1)
		re = ft_get_qut(line);
	puts(re);
	return (re);
}
