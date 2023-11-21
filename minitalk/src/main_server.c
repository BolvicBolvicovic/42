//METS UN HEADER

#include "minitalk.h"

void	sigusr_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		ft_printf("Server received SIGUSR1 from client\n");
	}
	if (signo == SIGUSR2)
	{
		ft_printf("Server received SIGUSR2 from client\n");
	}
}

int	start_serv(struct sigaction sa)
{
	sa.sa_handler = sigusr_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	return (0);
}

int	main()
{
	struct sigaction	sa;

	if (start_serv(sa))
		return (ft_error("Server could not start !"));
	server_pid = getpid();
	ft_printf("Server is running !\nServer PID: %d\n", server_pid);
	while(1)
	{
		continue ;
	}
	return (0);
}
