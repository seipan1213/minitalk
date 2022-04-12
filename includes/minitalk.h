/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:04:20 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/12 19:36:47 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <sys/types.h>
# include <signal.h>
# include <limits.h>
# include <errno.h>
# include <unistd.h>
# include <stdbool.h>

# define MSG_ARGS_ERR "---Invalid argument---"
# define MSG_PID_ERR "---Invalid pid---"
# define MSG_PID_FALIED "---Connection failed---"
# define MSG_PID_SUCCESS "---Connection success---"
# define MSG_SIG_ERR "---Signal Error---"

# define PID_MAX INT_MAX
# define PID_MIN 0
# define SIG_INTAVAL 100
# define INT_MAX_STR "2147483647"

volatile sig_atomic_t	g_received_signal;

/* client */
void	send_signal(pid_t pid, int signal_type);
void	send_char(pid_t pid, char c);
void	send_message(pid_t pid, char *message);

/* server */
void	set_signal_handler(sig_t hander);
void	set_signal(int signal);
void	receive_char(void);
void	receive_message(void);

/* utils */
void	print_pid(void);
void	print_err_exit(char *str_err);
bool	check_str_to_int(char *str);
pid_t	str_to_pid(char *str);

#endif
