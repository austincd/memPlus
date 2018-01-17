int	memPlus_diag(t_memPlus_env *env, int fd)
{
  int counter;

  counter = 0;
  if (env && env->num_regions && fd >= 0)
    {
      while (counter < env->num_regions)
      {
        ft_putendl_fd(env->regions[counter].name, fd);
        ++counter;
      }
}
