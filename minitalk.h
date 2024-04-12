#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_kill(int pid, char *argc);
void	ft_action(int signal);
int		ft_atoi(const char *str);

void	ft_putchar(char c, int *result);
void	ft_putstr(char *s, int *result);
void	ft_putnbr(int n, int *result);
void	ft_checker(va_list *p, char c, int *result);
int		ft_printf(const char *s, ...);


#endif