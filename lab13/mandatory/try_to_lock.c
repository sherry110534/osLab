#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct flock* file_lock(short type, short whence){
	static struct flock ret;
	ret.l_type = type;
	ret.l_type = type;
	ret.l_start = 0;
	ret.l_whence = whence;
	ret.l_len = 0;
	return &ret;
}

int main(){
	int input, unlock;
	int fd = open("mandlock.txt", O_RDWR|O_APPEND);
	printf("opening file success, Choosing lock type:\n");
	printf("1. exclusive lock(write lock). 2. share lock(read lock). 3. not use lock\n");
	fflush(stdin);
	scanf("%d", &input);
	if(input == 1){
		if(fcntl(fd, F_SETLKW, file_lock(F_WRLCK, SEEK_SET)) == 0){
			printf("Locking file with 'WRLCK' success\n");
		}
		else{
			printf("F_WRLCK fail, another process lock it.\n");
			return 0;
		}
	}
	else if(input == 2){
		if(fcntl(fd, F_SETLK, file_lock(F_RDLCK, SEEK_SET)) == 0){
			printf("Locking file with 'RDLCK' success\n");
			char line[1000];
			if(read(fd, line, 1000) < 0){
				printf("Can't read file\n");
			}
			else{
				printf("Read success. string is : ");
				puts(line);
			}
			strcpy(line, "\nNo locking write in.\n");
			if(write(fd, line, strlen(line)) < 0){
				printf("can't write file\n");
				return 0;
			}
			else{
				printf("write file success\n");
				return 0;
			}
		}
		else{
			printf("F_RDLCK fail, another process lock it.\n");
			return 0;
		}
	}
	else if(input == 3){
		char line[1000];
		if(read(fd, line, 1000) < 0){
			printf("Can't read file\n");
		}
		else{
			printf("Read success. string is : ");
			puts(line);
		}
		strcpy(line, "\nNo locking write in.\n");
		if(write(fd, line, strlen(line)) < 0){
			printf("can't write file\n");
		}
		else{
			printf("write file success\n");
			return 0;
		}
	}
	fflush(stdin);
	printf("enter integer to unlock\n");
	scanf("%d", &unlock);
	fcntl(fd, F_SETLKW, file_lock(F_UNLCK, SEEK_SET));
	printf("unlock success\n");
	close(fd);
	return 0;
}
