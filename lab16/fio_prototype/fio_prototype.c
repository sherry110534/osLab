#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	DIR *dp;
	char *filestr = "./bio_s";
	struct stat statbuf, statbuf_s;
	
	stat(filestr, &statbuf);
	lstat(filestr, &statbuf_s);

	//show the information
	//mode 100777 >>100 file type 777 mod
	printf("\nThe INFO of the original file -> Size:%ld Mode:%o\n", statbuf.st_size, statbuf.st_mode);
	printf("\nThe INFO of the file -> Size:%ld Mode:%o\n", statbuf_s.st_size, statbuf_s.st_mode);
	return 0;
}
