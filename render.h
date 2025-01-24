/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sai <aben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:53:54 by aben-sai          #+#    #+#             */
/*   Updated: 2025/01/24 12:05:54 by aben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fractal.h"

void	set_pixel_color(t_engine *engine, int x, int y, int color);
void	change_color(int key, t_engine *engine);
void	change_view(int key, t_engine *engine);
int		calc_fractal(t_fractal *fract, t_complex *c, int x, int y);
void	draw_fractal(t_engine *engine);

#endif
