#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int global_num = 10;

int main(){
	int local_num = 10;
	if (fork() == 0){
		printf("global = %d\nlocal = %d\n", global_num, local_num);
		global_num++;
		local_num++;
		printf("global++ = %d\nlocal++ = %d\n", global_num, local_num);
		printf("I am child process 1. \n");
		printf("PID: %d\tParent PID:%d\n", getpid(), getppid());
		return 0;
	}
	
	wait(NULL);
	printf("global = %d\nlocal = %d\n", global_num, local_num);
	printf("I am parent process. \n");
	printf("PID:%d\tParent PID:%d\n", getpid(), getppid());
	return 0;
}
