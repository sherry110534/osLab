#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
int main(){
	//the size of shared memory
	const int SIZE = 4096;
	//name of the shared memory
	const char *name = "OS";

	//shared memory descriptor
	int shm_fd;
	//pointer to shared mem
	void *ptr;
	//int *tmp;
	//create the shared  mem
	shm_fd = shm_open(name,O_RDONLY,0666);

	//mem map to the shared mem
	ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
	//read to the shared mem
	printf("%s",(char *)ptr);
	printf("\n");
	printf("all over\n");
	shm_unlink(name);
	return 0;
}
