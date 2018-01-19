#include "memPlus.h"

/*
**RETURNS -1 IN CASE OF FAILURE, OTHERWISE IT RETURNS THE SEQUENTIAL ID
**OF THE JUST ALLOCATED SEGMENT
*/
int	memPlus_allocRegion(MPenv *env, int regSize)
{
  int retCode;
  int counter;

  retCode = -1;
  counter = 0;
  if (env && regSize && env->bytesFree >= regSize)
    {
      while (counter < env->numSlots)
      {
        if (!env->slot[counter].mem && (env->slot[counter].mem = ft_memalloc(regSize)))
          {
            retCode = counter;
            return (retCode);
          }
        ++counter;
      }
    }
  return (retCode);
}

MPslot *memPlus_alloc(MPenv *env, int regSize, char *name)
{
  int retVal;

  retVal = -1;
  if (env && regSize)
    {
      retVal = memPlus_allocRegion(env, regSize);
      if (retVal >= 0)
      {
        if (name)
          ft_strlcat(env->slot[retVal].regName, name, 64);
        env->slot[retVal].regSize = regSize;
        env->slot[retVal].seqId = env->totalRegions;
        retVal = env->totalRegions;
        env->totalRegions += 1;
        env->bytesInUse += regSize;
        env->bytesFree -= regSize;
		return (env->slot + retVal);
      }
    }
  return (NULL);
}
