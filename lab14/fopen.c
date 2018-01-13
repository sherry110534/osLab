#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char buffer[] = {'x', 'y', 'z'};
	//w+: open file which can be read and written
	//w: open file which can only be read
	fp = fopen(argv[1], "w+");

	fwrite(buffer, 1, sizeof(buffer), fp);
	printf("You can open another terminal use 'more' command to check the file now...\n");
	
	//Wait user input any character to close fp.
	getchar();
	fclose(fp);
	return 0;
}
