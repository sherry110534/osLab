#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msg_que.h"

int main()
{
    int msqid;
	struct oslab_msg_st msg_buffer;
	key_t key = 0x1234;
	msqid = msgget(key, IPC_CREAT | 0666);
	while(1){
		printf("Received: ");
		msgrcv(msqid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0,0);
		if(!strcmp(msg_buffer.msg_text, "exit\n")){
			printf("%s\n", msg_buffer.msg_text);
			return 0;
		}
		else{
			printf("%s\n", msg_buffer.msg_text);
		}
	}	
	return 0; 
}
