#include "memPlus.h"

void	memPlus_killRegion(MPslot *region)
{
  if (region)
    {
      if (region->mem)
	  {
		ft_bzero(region->mem, region->regSize);
        free(region->mem);
	  }
      ft_bzero(region, sizeof(MPslot));
    }
}

void	memPlus_killRegionsLargerThan(MPenv *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->numSlots)
        {
          if (env->slot[counter].regSize > bytes)
            memPlus_killRegion(env->slot + counter);
          ++counter;
        }
    }
}

void	memPlus_killRegionsSmallerThan(MPenv *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->numSlots)
        {
          if (env->slot[counter].regSize < bytes)
            memPlus_killRegion(env->slot + counter);
          ++counter;
        }
    }
}

void	memPlus_killAll(MPenv *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->numSlots)
        {
          memPlus_killRegion(env->slot + counter);
          ++counter;
        }
    }
}

void	memPlus_kill(MPenv *env, int seqId)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->numSlots)
        {
          if (env->slot[counter].seqId == seqId)
            memPlus_killRegion(env->slot + counter);
          ++counter;
        }
    }
}
