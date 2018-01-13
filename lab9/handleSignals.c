#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//here is the signal handler
void catch_int(int sig_num){
	//re-set the signal handler again to catch_int, for next time
	signal(SIGINT, catch_int);
	printf("Ouch!-I got signal %d\n", sig_num);
}

int main(){
	signal(SIGINT, catch_int);
	for( ; ; )
		pause();
	return 0;
}
