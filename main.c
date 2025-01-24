/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sai <aben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:12:30 by aben-sai          #+#    #+#             */
/*   Updated: 2025/01/24 12:16:52 by aben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_engine.h"
#include "render.h"
#include "events.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc != 2)
		show_help();
	init_engine(&engine, argv[1]);
	draw_fractal(&engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_mouse_hook(engine.window, on_mouse_hook_event, &engine);
	mlx_hook(engine.window, 6, 1L << 6, on_mousemove_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
