/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:45:02 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/10 21:59:30 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signal(pid_t pid, int signal_type)
{
	if (signal_type == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_char(pid_t pid, char c)
{
	int	bit_shift;
	int	signal_type;

	bit_shift = 0;
	while (bit_shift < CHAR_BIT)
	{
		signal_type = (c >> bit_shift) & 1;
		send_signal(pid, signal_type);
		bit_shift++;
		usleep(SIG_INTAVAL);
	}
}

void	send_client_pid(pid_t pid)
{
	kill(pid, SIGUSR1);
	if (is_timeout(TIME_OUT_LIMIT) == true)
	{
		print_err_exit(MSG_SIG_ERR);
	}

}

void	send_message(pid_t pid, char *message)
{
	int	msg_i;

	msg_i = 0;
	send_client_pid(pid);
	while (message[msg_i] != '\0')
	{
		send_char(pid, message[msg_i]);
		msg_i++;
	}
	ft_putendl_fd(MSG_PID_SUCCESS, STDOUT_FILENO);
}

void	set_client_signal(int signal)
{
	g_received_client_signal = signal;
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		print_err_exit(MSG_ARGS_ERR);
	pid = str_to_pid(argv[1]);
	set_signal_handler(set_client_signal);
	send_message(pid, argv[2]);
}
