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

#include "minitalk.h"

int	g_char = 0;

void	error(void)
{
	ft_printf("Program was failed.\n");
	exit(1);
}

static void	output(void)
{
	if(write(1, &g_char, 1) == -1) error();
	g_char = 0;
}

static void	signal_handler(int signum)
{
	g_char = g_char << 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	else if (signum == SIGUSR2)
		;
	else
		error();
}

int	main(void)
{
	int	n;

	ft_printf("Server pid: %d\n", getpid());
	if (signal(SIGUSR1, signal_handler) == SIG_ERR) error();
	if (signal(SIGUSR2, signal_handler) == SIG_ERR) error();
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
/*if error happens in functions 
write	-1
getpid	no return >> wrong with %d in ft_printf
signal	SIG_ERR
pause	always returns -1(no error)

ft_printf	no deal
error	no deal
output	error()
signal_handler	error()
main	error()
*/