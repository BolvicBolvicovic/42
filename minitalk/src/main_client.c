//METS TON HEADER

#include "minitalk.h"

void	args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		sig_error("Invalid number of arguments.\n");
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			sig_error("Invalid PID.");
	if (*argv[2] == 0)
		sig_error("Invalid message (empty).\n");
}

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Character recieved!\n");
}

void	send_char_to_server(pid_t pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		c <<= 1;
	}
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &confirm_msg;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		sig_error("Failed to change SIGUSR1's behavior.\n");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		sig_error("Failed to change SIGUSR2's behavior.\n");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = -1;
	args_check(argc, argv);
	pid = ft_atoi(argv[1]);
	config_signals();
	while (argv[2][++i])
		send_char_to_server(pid, argv[2][i]);
	send_char_to_server(pid, '\n');
	return (0);
}
