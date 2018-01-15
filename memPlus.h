typedef	struct		s_memPlus_reg
{
  char 						regName[64];
  int							seqId;
  int							regSize;
  void						*mem;
  char						active;
}									t_memPlus_reg;

typedef	struct		s_memPlus_env
{
  t_memPlus_reg		*regions;
  int 						num_regions;
  int							total_allocd;
  int							byte_limit;
  int							region_limit;
  int							bytes_free;
  int							regions_free;
}									t_memPlus_env;

void	memPlus_init(t_memPlus_env *env, int region_limit, int byte_limit);
void	*memPlus_alloc(t_memPlus_env *env, int regSize, char *regName);

