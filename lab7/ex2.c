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
	printf("Message Queue Identifier:%d\n", msqid);
	// set the message
	strcpy(msg_buffer.msg_text, "Message No.1 Msg type : 5");
	 msg_buffer.oslab_msg_type = 5;
	// send the message to message queue
	msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0);
	strcpy(msg_buffer.msg_text, "Message No.2 Msg type : 10");
	msg_buffer.oslab_msg_type = 10;
	msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0);
	strcpy(msg_buffer.msg_text, "Message No.3 Msg type : 20");
	msg_buffer.oslab_msg_type = 20;
	msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0);
	return 0;
}
