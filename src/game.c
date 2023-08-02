/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by yahan             #+#    #+#             */
/*   Updated: 2023/08/02 20:32:59 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	update_window(t_screen gscr, t_ball ball, t_player p1, t_player p2)
{
	clear();
	wprint_ball(gscr.win, ball);
	wprint_bar(gscr.win, p1);
	wprint_bar(gscr.win, p2);
	wprint_wall_board(gscr.win, gscr.y, gscr.x);
	refresh();
	wrefresh(gscr.win);
}

void	init_gscr(t_screen *gscr, t_screen *stsc)
{
	gscr->x = stsc->x;
	gscr->y = stsc->y;
	gscr->win = newwin(stsc->y, stsc->x, 0, 0);
}

void	init_game(t_screen gscr, t_ball *ball, t_player *p1, t_player *p2)
{
	srand(time(NULL));
	ball->x = gscr.x / 2;
	ball->y = (gscr.y - 2) / 2;
	ball->vx = 1 + (rand() % 2) * (-2);
	ball->vy = 0;
	p1->x = 1;
	p1->y = (gscr.y - 2) / 2 - BAR_LEN / 2;
	p1->score = 0;
	p2->x = gscr.x - 2;
	p2->y = (gscr.y - 2) / 2 - BAR_LEN / 2;
	p2->score = 0;
	update_window(gscr, *ball, *p1, *p2);
	mvwprintw(gscr.win, gscr.y - 2, 0, "Press any key to start...");
	refresh();
	wrefresh(gscr.win);
	getch();
}

void	start_game(t_screen stsc)
{
	int			ch;
	t_ball		ball;
	t_player	player1;
	t_player	player2;
	t_screen	gscr;

	init_gscr(&gscr, &stsc);
	init_game(gscr, &ball, &player1, &player2);
	nodelay(gscr.win, TRUE);
	nodelay(stsc.win, TRUE);
	while (1)
	{
		ch = getch();
		if (ch)
			move_player(ch, &player1, &player2, gscr);
		if (ball.y == 1 || ball.y == gscr.y - 4) //collide with wall
			ball.vy *= -1;
		if ((ball.x == player1.x + 1 && ball.y >= player1.y && ball.y <= player1.y + BAR_LEN) //collide with player
			|| (ball.x == player2.x - 1 && ball.y >= player2.y && ball.y <= player2.y + BAR_LEN))
		{
			ball.vy = (rand() % 3 - 1) * rand() % 3;
			ball.vx *= -1;
		}
		ball.x += ball.vx;
		ball.y += ball.vy;
		update_window(gscr, ball, player1, player2);
		usleep(DELAY);
	}
	nodelay(gscr.win, FALSE);
	nodelay(stsc.win, FALSE);
	delwin(gscr.win);
}
