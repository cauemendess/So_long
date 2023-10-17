#include "so_long.h"

void	ft_error(char *message)
{	
	ft_putstr_fd(message, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}