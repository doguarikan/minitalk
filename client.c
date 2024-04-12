#include "minitalk.h"

void ft_kill(int pid, char *argc)
{
	int i;
	int bit;

	i = 0;
	if(!argc || !argc[i])
		return ;
	while(argc[i])
	{
		bit = 7;
		while(bit>=0)
		{
			if((argc[i]>>bit) & 1) // eğer en soldaki en soldaki bit 1 ise sigusr1 sinyalini yollar
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(100); //sleep saniye için çalışır usleep mikrosaniye içim, ama sleep(0.0001); yaparsak bile doğru çalışmaz
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_kill(pid, argv[2]);
	}
	else
	{
		ft_printf("Error!\n");
		exit(0);
	}

	return (0);
}