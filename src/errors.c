/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:24:32 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:07:16 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <SDL.h>
#include "rt/errors.h"

void	print_error_and_exit(const char *error_text, Uint8 sdl)
{
	const char *buf;

	ft_putstr(error_text);
	if (sdl == 1)
	{
		buf = SDL_GetError();
		ft_putstr(buf);
	}
	write(1, "\n", 1);
	SDL_Quit();
	exit(1);
}

void	rtv_error(t_error error_code)
{
	if (error_code == usage_error)
		print_error_and_exit("Usage: ./RTv1 <scene>", 0);
	else if (error_code == malloc_error)
		print_error_and_exit("Malloc allocation error.", 0);
	else if (error_code == sdl_init_error)
		print_error_and_exit("SDL error: init. ", 1);
	else if (error_code == sdl_window_error)
		print_error_and_exit("SDL error: window. ", 1);
	else if (error_code == sdl_renderer_error)
		print_error_and_exit("SDL error: renderer. ", 1);
	else if (error_code == file_close_error)
		print_error_and_exit("File close error: file. ", 0);
	else if (error_code == line_error)
		print_error_and_exit("Line error: file. ", 0);
	else if (error_code == file_open_error)
		print_error_and_exit("File open error: file. ", 0);
	else if (error_code == gnl_error_code)
		print_error_and_exit("GNL error: file. ", 0);
	else if (error_code == parse_error)
		print_error_and_exit("Parsing error: file. ", 0);
	else
		print_error_and_exit("No such error code.", 0);
}
