#include "memPlus.h"

int	memPlus_init(t_memPlus_env *env, int byteLimit, int reqSlots)
{
  int status;

  status = -1;
  if (env && reqSlots > 0)
    {
      ft_bzero(env, sizeof(t_memPlus_env));
      env->byteLimit = byteLimit;
      env->slots = ft_memalloc(reqSlots * sizeof(t_memPlus_slot));
      if (env->slots)
        {
          env->numSlots = reqSlots;
          status = 1;
        }
    }
  return (status);
}
