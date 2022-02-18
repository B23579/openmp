# openmp

## Parallel writing in the same memory in an OMP loop 

Race conditions occur when different threads write to the same location at the same time. This is not necessarily an undefined behavior, but it should be avoided.
In the same way, if at least one thread reads from and writes to the same memory unit without synchronization, as a result of atomicity as described above, then a data race occurs. The outcome of the program is unspecified if a data race occurs.

So we implemented a specific case to solve this situation by using multiple to tread to create a 2D array in c++ using vector_name.push_back() routine. [code](https://github.com/B23579/openmp/blob/main/write_on_same_memory_with_Nthread.cpp) 
