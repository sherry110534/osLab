#include <stdio.h>                                                              
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <sys/mman.h>


int main(){
	//the size of shared memory
	const int SIZE = 4096;
	//name of the shared memory
	const char *name = "OS";
	//shared memory descriptor
	int fd;
	//pointer to shared mem
	void *ptr;
	//create the shared  mem
	fd = shm_open(name,O_CREAT | O_RDWR,0666);
	//configure the size of shared mem
	ftruncate(fd,SIZE);
	//mem map to the shared mem
	ptr = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,fd,0);
	//write to the shared mem

	int i=0;
	//string written to shared memory
	const char *msg[16];
	printf("Enter some text(exit=finish):");
	char s[256];
	while(fgets(s,256,stdin)!=NULL){
		if(strcmp(s,"exit\n")==0){
			msg[i]=s;
			//printf("%s\n",msg[i]);
			sprintf(ptr,"%s",msg[i]);
			ptr += strlen(msg[i]);
			break;
		}
		else{
			msg[i]=s;
			//printf("%s\n",msg[i]);
			sprintf(ptr,"%s",msg[i]);
			ptr += strlen(msg[i]);
			i++;
			printf("Enter some text(exit=finish):");
		}
	}
	return 0;

}
