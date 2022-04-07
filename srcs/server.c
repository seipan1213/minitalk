/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:29:50 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/07 23:35:53 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void set_signal_handler(sig_t hoge)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler= hoge;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_err_exit(MSG_SIG_ERR);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_err_exit(MSG_SIG_ERR);
}

void print_pid(void)
{
	pid_t pid;

	pid = getpid();
	ft_putstr_fd("PID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

void	set_signal(int signal)
{
	g_received_signal = signal;
}

void	receive_char()
{
	static int	bit_shift;
	static char	put_c;

	if (g_received_signal == SIGUSR1)
		put_c |= 1 << bit_shift;
	if (bit_shift == CHAR_BIT)
	{
		ft_putchar_fd(put_c, STDOUT_FILENO);
		bit_shift = 0;
		put_c = 0;
	}
}

void	receive_message()
{
	while (1)
	{
		pause();
		receive_signal();
	}
}

int main(void)
{
	print_pid();
	set_signal_handler(set_signal);
	receive_message();
}