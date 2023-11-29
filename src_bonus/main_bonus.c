/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:00:05 by lcollado          #+#    #+#             */
/*   Updated: 2023/11/29 15:03:24 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = ft_new_window(game->mlx, game->map.size.x * TILE_SIZE,
			(game->map.size.y * TILE_SIZE) + 64, "SO_LONG");
	init_img(game);
	game->actions = (t_actions){false, false, false, false};
	init_enemies(game);
	draw_map(game, 1);
}

int	start(t_game *game, int argc, char *argv[])
{
	if (!valid_file(argc, argv[1]))
		return (0);
	map_init(game, argv[1]);
	if (!valid_map(game))
	{
		free_map(&game->map);
		return (0);
	}
	init(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.window.win, 2, 1L << 0, on_key_press, &game);
	mlx_hook(game.window.win, 3, 1L << 1, on_key_release, &game);
	mlx_loop(game.mlx);
	return (0);
}
