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
	// set the key value
	key_t key = 0x1234;
	// create a message queue
	msqid = msgget(key, IPC_CREAT | 0666);
	char str[256];
	int i = 1;
	printf("Enter some text: ");
	while(fgets(str, sizeof(str), stdin) != NULL){
		if(strcmp(str, "exit\n") == 0){
			strcpy(msg_buffer.msg_text, str);
			msg_buffer.oslab_msg_type = i;
			msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0);
			break;
		}
		else{
			strcpy(msg_buffer.msg_text, str);
			msg_buffer.oslab_msg_type = i;
			msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0);
			i++;
			printf("Enter some text: ");
		}
	}
	return 0;
}
