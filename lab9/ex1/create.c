#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	//child
	if(fork() == 0){
		for( ; ; )
			pause();
		return 0;
	}
	printf("pid = %d\n", getpid());
	//parent
	wait(NULL);
	printf("finish\n");
	return 0;
}
