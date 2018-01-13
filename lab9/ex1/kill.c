#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
	pid_t pid;
	printf("insert the process to kill:\n");
	scanf("%d", &pid);
	kill(pid, SIGKILL);
	return 0;
}
