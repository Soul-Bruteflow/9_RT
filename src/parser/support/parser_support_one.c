/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_support_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:21:23 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "utility/get_next_line.h"

/*
** Closes the file, and checks for the errors.
*/

void	close_file(t_rtv *r)
{
	if ((close(r->pars->fd)) < 0)
		rtv_error(file_close_error);
}

/*
** Opens the file, and checks for the errors.
*/

void	open_file(t_rtv *r)
{
	r->pars->fd = open(r->pars->av[1], O_RDONLY);
	if (r->pars->fd < 0)
		rtv_error(file_open_error);
}

/*
** Checks for the GNL errors.
*/

void	gnl_error(t_rtv *r, int i)
{
	if (i < 0)
	{
		close_file(r);
		rtv_error(gnl_error_code);
	}
}

/*
** Parses int values in to the float.
*/

t_bool	parse_number(t_rtv *r, float *n, int min, int max)
{
	float tmp;

	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		tmp = ft_atoi(r->pars->line);
		if (tmp >= min && tmp <= max)
		{
			*n = tmp;
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

/*
** Parses line by line vector values.
*/

t_bool	parse_vector(t_rtv *r, t_vec3d *v, int min, int max)
{
	if (!(parse_number(r, &v->x, min, max)))
		return (false);
	if (!(parse_number(r, &v->y, min, max)))
		return (false);
	if (!(parse_number(r, &v->z, min, max)))
		return (false);
	return (true);
}
