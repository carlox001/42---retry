/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:55:55 by czerini           #+#    #+#             */
/*   Updated: 2024/05/22 18:04:32 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 7;

	(void)context;
	if (signal == SIGUSR2)
		bit |= (1 << i);
	i--;
	if (i < 0)
	{
		ft_printf("%c", bit);
		bit = 0;
		i = 7;
	}
	usleep(1);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	if (argc > 1)
	{
		ft_printf("Wrong number of arguments\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\nwaiting...\n", pid);
	sig.sa_sigaction = handle_signal;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
