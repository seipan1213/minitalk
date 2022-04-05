/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:45:02 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/05 15:28:09 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	main (int argc, char **argv) {
	pid_t pid;

	if (argc != 3)
		print_err_exit(MSG_ARGS_ERR);
	pid = str_to_pid(argv[1]);
}