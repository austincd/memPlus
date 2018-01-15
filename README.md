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