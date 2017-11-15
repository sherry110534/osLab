#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t  new_pid;
	new_pid = fork();
	if(new_pid < 0){
		printf("fork error\n");
		return 0;
	}
	else if(new_pid == 0){
		printf("\n----------This is child process----------\n");
		printf("Pid:%d\nParent pid:%d\n", getpid(), getppid());
		printf("-----------------------------------------\n");
		return 0;
	}
	else{
		printf("\n----------This is parent process----------\n");
		printf("Pid:%d\nChild Pid:%d\n", getpid(), new_pid);
		printf("------------------------------------------\n");
		return 0;
	}	
}
