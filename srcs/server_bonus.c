/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:29:50 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/11 00:07:22 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_received_signal;

void	sig_handler_server(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_received_signal == SIG_INIT)
	{
		g_received_signal = info->si_pid;
	}
	else
	{
		g_received_signal = signal;
	}
}

void	receive_char(void)
{
	static int	bit_shift;
	static char	put_c;

	if (g_received_signal == SIGUSR2)
		put_c |= 1 << bit_shift;
	bit_shift++;
	if (bit_shift == CHAR_BIT)
	{
		ft_putchar_fd(put_c, STDOUT_FILENO);
		bit_shift = 0;
		put_c = 0;
	}
}

int	receive_client_pid(void)
{
	int	cli_pid;

	cli_pid = g_received_signal;
	kill(cli_pid, SIGUSR1);
	g_received_signal = 0;
	return (cli_pid);
}

void	receive_message(void)
{
	int		cli_pid;

	g_received_signal = SIG_INIT;
	pause();
	cli_pid = receive_client_pid();
	while (1)
	{
		pause();
		receive_char();
		g_received_signal = 0;
		kill(cli_pid, SIGUSR1);
	}
}

int	main(void)
{
	print_pid();
	set_signal_handler(sig_handler_server);
	receive_message();
}
