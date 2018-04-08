/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polinoms.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:20:57 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 15:20:58 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLINOMS_H
# define POLINOMS_H

/*
** polinome representation
*/
typedef struct	s_pol
{
	int			deg;
	double		s;
	double		p;
	double		q;
	double		r;
	double		f;
	double		x_im[4];
	double		x_re[4];
}				t_pol;

t_pol			polinom_2_degr(double a, double b, double c);
t_pol			polinom_3_degr(double a, double b, double c, double d);
t_pol			polinom_4_degr(double b, double c, double d, double e);

#endif
