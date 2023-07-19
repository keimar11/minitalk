/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitakah <keitakah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:32:38 by keitakah          #+#    #+#             */
/*   Updated: 2023/07/19 13:32:38 by keitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./ft_printf/libftprintf.h"
#include "./ft_printf/libft/libft.h"

void	send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
		usleep(100);
	}
}

void	send_str(const pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\n');
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Please try again.\n");
		ft_printf("./client <pid_number> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
}

// argv[1]= "server PID"
// argv[2]= "strings"