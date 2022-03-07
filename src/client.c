/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <dangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:39:11 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/07 16:18:25 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	send_bit(int pid, char *message)
{
	static int		server_pid;
	static char		*full_message;
	static int		next_char = 0;
	static int		next_bit = 0;
	unsigned int	send;

	if (pid != -1)
		server_pid = pid;
	if (message != NULL)
		full_message = message;
	if (*(full_message + next_char) == '\0')
		exit(0);
	if (next_bit == 0)
		ft_printf("%s'%c'\t[", "\033[0;37m", *(full_message + next_char));
	send = (unsigned int) *(full_message + next_char);
	send = (send & (1 << (7 - next_bit))) >> (7 - next_bit);
	if (send % 2 == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	if (++next_bit >= 8)
	{
		next_bit = 0;
		next_char++;
	}
}

void	action(int sig, siginfo_t *info, void *idk)
{
	static int	bit_count = 0;

	bit_count++;
	ft_printf("%s ✓ %s", "\033[0;32m", "\033[0;37m");
	if (bit_count == 8)
	{
		ft_printf("%s]\n", "\033[0;37m");
		bit_count = 0;
	}
	usleep(500);
	send_bit(-1, NULL);
	(void) sig;
	(void) info;
	(void) idk;
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_info;

	if (argc != 3)
	{
		ft_printf("Usage: ./client SERVER_PID MESSAGE\n");
		exit(0);
	}
	ft_printf("This PID: %d\n", getpid());
	send_bit(ft_atoi(argv[1]), argv[2]);
	sig_info.sa_sigaction = action;
	sig_info.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sig_info, 0);
	while (1)
	{
		pause();
	}
}
