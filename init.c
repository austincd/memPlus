#include "memPlus.h"

int	memPlus_init(MPenv *env, int byteLimit, int reqSlots)
{
  int status;

  status = -1;
  if (env && reqSlots > 0)
    {
      ft_bzero(env, sizeof(MPenv));
      env->byteLimit = byteLimit;
      env->slot = ft_memalloc(reqSlots * sizeof(MPslot));
      if (env->slot)
        {
          env->numSlots = reqSlots;
          status = 1;
        }
    }
  return (status);
}
