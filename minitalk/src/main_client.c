//METS TON HEADER

#include "minitalk_c.h"

void send_char_to_server(pid_t server_pid, char c)
{
	for (int i = 0; i < 8; ++i)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			sleep(10000);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_error("Wrong number of arguments.\n \
					It should be <Message PID>"));
	pid = ft_atoi(argv[2]);
	for (int i = 0; argv[1][i]; ++i)
		send_char_to_server(pid, argv[1][i]);
	send_char_to_server(pid, '\0');
	return (0);
}
