/**
 * a C file to demonstrate Inter Process Communication using
 * Shared Memory in Linux.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#define SHARED_MEM_SIZE 1024 // 1024 = 1MiB
#define SHARED_KEY_FILENAME "shmfile"

int main(){
    // first generate the key for shared memory!
    key_t shared_memory_key = ftok(SHARED_KEY_FILENAME, 65);
    
    // and makes the space in the memory!
    int shared_memory_space_id = shmget(shared_memory_key, SHARED_MEM_SIZE, 0 | IPC_CREAT);

    // after that, let's fork the process 
    if(fork() != 0){
        // parent

        /**
         * This one, we gonna attach the shared memory space
         * and allocate it as a string (char *) memory space
         * 
         * key => using key have been generated
         * memory location => 0, to make it random
         * flag => 0, we won't use flag at all
        */

        char * data = (char *) shmat(shared_memory_space_id, (void *) 0, 0);

        sleep(1);
        strcpy(data, "Hewwo everyone! \(OwO)/");
        sleep(1);

        printf("[PARENT] the data is %s\n", data);

        // and we detach it
        /**
         * what you borrow, shall be returned
        */
       shmdt(data);

    }else{
        // child

        /**
         * This one, we gonna attach the shared memory space
         * and allocate it as a string (char *) memory space
         * 
         * key => using key have been generated
         * memory location => 0, to make it random
         * flag => 0, we won't use flag at all
        */

        char * info = (char *) shmat(shared_memory_space_id, (void *) 0, 0);
        
        // print the whole data
        sleep(2);
        printf("[CHILD] the data is %s\n", info);
        strcpy(info, "This message has been modified");
        sleep(2);

        // detach
        shmdt(info);
    }
}