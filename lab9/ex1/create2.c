#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	//child
	if(fork() == 0){
		printf("child process\npid = %d\nparent pid = %d\n", getpid(), getppid());
		return 0;
	}
	//parent
	wait(NULL);
	printf("-------------------------------------\n");
	printf("parent process\npid = %d\n", getpid());
	for( ; ; )
		pause();
	return 0;
}
