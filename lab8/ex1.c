#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *PrintHello (void *arg){
	printf("This is Hello Thread\n");
	printf("Thread ID: %lu\n", pthread_self());
	printf("Argument: %d\n", (int)arg);
	pthread_exit(NULL);
}
int main(){
	pthread_t thread;
	int rc, t = 100;
	rc = pthread_create(&thread, NULL, PrintHello, (void *)t);
	if(rc){
		printf("ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1);
	}
	rc = pthread_join(thread, NULL);
	if(rc){
		printf("ERROR; return code from pthread_join() is %d\n", rc);
		exit(-1);
	}
	return 0;
}
