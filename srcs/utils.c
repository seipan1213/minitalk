/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:02:55 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/12 20:58:16 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern volatile sig_atomic_t	g_received_signal;

void	set_signal_handler(t_sigaction_handler hander)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = hander;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_err_exit(MSG_SIG_ERR);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_err_exit(MSG_SIG_ERR);
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

void	print_err_exit(char *str_err)
{
	ft_putendl_fd(str_err, STDERR_FILENO);
	exit(1);
}

bool	check_str_to_int(char *str)
{
	int		str_len;
	bool	is_over_int;

	str_len = ft_strlen(str);
	is_over_int = (str_len < 10 || !ft_strncmp(str, INT_MAX_STR, str_len));
	if (is_over_int)
	{
		return (true);
	}
	return (false);
}

bool	is_timeout(int time_limit)
{
	while (time_limit--)
	{
		if (g_received_signal)
		{
			return (false);
		}
		usleep(TIME_OUT_INTAVAL);
	}
	return (true);
}
