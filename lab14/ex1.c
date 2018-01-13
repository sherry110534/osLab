#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_LENGTH 0x50

int main(int argc, char *argv[]){
	int fd, count;
	char ch[80] = {0};
	void *file_memory;
	//open file
	fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	lseek(fd, 0, SEEK_SET);
	write(fd, "", FILE_LENGTH);
	//create the memory mapping
	file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);

	count = strlen(file_memory);
	//printf("count1: %d\n",count); 

	printf("Input any character continuously:\n");
	while(1 &&  count <= FILE_LENGTH){
		gets(ch);
		count = strlen(file_memory);
		sprintf((char*)(file_memory+count),"%s",ch);
		count = strlen(file_memory);
		//printf("count2: %d\n",count);
		//printf("You can open another terminal use 'more' command to check the file now...\n");
	}
	//release
	munmap((char*)file_memory, FILE_LENGTH);

	return 0;
}
