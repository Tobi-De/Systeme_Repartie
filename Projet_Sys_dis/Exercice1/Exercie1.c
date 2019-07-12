#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    pid_t fils1, fils2, fils3;
    int status;

    fils1 = fork();
    if(fils1 < 0){
        perror("\nErreur de creation du processus fils");
        exit(EXIT_FAILURE);
    }
    if(fils1 == 0){
        //Le fils 1 a ete cree, il vague a ses occupations"
    }
    else{
        fils2 = fork();
        if(fils2 < 0){
            perror("\nErreur de creation du processus fils");
            fils1 = wait(&status);
            exit(EXIT_FAILURE);
        }

        if(fils2 == 0){
           //Le fils 2 a ete cree, il vague a ses occupations"
        }
        else{
            fils3 = fork();
            if(fils3 < 0){
                perror("\nErreur de creation du processus fils");
                fils2 = wait(&status);
                exit(EXIT_FAILURE);
            }

            if(fils3 == 0){
                //Le fils 3 a ete cree, il vague a ses occupations"
            }
            else{
                fils1 = wait(&status);
                printf("\nLe pid du fils 1 est: %d", fils1);
                fils2 = wait(&status);
                printf("\nLe pid du fils 2 est: %d", fils2);
                fils3 = wait(&status);
                printf("\nLe pid du fils 3 est: %d", fils3);
            }
        }
    }
    
}
