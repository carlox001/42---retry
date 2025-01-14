/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:19:47 by czerini           #+#    #+#             */
/*   Updated: 2024/05/22 18:04:18 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_signal(char signal, int pid)
{
	int	bit;
	int	sig;

	bit = 0;
	while (bit < 8)
	{
		if (signal & 128)
			sig = SIGUSR2;
		else
			sig = SIGUSR1;
		kill(pid, sig);
		signal <<= 1;
		bit++;
		pause();
		usleep(1);
	}
}

static void	nothing(int s)
{
	(void)s;
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	signal(SIGUSR1, nothing);
	i = 0;
	if (argc != 3)
	{
		ft_printf("client: invalid arguments\n");
		ft_printf("correct format [./%S SERVER_PID SIGNUM\n]", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: correct format [./%S SERVER_PID SIGNAL\n", argv[0]);
		return (1);
	}
	while (argv[2][i])
	{
		send_signal(argv[2][i], pid);
		i++;
	}
	send_signal(argv[2][i], pid);
	ft_printf("Messaggio ricevuto\n");
	return (0);
}
