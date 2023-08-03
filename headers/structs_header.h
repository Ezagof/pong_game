/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <ezagof@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:30:50 by aautin            #+#    #+#             */
/*   Updated: 2023/08/03 21:14:21 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_HEADER_H
# define STRUCTS_HEADER_H

# include <ncurses.h>

typedef struct s_file {
	char	*content;
	char	*name;
	int		size;
	int		descriptor;
	int		lines_nb;
}	t_file;

typedef struct s_ball {
	char	c;
	int		x;
	int		y;
	int		vx;
	int		vy;
}	t_ball;

typedef struct s_players {
	char	c;
	int		score1;
	int		x1;
	int		y1;
	int		score2;
	int		x2;
	int		y2;
	int		ball_returns_nb;
}	t_players;

typedef struct s_screen {
	WINDOW		*win;
	int			x;
	int			y;
}	t_screen;

typedef struct s_strpart {
	int		from;
	int		to;
	char	*str;
}	t_strpart;

#endif