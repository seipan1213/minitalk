/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:04:20 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/10 22:17:22 by sehattor         ###   ########.fr       */
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

volatile sig_atomic_t g_received_signal;

/* utils.c */
/* print arg and exit STDERR_FILENO */
void print_err_exit(char *str_err);
/* str convert to pid and check */
pid_t str_to_pid(char *str);
void	print_pid(void);

#endif
