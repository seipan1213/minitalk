/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:02:55 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/07 23:35:45 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_err_exit(char *str_err)
{
	ft_putendl_fd(str_err, STDERR_FILENO);
	exit (1);
}


pid_t	str_to_pid(char	*str)
{
	pid_t	pid;

	pid = ft_atoi(str);// TODO: INT超えた場合のエラー処理ができてない CMP?
	if (pid < PID_MIN || PID_MAX < pid)
		print_err_exit(MSG_PID_ERR);
	else if (kill(pid, 0) == -1)
		print_err_exit(MSG_PID_FALIED);
	return (pid);
}