#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_LENGTH 0x01

int main(int argc, char *argv[]){
	int fd, count;
	char ch;
	void *file_memory;
	fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	//open file

	lseek(fd, 1, SEEK_SET);
	//write file from start
	write(fd, "", 1);
	//just let a text file no less than 1 byte
	
	file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
	//create the memory mapping
	
	close(fd);

	//write a character to memory-mapping area
	printf("Enter any character:\n");
	scanf("%c", &ch);
	
	getchar();
	sprintf((char*)file_memory, "%c", ch);
	printf("You can open another terminal use 'more' command to check the file now...\n");

	//input to close mmap
	getchar();
	
	//release the memory
	munmap((char*)file_memory, FILE_LENGTH);
	return 0;
}
