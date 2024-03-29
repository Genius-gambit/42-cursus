/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:21:55 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 20:28:23 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == ESC)
	{
		free(vars->map);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		if (vars->collectible == vars->collected_tokens)
			ft_putstr_fd("Game Over\n", 1);
		write(1, "\nDead\n", 5);
		exit (0);
	}
	else if (keycode == W)
		player_up_image(vars);
	else if (keycode == S)
		player_down_image(vars);
	else if (keycode == D)
		player_right_image(vars);
	else if (keycode == A)
		player_left_image(vars);
	if (vars->collected_tokens == vars->collectible)
		open_exit(vars);
	print_moves(vars);
	return (1);
}

int	del_game(t_data *vars)
{
	key_hook(ESC, vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	vars;
	int		fd;

	ft_init(&vars);
	if (argc == 2 && file_check(argv))
	{
		fd = open(argv[1], O_RDONLY);
		vars.map = map_work(fd, &vars);
		if (!vars.map)
			exit(1);
		vars.mlx = mlx_init();
		map_init(&vars);
		grass(&vars);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, 1L << 17, del_game, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
