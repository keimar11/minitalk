/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitakah <keitakah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:32:58 by keitakah          #+#    #+#             */
/*   Updated: 2023/07/19 13:32:58 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/libftprintf.h"
#include "ft_printf/libft/libft.h"

int	g_char = 0;

void	output(void)
{
	write(1, &g_char, 1);
	g_char = 0;
}

void	signal_handler(int signum)
{
	g_char = g_char << 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	else if (signum == SIGUSR2)
		;
}

int	main(void)
{
	int	n;

	ft_printf("Server pid: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		n = 0;
		while (n < 8)
		{
			pause();
			n++;
		}
		output();
	}
}

// pid_t: intと同義