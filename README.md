Tools to help automate memory management and tracking in C.

+An environment structure is initialized at the start of a process, taking in
limits on the number of allocations, as well as the number of bytes the program
may allocate at one time. The initialization sets up an array of memPlus_regions,
which will be used to record data about every memory allocation during the execution
of the program.

+Every memPlus_alloc call checks the environment structure for the first region in
the array not in use. It then occupies that region, attempts to malloc() and bzero()
a region of memory of the requested size, and if successful, it records the address
of that allocated space(along with any metadata about the malloc call or region "name")
in the memPlus_region structure. The calling function is returned the address of the
struture, so any calling function, as well as the main of the program, are able
to track(and therefore free) all malloced regions of memory based on whether or not
they are marked as being in use, their size, their name, or their sequential ID.

+In the place of just freeing a memory address, the user has the choice of calling
commands to either "free" or "kill" a region or selection of regions allocated by
the program. These are almost identical, but "kill" frees any reserved memory in
a region even if the region is still marked as being active. This could result
in segfaults if you aren't absolutely certain that the program won't try to access
that region of memory again, so be careful. Either way, "free" will only close
a region passed to it if that region is not marked as "active". On the other hand,
"kill" acts as a sort of "force-free", which will free any mem areas and bzero()
their encasing regions regardless.

+The standard memPlus_free() and memPlus_kill() functions allow the user to target
a region of memory based on the standard identifier, the seqId(sequential id).
However, those functions just find a region with the matching id, and pass the
address of that region into another function that handles the rest. This way,  we
can create more complex functions that select and either free or kill a group of
regions based on some kind of conditional statement.

+Currently, the examples we have are functions to free or kill ALL the allocated
regions of memory, and functions to free or kill all allocated regions based on
how large or small they are in bytes, with an upper or lower bound passed in as
a parameter.