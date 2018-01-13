#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	DIR *dp;
	char *dir = "./test";
	char *filestr;
	struct dirent *entry;
	struct stat statbuf;

	dp = opendir(dir);//open dir stream and return a DIR*

	while((entry=readdir(dp)) != NULL){
		if(entry->d_type != 4){//d_type=4 means it is dir
			filestr = entry->d_name;
			stat(filestr, &statbuf);
			printf("name: %s\tsize: %d\n", entry->d_name, statbuf.st_size);
		}
	}
	closedir(dp);
	exit(0);
}
