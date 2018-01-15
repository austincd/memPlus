#include "memPlus.h"

void	memPlus_killRegion(t_memPlus_reg *region)
{
  if (region)
    {
      if (region->mem)
        kill(region->mem);
      ft_bzero(region, sizeof(t_memPlus_reg));
    }
}

void	memPlus_killRegionsLargerThan(t_memPlus_env *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          if (env->regions[counter].regSize > bytes)
            memPlus_killRegion(env->regions + counter);
          ++counter;
        }
    }
}

void	memPlus_killRegionsSmallerThan(t_memPlus_env *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          if (env->regions[counter].regSize < bytes)
            memPlus_killRegion(env->regions + counter);
          ++counter;
        }
    }
}

void	memPlus_killAll(t_memPlus_env *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          memPlus_killRegion(env->regions + counter);
          ++counter;
        }
    }
}

void	memPlus_kill(t_memPlus_env *env, int seqId)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          if (env->regions[counter].seqId = seqId)
            memPlus_killRegion(env->regions + counter);
          ++counter;
        }
    }
}
