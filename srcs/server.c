/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:29:50 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/10 21:02:26 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_signal_handler(sig_t hander)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = hander;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_err_exit(MSG_SIG_ERR);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_err_exit(MSG_SIG_ERR);
}

void	set_signal(int signal)
{
	g_received_signal = signal;
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

void	receive_message(void)
{
	while (1)
	{
		pause();
		receive_char();
	}
}

int	main(void)
{
	print_pid();
	set_signal_handler(set_signal);
	receive_message();
}
