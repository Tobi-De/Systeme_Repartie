#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(int argc, char* argv[]){
    pid_t fils1, fils2, fils3;
    int status;

    // generation de la cle
    key_t key = ftok("shmfile",65); 
    int i;

    // renvoie un identifiant
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
    //  cree la memoire partager
    int *value = (int*) shmat(shmid,(void*)0,0);

    *value = 0; 

    fils1 = fork();
    if(fils1 < 0){
        perror("\nErreur de creation du processus fils");
        exit(EXIT_FAILURE);
    }
    if(fils1 == 0){
        for(i = 0; i < 100; i++){
            *value += 1;
        }
        i = 0;
        
    }
    else{
        fils2 = fork();
        if(fils2 < 0){
            perror("\nErreur de creation du processus fils");
            fils1 = wait(&status);
            exit(EXIT_FAILURE);
        }

        if(fils2 == 0){
           for(i = 0; i < 100; i++){
                *value += 1;
            }
            i = 0;
        }
        else{
            fils3 = fork();
            if(fils3 < 0){
                perror("\nErreur de creation du processus fils");
                fils2 = wait(&status);
                exit(EXIT_FAILURE);
            }

            if(fils3 == 0){
                for(i = 0; i < 100; i++){
                    *value += 1;
                }
            }
            else{
               
                fils3 = wait(&status);
                printf("\nLa value est: %d", *value);
                
                //detach from shared memory
                shmdt(value);
  
                //destroy the shared memory
                shmctl(shmid,IPC_RMID,NULL); 
            }
        }
    }
    
}