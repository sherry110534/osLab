#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf(
		"Real	  UID = %d\n"
		"Effective UID = %d\n",
		getuid(),
		geteuid()
	);
	return 0;
}
