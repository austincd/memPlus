#include "memPlus.h"

void	memPlus_diag(MPenv *env, int fd)
{
  int counter;

  counter = 0;
  if (env && env->numSlots && fd >= 0)
    {
      while (counter < env->numSlots)
      {
        ft_putendl_fd(env->slot[counter].regName, fd);
        ++counter;
      }
	}
}
