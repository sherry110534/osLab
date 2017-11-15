#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	if (fork() == 0){
		printf("I am child process 1. \n");
		printf("PID: %d\tParent PID:%d\n", getpid(), getppid());
		return 0;
	}
	if (fork() == 0){
		printf("I am child process 2. \n");
		printf("PID: %d\tParent PID:%d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	wait(NULL);
	printf("I am parent process. \n");
	printf("PID:%d\tParent PID:%d\n", getpid(), getppid());
	return 0;
}
