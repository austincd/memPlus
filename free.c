#include "memPlus.h"

void	memPlus_freeRegion(t_memPlus_reg *region)
{
  if (region && region->mem && !region->active)
    {
      free(region->mem);
      ft_bzero(region, sizeof(t_memPlus_reg));
    }
}

void	memPlus_freeRegionsLargerThan(t_memPlus_env *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          if (env->regions[counter].regSize > bytes)
            memPlus_freeRegion(env->regions + counter);
          ++counter;
        }
    }
}

void	memPlus_freeRegionsSmallerThan(t_memPlus_env *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          if (env->regions[counter].regSize < bytes)
            memPlus_freeRegion(env->regions + counter);
          ++counter;
        }
    }
}

void	memPlus_freeAll(t_memPlus_env *env, int bytes)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          memPlus_freeRegion(env->regions + counter);
          ++counter;
        }
    }
}

void	memPlus_free(t_memPlus_env *env, int seqId)
{
  int	counter;

  counter = 0;
  if (env)
    {
      while (counter < env->region_limit)
        {
          if (env->regions[counter].seqId = seqId)
            memPlus_freeRegion(env->regions + counter);
          ++counter;
        }
    }
}
