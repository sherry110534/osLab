#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void *thread_function (void *arg){
	int i;
	printf("Thread %d: ID %lu Completed\n", (int)arg, pthread_self());
	for(i = 0; i < 250000; i++){
		count+=1;
	}
	pthread_exit(NULL);
}
void checkcreate(int rc){
	if(rc){ 
		printf("ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1); 
	} 	
}
void checkjoin(int rc){
	if(rc){ 
		printf("ERROR; return code from pthread_join() is %d\n", rc); 
		exit(-1); 
	}
}
int main(){
	pthread_t thread1, thread2, thread3, thread4;
	int rc1, rc2, rc3, rc4;

	rc1 = pthread_create(&thread1, NULL,thread_function, (void *)1); 
	checkcreate(rc1);

	rc2 = pthread_create(&thread2, NULL,thread_function, (void *)2); 
	checkcreate(rc2);

	rc3 = pthread_create(&thread3, NULL,thread_function, (void *)3); 
	checkcreate(rc3);
	
	rc4 = pthread_create(&thread4, NULL,thread_function, (void *)4); 
	checkcreate(rc4);
	rc1 = pthread_join(thread1, NULL); 
	checkjoin(rc1);
	rc2 = pthread_join(thread2, NULL); 
	checkjoin(rc3);
	rc3 = pthread_join(thread3, NULL); 
	checkjoin(rc4);
	rc4 = pthread_join(thread4, NULL); 
	checkjoin(rc4);

	printf("\nThis is main program.\nvalue = %d\n", count);

	return 0;
}
