#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_NAME_SIZE    32
#define MAX_BUF_SIZE    100
#define SRC_PATH    "/home/stiks/OS_LABS/Lab_1/src/"

int main(){
    char *temp = SRC_PATH;
    char name_file[MAX_NAME_SIZE];
    char buffer[MAX_BUF_SIZE];
    scanf("%s",name_file);
    char *path = (char *)malloc(strlen(temp) + strlen(name_file) + 1);
    if (path == NULL) {
        perror("MAlloc");
        exit(EXIT_FAILURE);
    }
    // printf("%s\n", name_file);
    strcpy(path, temp); // Копирование str1 в result
    strcat(path, name_file); // Сконкатенирование str2 к result
    FILE *file;
    file = fopen(path,"r");
    // printf("%p\n", file);
    if(file==NULL){
        perror("Faild open file");
        exit(EXIT_FAILURE);
    }
    int fd[2];
    int err = pipe(fd);
    int write1 = fd[1], read1 = fd[0];
    if (err == -1)
    {
        perror("Faild make pipe");
        exit(EXIT_FAILURE);
    }
    
    pid_t pid = fork();
    if (pid==-1)
    {
        perror("Faild child process");
        exit(EXIT_FAILURE);
    }
    
    if(pid==0){// Child
        close(read1);
        err = dup2(fileno(file),fileno(stdin));
        if(err==-1){
            perror("Faild dup file to stdin");
            exit(EXIT_FAILURE);
        }
        err = dup2(write1, fileno(stdout));
        if(err==-1){
            perror("Faild dup file to stdin");
            exit(EXIT_FAILURE);
        }
        err = execl("./bin/child_process","./bin/child_process",NULL);
        if(err==-1){
            perror("Faild run programm from child process");
            exit(EXIT_FAILURE);
        }



    }else{// Father
        close(write1);

        read(read1,buffer,sizeof(buffer));
        printf("%s\n", buffer);
        wait(NULL);
        fclose(file);

    }



    
    // printf("%s\n",name_file);


    return 0;


}




