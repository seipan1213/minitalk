/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:02:55 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/10 22:16:21 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

bool	is_timeout(int time_limit)
{
	while (time_limit--)
	{
		if (g_received_client_signal == 1)
		{
			return (false);
		}
		usleep(SIG_INTAVAL);
	}
	return (true);
}