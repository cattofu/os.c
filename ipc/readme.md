# cattofu/os.c/ipc
this is a folder for Inter Process Communication or IPC on linux. 

## [Shared Memory](shared_memory.c)
Shared memory is one of method for Inter Process Communication. To put it simple, the way two or more process communicate using shared memory is by having a common memory space that accissible by those processes. 

In Linux, the process can be said are like this :
* the shared memory itself should ne created first 
* each process that want to use the shared memory should attach its own memory space 
* then the process can put or write or do whatever with it
* (and don't forget to) to detach it's own memory space with the shared memory space when done.

According to some internet literature I have read, this is the fastest way for a process to communicate with other process, but idk 

**:P**