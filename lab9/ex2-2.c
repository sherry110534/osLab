#include <signal.h>
#include <stdio.h>
#include <unistd.h>

struct sigaction newact;

void catch_int1(int sig_num){
	printf("How are you?\n");
}
void catch_int2(int sig_num){
	printf("I am fine\n");
}

void catch_alarm_2(){
	printf("3s\n");
	//default
	signal(SIGINT, SIG_DFL);
}
void catch_alarm_1(){
	printf("3s\n");
	signal(SIGINT, catch_int2);
	signal(SIGALRM, catch_alarm_2);
	alarm(3);
}

int main(){
	//set ctrl-c signal handler to "catch_int1"
	signal(SIGINT, catch_int1);
	//set alarm
	signal(SIGALRM, catch_alarm_1);
	alarm(3);

	for( ; ; )
		pause();
	return 0;
}
