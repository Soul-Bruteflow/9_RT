/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polinom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:12:52 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:12:55 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		negative_discr(t_pol *res, double a, double b)
{
	res->f = atan(sqrt(-res->s) / (-res->q / 2));
	res->f = (res->q < 0) ? res->f : res->f + M_PI;
	res->f = (res->q == 0) ? M_PI / 2 : res->f;
	res->f = res->f / 3;
	res->x_re[0] = 2 * sqrt(-res->p / 3) * cos(res->f) - b / 3 / a;
	res->x_re[1] = 2 * sqrt(-res->p / 3) * cos(res->f + 2 * M_PI / 3)
					- b / 3 / a;
	res->x_re[2] = 2 * sqrt(-res->p / 3) * cos(res->f + 4 * M_PI / 3)
					- b / 3 / a;
	if (res->q == 0)
		res->x_re[2] = -b / 3 / a;
}

void		pozitive_discr(t_pol *res, double a, double b)
{
	double	y1;
	double	y2;

	y1 = exp(log(fabs(-res->q / 2 + sqrt(res->s))) / 3);
	y1 = (-res->q / 2 + sqrt(res->s) > 0) ? y1 : -y1;
	y1 = (-res->q / 2 + sqrt(res->s) == 0) ? 0 : y1;
	y2 = exp(log(fabs(-res->q / 2 - sqrt(res->s))) / 3);
	y2 = (-res->q / 2 - sqrt(res->s) > 0) ? y2 : -y2;
	y2 = (-res->q / 2 - sqrt(res->s) == 0) ? 0 : y2;
	res->x_re[0] = y1 + y2 - b / a / 3;
	res->x_re[1] = -(y1 + y2) / 2 - b / a / 3;
	res->x_re[2] = -(y1 + y2) / 2 - b / a / 3;
	res->x_im[1] = (y1 - y2) * sqrt(3) / 2;
	res->x_im[2] = -(y1 - y2) * sqrt(3) / 2;
}

t_pol		polinom_2_degr(double a, double b, double c)
{
	t_pol	res;

	res.deg = 2;
	res.s = b * b - 4 * a * c;
	if (res.s < 0)
	{
		res.x_re[0] = -b / 2.0 / a;
		res.x_re[1] = -b / 2.0 / a;
		res.x_im[0] = sqrt(-res.s) / 2.0 / a;
		res.x_im[1] = -sqrt(-res.s) / 2.0 / a;
	}
	else
	{
		res.x_re[0] = (-b - sqrt(res.s)) / 2.0 / a;
		res.x_re[1] = (-b + sqrt(res.s)) / 2.0 / a;
		res.x_im[0] = 0;
		res.x_im[1] = 0;
	}
	return (res);
}

t_pol		polinom_3_degr(double a, double b, double c, double d)
{
	double	y1;
	t_pol	r;

	r.deg = 3;
	r.s = (4 * pow(3 * a * c - b * b, 3) + pow(2 * pow(b, 3) -
			9 * a * b * c + 27 * a * a * d, 2)) / 2916.0 / pow(a, 6);
	r.p = (3 * a * c - b * b) / 3 / pow(a, 2);
	r.q = (2 * pow(b, 3) - 9 * a * b * c + 27 * a * a * d) / pow(a, 3) / 27;
	r.x_im[0] = 0;
	r.x_im[1] = 0;
	r.x_im[2] = 0;
	if (r.s < 0)
		negative_discr(&r, a, b);
	else if (r.s > 0)
		pozitive_discr(&r, a, b);
	else
	{
		y1 = (r.q == 0) ? 0 : exp(log(fabs(-r.q / 2)) / 3);
		y1 = (r.q < 0) ? y1 : -y1;
		r.x_re[0] = 2 * y1 - b / a / 3;
		r.x_re[1] = -y1 - b / a / 3;
		r.x_re[2] = -y1 - b / a / 3;
	}
	return (r);
}

t_pol		polinom_4_degr(double b, double c, double d, double e)
{
	t_pol	r;
	t_pol	p;
	double	a;
	double	z;

	a = 1;
	r.deg = 4;
	r.p = (8 * a * c - 3 * b * b) / 8.0 / a / a;
	r.q = (8 * a * a * d + pow(b, 3) - 4 * a * b * c) / pow(a, 3) / 8;
	r.r = (16 * a * b * b * c - 64 * a * a * b * d - 3 * pow(b, 4) + 256 *
			pow(a, 3) * e) / 256.0 / pow(a, 4);
	p = polinom_3_degr(1, r.p, pow(r.p, 2) / 4 - r.r, -pow(r.q, 2) / 8);
	z = 2 * p.x_re[0];
	p = polinom_2_degr(1, -sqrt(z), (r.p + z + r.q / sqrt(z)) / 2);
	r.x_re[0] = p.x_re[0] - b / (4 * a);
	r.x_re[1] = p.x_re[1] - b / (4 * a);
	r.x_im[0] = p.x_im[0];
	r.x_im[1] = p.x_im[1];
	p = polinom_2_degr(1, sqrt(z), (r.p + z - r.q / sqrt(z)) / 2);
	r.x_re[2] = p.x_re[0] - b / (4 * a);
	r.x_re[3] = p.x_re[1] - b / (4 * a);
	r.x_im[2] = p.x_im[0];
	r.x_im[3] = p.x_im[1];
	return (r);
}
