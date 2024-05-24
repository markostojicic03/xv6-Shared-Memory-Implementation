#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"



int main(int argc, char **argv){

    int shm = shm_open("shm demo");
    if(shm < 0){
        printf("failed to open shm\n");
        exit();
    }

    shm_trunc(shm, 4096);

    void *shmReg;
    
    if(shm_map(shm, &shmReg,O_RDONLY ) < 0){
        printf("failed to map shm\n");
        exit();
    }
    const char *shmRegChar = shmReg;
    printf("message: %s\n", shmRegChar);


   exit();

}
