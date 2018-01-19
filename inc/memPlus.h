#include "./libft/libft.h"

typedef	struct		s_memPlus_slot
{
  char 						regName[64];
  int							seqId;
  int							regSize;
  void						*mem;
  char						active;
}									MPslot;

typedef	struct		s_memPlus_env
{
  MPslot					*slot;
  int 						numSlots;
  int 						slotsInUse;
  int						totalRegions;
  int							bytesInUse;
  int							byteLimit;
  int							regionLimit;
  int							bytesFree;
  int							slotsFree;
}									MPenv;

int		memPlus_init(MPenv *env, int regionLimit, int byteLimit);
MPslot	*memPlus_alloc(MPenv *env, int regSize, char *regName);

