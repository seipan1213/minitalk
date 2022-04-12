/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sub_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:45:02 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/12 19:39:46 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern volatile sig_atomic_t	g_received_signal;

void	sig_handler_client(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_received_signal = signal;
}

pid_t	str_to_pid(char *str)
{
	pid_t	pid;

	pid = ft_atoi(str);
	if (!check_str_to_int(str) || pid < PID_MIN || PID_MAX < pid)
		print_err_exit(MSG_PID_ERR);
	else if (kill(pid, 0) == -1)
		print_err_exit(MSG_PID_FALIED);
	return (pid);
}
