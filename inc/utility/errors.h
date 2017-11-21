/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:44:54 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 16:02:09 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV_ERROR_H
# define __RTV_ERROR_H

typedef enum		e_error
{
	usage_error,
	malloc_error,
	sdl_init_error,
	sdl_window_error,
	sdl_renderer_error,
	file_close_error,
	line_error,
	file_open_error,
	gnl_error_code,
	parse_error,
	number_of_errors
}					t_error;

/*
** Errors
*/
void				rtv_error(t_error error_code);
void				print_error_and_exit(const char *error_text, Uint8 sdl);

#endif
