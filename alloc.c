#include "memPlus.h"

/*
**RETURNS -1 IN CASE OF FAILURE, OTHERWISE IT RETURNS THE SEQUENTIAL ID
**OF THE JUST ALLOCATED SEGMENT
*/
int	memPlus_allocRegion(t_memPlus_env *env, int regSize)
{
  int retCode;
  int counter;

  retCode = -1;
  counter = 0;
  if (env && regSize && env->bytes_free >= regSize)
    {
      while (counter < env->region_limit)
      {
        if (!env->regions[counter].mem && (env->regions[counter].mem = ft_memalloc(regSize)))
          {
            retCode = counter;
            return (retCode);
          }
        ++counter;
      }
    }
  return (retCode);
}

int memPlus_alloc(t_memPlus_env *env, int regSize, char *name)
{
  int retVal;

  retVal = -1;
  if (env && regSize)
    {
      retVal = memPlus_allocRegion(env, regSize);
      if (retVal >= 0)
      {
        if (name)
          ft_strlcat(env->regions[retVal].name, name, 64);
        env->regions[retVal].regSize = regSize;
        env->regions[retVal].seqId = env->num_regions;
        retVal = env->num_regions;
        env->num_regions += 1;
        env->bytes_used += regSize;
        env->bytes_free -= regSize;
      }
    }
  return (retVal);
}
