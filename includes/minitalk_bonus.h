/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:04:20 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/10 23:44:27 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include "../libft/libft.h"
#include <sys/types.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

#define MSG_ARGS_ERR "---Invalid argument---"
#define MSG_PID_ERR "---Invalid pid---"
#define MSG_PID_FALIED "---Connection failed---"
#define MSG_PID_SUCCESS "---Connection success---"
#define MSG_SIG_ERR "---Signal Error---"

#define PID_MAX INT_MAX
#define PID_MIN 0
#define SIG_INTAVAL 100
#define INT_MAX_STR "2147483647"
#define TIME_OUT_LIMIT 1000
#define TIME_OUT_INTAVAL 100

#define SIG_INIT -1

volatile sig_atomic_t g_received_signal;
volatile sig_atomic_t g_received_signal;

typedef void(*t_sigaction_handler)(int, siginfo_t *, void *);

/* utils.c */
/* print arg and exit STDERR_FILENO */
void print_err_exit(char *str_err);
/* str convert to pid and check */
pid_t str_to_pid(char *str);
void	set_signal_handler(t_sigaction_handler hander);
void	sig_handler_server(int signal, siginfo_t *info, void *ucontext);
bool	is_timeout(int time_limit);
void	print_pid(void);

#endif
