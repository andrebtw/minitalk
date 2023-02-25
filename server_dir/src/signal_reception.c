#include "server.h"

extern int user_signal;

int	check_start(int end)
{
	static int i;
	static int byte;

	if (!i)
	{
		if (user_signal == SIGUSR1)
			byte = (byte << 0) + 0;
		else if (user_signal == SIGUSR2)
			byte = (byte << 0) + 1;
		i++;
	}
	else if (i < 8)
	{
		if (user_signal == SIGUSR1) {
			byte = (byte << 1) + 0;
		}
		else if (user_signal == SIGUSR2) {
			byte = (byte << 1) + 1;
		}
		i++;
	}
	if (end)
	{
		i = 0;
		byte = 0;
	}
	if (byte == 1 && i == 8)
		return (1);
	return (0);
}
