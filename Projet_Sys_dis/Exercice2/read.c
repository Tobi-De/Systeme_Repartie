 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>

#define ITER 3


int main() 
{ 
  // generation de la cle
  key_t shm_key = ftok("shmfile",65); 
  int i;
  // renvoie un identifiant 
  int shmid = shmget(shm_key,1024,0666); 

  // cree a memoire partager
  int *value = (int*) shmat(shmid,(void*)0,0); 
  
  value = 10;
  
  //detach from shared memory
  //shmdt(value);
  
  //destroy the shared memory
  //shmctl(shmid,IPC_RMID,NULL); 
	
  return 0; 
} 
