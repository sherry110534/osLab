#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	seteuid(0);
	int uid = getuid();
	int euid = geteuid();
	printf(
		"Real	  UID = %d\n"
		"Effective UID = %d\n",
		uid,
		euid
	);
	return 0;
}
