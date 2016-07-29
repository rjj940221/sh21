/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:48:38 by rojones           #+#    #+#             */
/*   Updated: 2016/07/26 18:10:57 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_init_win(t_win *win)
{
	char	*buf;

	buf = NULL;
	tgetent(buf, getenv("TERM"));

	if ( ! isatty(STDOUT_FILENO) )
		return;

	/* Get terminal attributes and then determine if terminal */
	/* start and stop is enabled and if terminal is in        */
	/* canonical mode.                                        */
	else {
		if (tcgetattr(STDOUT_FILENO, &win->owin) != 0)
			ft_putstr_fd("error taking over terminal\n", 2);
		if (tcgetattr(STDOUT_FILENO, &win->nwin) != 0)
			ft_putstr_fd("error taking over terminal\n", 2);
		else
		{
			win->nwin.c_iflag |= IGNBRK;
			win->nwin.c_lflag |= ISIG;
			win->nwin.c_lflag &= ~(ICANON | ECHO);
			win->nwin.c_cc[VMIN] = 1;
			win->nwin.c_cc[VTIME] = 0;
			tcsetattr(STDOUT_FILENO, TCSANOW, &win->nwin);
		}
	}
}
