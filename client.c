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

#include "minitalk.h"

void	error(void)
{
	ft_printf("Program was failed.\n");
	exit(1);
}

static void	send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
		{
			if(kill(pid, SIGUSR1) == -1)
				error();
		}
		else
		{
			if(kill(pid, SIGUSR2) == -1) 
				error();
		}
		digit--;
		if(usleep(100) == -1) error();
	}
}

static void	send_str(const pid_t pid, char *str)
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

/*if error happans in function
kill	-1
usleep	-1

ft_printf	no deal
ft_atoi	?
send_str	error()
send_char	error()
main
*/