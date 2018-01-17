typedef	struct		s_memPlus_slot
{
  char 						regName[64];
  int							seqId;
  int							regSize;
  void						*mem;
  char						active;
}									t_memPlus_slot;

typedef	struct		s_memPlus_env
{
  t_memPlus_slot		*slots;
  int 						numSlots;
  int							bytesInUse;
  int							byteLimit;
  int							regionLimit;
  int							bytesFree;
  int							slotsFree;
}									t_memPlus_env;

void	memPlus_init(t_memPlus_env *env, int region_limit, int byte_limit);
void	*memPlus_alloc(t_memPlus_env *env, int regSize, char *regName);

