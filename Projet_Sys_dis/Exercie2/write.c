 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>

#define ITER 3


int main(int argc, char *argv[]) 
{ 
  // generation de la cle
  key_t key = ftok("shmfile",65); 
  int i;

  // renvoie un identifiant
  int shmid = shmget(key,1024,0666|IPC_CREAT); 
  //  cree la memoire partager
  int value = (int) shmat(shmid,(void*)0,0);

  value = (int)argv[2]; 

  /*for(i=0; i < ITER; i++){
     printf("Write Data : \n"); 
     gets(str); 

     printf("Data written in memory: %s\n",str); 
  }	*/
  //detach from shared memory 
  //shmdt(str); 
  // destroy the shared memory 
  //shmctl(shmid,IPC_RMID,NULL);
  return 0; 
} 