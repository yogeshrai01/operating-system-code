#include<stdio.h>
#include<unistd.h>
int main()
{
    int pid;
    pid=fork();
    if(pid>0){
        sleep(10);
        printf("Its parent process\n");
        printf("Get Process id :%d",getpid());
    }
    else {
    printf("its child process\n");
    printf("Get process id:%d",getpid());
    exit(0);
}
return 0;
}