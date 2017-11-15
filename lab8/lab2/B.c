#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include "msg_que.h"

int msqid,msgid;
struct oslab_msg_st msg_buffer;

void *send(void *arg){
	key_t key = 0x1234;
	msqid = msgget(key,IPC_CREAT | 0666);

	printf("Enter some text:");

	do{
		fgets(msg_buffer.msg_text,sizeof(msg_buffer),stdin);
		msg_buffer.oslab_msg_type = 50;
		msgsnd(msqid,(void *) &msg_buffer,sizeof(msg_buffer) - sizeof(long int),0);
		printf("Enter some text:");
	}while(strcmp(msg_buffer.msg_text,"exit\n")!=0);
	pthread_exit(NULL);
}

void *recieve(void *arg){
	key_t key = 0x1234;
	msgid = msgget(key,IPC_CREAT | 0666);

	do{
		msgrcv(msgid,(void *) &msg_buffer,sizeof(msg_buffer) - sizeof(long int),0,0);
		printf("\nRecieve:%s\n",msg_buffer.msg_text);
	}while(strcmp(msg_buffer.msg_text,"exit\n")!=0);
	pthread_exit(NULL);

}

int main(){

	pthread_t threads,threadr;
	int rc1,rc2,t=100;
	rc1=pthread_create(&threadr,NULL,recieve,(void*)t);
	rc1=pthread_create(&threads,NULL,send,(void*)t);

	rc1=pthread_join(threadr,NULL);
	rc1=pthread_join(threads,NULL);

	return 0;
}
