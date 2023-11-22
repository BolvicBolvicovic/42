//METS UN HEADER

#include "minitalk.h"

void	sigusr_handler(int signo, siginfo_t *info, void *context)
{
	static int				bit = -1;
	static unsigned char	i;

	(void)context;
	if (bit < 0)
		bit = 7;
	if (signo == SIGUSR1)
		i |= (0x01 << bit);
	bit--;
	if (bit < 0 && i)
	{
		ft_printf("%c", i);
		i = 0;	
		if (kill(info->si_pid, SIGUSR2) == -1)
			sig_error("Server failed to send SIGUSR2.\n");
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		sig_error("Server failed to send SIGUSR1.\n");
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &sigusr_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		sig_error("Failed to change SIGUSR1's behavior.\n");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		sig_error("Failed to change SIGUSR2's behavior.\n");
}

int	main(int argc, char **argv)
{
	pid_t   server_pid;

	(void)argv;
	if (argc != 1)
		return (ft_error("Error: do not put any argument!\n"));
	server_pid = getpid();
	ft_printf("Server is running !\nServer PID: %d\n", server_pid);
	while(argc == 1)
		config_signals();
	return (0);
}
