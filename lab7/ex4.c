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
	struct msqid_ds msq_id;
	msqid = msgget((key_t) 0x1234, 0);
	msgctl(msqid, IPC_STAT, &msq_id);
	printf("Msq ID:%d	perms:%o	message:%d	used-bytes:%d\n", msqid, msq_id.msg_perm.mode, (int) msq_id.msg_qnum, (int) msq_id.msg_cbytes);
	msq_id.msg_perm.mode = 0444;
	msgctl(msqid, IPC_SET, &msq_id);
	return 0;
}
