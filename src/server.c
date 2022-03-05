#include <minitalk.h>

void    print_byte(int bit, int pid)
{
    static unsigned int c = 0;
    static int          n_bits = 0;

    if (pid <= 0)
        return ;
    c *= 2;
    if (bit == 1)
        c += 1;
    n_bits++;
    if (n_bits >= 8)
    {
        //ft_printf("%d] %c -> %d\n", bit, (char) c, pid);
        ft_printf("%c", (char) c);
        if (c == 0)
        {
            ft_printf("It happened again...\n");
            exit(0);
        }
        n_bits = 0;
        c = 0;
    }/* else {
        if (n_bits == 1)
            ft_printf("[");
        ft_printf("%d", bit);
    }*/
    kill(pid, SIGUSR2);
}

// USR1 => 30
// USR2 => 31
void	action(int sig, siginfo_t *info, void *idk)
{
    int pid;

    pid = info->si_pid;
    if (sig == SIGUSR1)
        print_byte(0, pid);
    else if (sig == SIGUSR2)
        print_byte(1, pid);
    (void) idk;
}

int main(void)
{
    struct sigaction	sig_info;

	ft_printf("Server PID: %d\n", getpid());
	sig_info.sa_sigaction = action;
	sig_info.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig_info, 0);
	sigaction(SIGUSR2, &sig_info, 0);
    while (1)
        pause();
}

