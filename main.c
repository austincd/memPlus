#include "memPlus.h"

int main(int argc, char **argv)
{
  MPenv env;
  MPslot *slot;

  memPlus_init(&env, 8, 1024);
  slot = memPlus_alloc(&env, 100, "first");
  return (1);
}
