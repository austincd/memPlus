#include "memPlus.h"

void	memPlus_freeRegion(MPslot *region)
{
  if (region && region->mem && !region->active)
    {
      ft_bzero(region->mem, region->regSize);
      free(region->mem);
      ft_bzero(region, sizeof(MPslot));
    }
}

void	memPlus_freeRegionsLargerThan(MPenv *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
		while (counter < env->numSlots)
        {
          if (env->slot[counter].regSize > bytes)
            memPlus_freeRegion(env->slot + counter);
          ++counter;
        }
    }
}

void	memPlus_freeRegionsSmallerThan(MPenv *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
		while (counter < env->numSlots)
        {
          if (env->slot[counter].regSize < bytes)
            memPlus_freeRegion(env->slot + counter);
          ++counter;
        }
    }
}

void	memPlus_freeAll(MPenv *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->numSlots)
        {
          memPlus_freeRegion(env->slot + counter);
          ++counter;
        }
    }
}

void	memPlus_free(MPenv *env, int seqId)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->numSlots)
        {
          if (env->slot[counter].seqId == seqId)
            memPlus_freeRegion(env->slot + counter);
          ++counter;
        }
    }
}
