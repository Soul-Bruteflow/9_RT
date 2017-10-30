/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:15 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 16:02:35 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV_DEFINES_H
# define _RTV_DEFINES_H

/*
** Window size, and bits per pixel
*/
# define WIDTH 1024
# define HEIGHT 768
# define BITS 4

/*
** Allocation
*/
# define ONE_STR 1

# define PI 3.14159265359f

/*
** Parse defines
*/
# define V_MIN -10000
# define V_MAX 10000
# define S_MIN 1
# define S_MAX 10
# define F_MIN 1
# define F_MAX 90
# define C_MIN 0
# define C_MAX 1
# define R_MIN 0.01
# define R_MAX 0.99
# define M_MIN 0
# define M_MAX 10
# define SPR_MIN 1
# define SPR_MAX 1000
# define A_MIN 1
# define A_MAX 90
# define MIN(a,b) (((a) < (b)) ? (a) : (b))

#endif
