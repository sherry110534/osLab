#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msg_que.h"

int main()
{
    int msgid;
	struct oslab_msg_st msg_buffer;
	msgid = msgget((key_t)0x1234, IPC_CREAT | 0666);//get the msg queue ID
	msgrcv(msgid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 10, 0);
	printf("%s\n", msg_buffer.msg_text);

	msgrcv(msgid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0, 0);
	printf("%s\n", msg_buffer.msg_text);
	
	msgrcv(msgid, (void *)&msg_buffer, sizeof(msg_buffer) - sizeof(long int), 0, 0);
	printf("%s\n", msg_buffer.msg_text);



	return 0;
}
