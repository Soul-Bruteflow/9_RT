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
** Number of pthreads
*/
# define NB_THREAD	4
/*
** Window size, and bits per pixel
*/
# define WIDTH		800
# define HEIGHT		600
# define BITS		4
/*
** Allocation
*/
# define PI			3.14159265359f
# define TWO_PI		6.28318530718f
# define HALF_PI	1.57079632679f
# define MAX_LEN	10000
/*
** Mouse
** V_C_SENS/H_C_SENS    Default mouse sensitivity
** V_SENS/H_SENS        Default mouse sensitivity of the camera
** CL_REL_N/CL_REL_P    Mouse relative position clamp values (N - negative)
*/
# define V_C_SENS	0.006f
# define H_C_SENS	0.008f
# define V_SENS		0.010f
# define H_SENS		0.012f
# define CL_REL_N   -350
# define CL_REL_P   350


/*
** Parse defines
*/
# define V_MIN		-10000
# define V_MAX		10000
# define S_MIN		0
# define S_MAX		20
# define F_MIN		1
# define F_MAX		90
# define C_MIN		0
# define C_MAX		1
# define P_MIN		0.01
# define P_MAX		9.99
# define R_MIN		0.01
# define R_MAX		0.99
# define N_MIN		0.01
# define N_MAX		2.99
# define M_MIN		0
# define M_MAX		10
# define A_MIN		1
# define A_MAX		90
# define            SPR_MIN 1
# define            SPR_MAX 1000
# define MIN(a,b) (((a) < (b)) ? (a) : (b))

#endif
