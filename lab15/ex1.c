#include <stdio.h>
#include <fcntl.h> //for open(), close(), read()
#include <string.h> //for memset()
#include <sys/select.h>//for FD_*, select()
#include <limits.h>//for PIPE_BUF

int main(){
	char buffer[PIPE_BUF];
	int fd1 = open("fifo1", O_RDWR|O_NONBLOCK);
	int fd2 = open("fifo2", O_RDWR|O_NONBLOCK);
	fd_set readmask;
	int maxfd = fd1;//maxfd = listen amount
	if(maxfd < fd2){
		maxfd = fd2;
	}
	maxfd++;
	printf("fd1 = %d, fd2 = %d, maxfd = %d\n", fd1, fd2, maxfd);
	struct timeval tv;
	while(1){
		FD_ZERO(&readmask);
		FD_SET(fd1, &readmask);//add fd1
		FD_SET(fd2, &readmask);//add fd2
		tv.tv_sec = 5;
		tv.tv_usec = 0;
		memset(&buffer, 0, PIPE_BUF);//set 0
		int ready = select(maxfd, &readmask, NULL, NULL, &tv);
		if(ready < 0){//failure
			printf("Failure\n");
			continue;
		}
		else if(ready == 0){//Timeout
			printf("Timeout. Try another select.\n");
			continue;
		}
		else{//ready
			if(FD_ISSET(fd1, &readmask)){//fd1 is readable
				printf("Device 1 can read.\n");
				read(fd1, &buffer, PIPE_BUF);
				printf("%s\n", buffer);
			}
			if(FD_ISSET(fd2, &readmask)){//fd2 is readable
				printf("Device 2 can read.\n");
				read(fd2, &buffer, PIPE_BUF);
				printf("%s\n", buffer);
			}
		}
	}
	close(fd1);
	close(fd2);
	return 0;
}
