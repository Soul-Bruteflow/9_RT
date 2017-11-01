/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:11:15 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_whitespaces(const char *s, int *i, float *fact)
{
	int		j;
	float	tmp;

	j = 0;
	tmp = 1;
	while ((ft_isspace(s[j]) != 0 || s[j] == '+') && s[j] != '\0')
		j++;
	if (s[j] == '-')
	{
		j++;
		tmp = -1;
	}
	*i = j;
	*fact = tmp;
}

float	ft_atof(const char *s)
{
	float		rez[2];
	int			d[2];
	int			i;

	rez[0] = 0;
	skip_whitespaces(s, &i, &rez[1]);
	d[1] = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			d[1] = 1;
			i++;
			continue;
		}
		d[0] = s[i] - '0';
		if (d >= 0 && d[0] <= 9)
		{
			if (d[1])
				rez[1] /= 10.0f;
			rez[0] = rez[0] * 10.0f + (float)d[0];
		}
		i++;
	}
	return (rez[0] * rez[1]);
}
