#include "../libft.h"

void  ft_putnbr_fd(int n, int fd)
{
  char  *nb;

  nb = ft_itoa(n);
  ft_putstr_fd(nb, fd);
}
