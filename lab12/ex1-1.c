#include <stdio.h>
#include <stdlib.h>
#include <time.h>     //for random

//Define text color
#define RED_BOLD "\x1b[;31;1m"
#define BLU_BOLD "\x1b[;34;1m"
#define YEL_BOLD "\x1b[;33;1m"
#define GRN_BOLD "\x1b[;32;1m"
#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"
#define RESET "\x1b[0;m"

// Define parameters
#define MemorySize 32
#define PageSize 2

// record each page map to frame
int r[6];
int ascChar[32];


void Init();
void Paging();
void Randomize();
void Result();



int main() {
	// initial
	Init();
	Paging();
	Result();
	return 0;
}

void Paging() {
	printf(RED_BOLD"Step2: Paging\n"RESET);

	int i = 0, j = 0, asc = 65;
	Randomize();
	for(i = 0; i < 6; i++){
		r[i] = rand() % 16;
		if( i != 0){
			for(j = 0; j < i; j++){
				if(r[j] == r[i]){
					i--;
					break;
				}
			}
		}    
	}

	for(i = 0; i < 6; i++){
		if(i < 3)
		{
			printf("\t Process 0 Page(%d) -> frame(%d)\n", i, r[i]);
		} else {
			printf("\t Process 1 Page(%d) -> frame(%d)\n", i, r[i]);
		}

		ascChar[r[i] * 2] = asc;
		// printf("%c ", ascChar[r[i] * 2]);
		asc++;
		ascChar[r[i] * 2 + 1 ] = asc;
		// printf("%c !", ascChar[r[i] * 2 + 1]);
		asc++;
	}

	printf(GRN_BOLD"FreeFrameList[10]: "RESET);
	for(i = 0; i < 16; i++){
		if( i == r[0] || i == r[1] || i == r[2] || i == r[3] || i == r[4] || i == r[5]){
			continue;
		} else {
			printf("%d,", i);
		}
	}
	printf("\n\n");

}

void Result() {
	int i = 0, j = 0 , asc = 65;
	printf(RED_BOLD"Step3: Result\n"RESET);

	printf(BLU_BOLD"*****Logical Memory*****\n"RESET);
	printf("----  Frame\tEntry\tData----\n");
	for(i = 0; i <12 ; i++ , asc++){
		printf("-\t%d\t %d\t %c-----\n", i/2, i, asc);
	}

	printf(YEL_BOLD"Process 0:\n"RESET);
	printf(BLU_BOLD"*******Page Table*******\n"RESET);
	printf("-------Page   Frame-----\n");
	for(i = 0; i <3 ; i++){
		printf("-        %d      %d-----\n", i, r[i]);
	}
	printf(YEL_BOLD"Process 1:\n"RESET);
	printf(BLU_BOLD"*******Page Table*******\n"RESET);
	printf("-------Page   Frame-----\n");
	for(i = 3; i <6 ; i++){
		printf("-        %d      %d-----\n", i, r[i]);
	}

	printf(BLU_BOLD"*****Physical Memory*****\n"RESET);
	printf("----  Frame\tEntry\tData----\n");
	int k = 0;
	for(i = 0 ; i <32 ; i++){
		if(i/2 == r[0] || i/2 == r[1] || i/2 == r[2] || i/2 == r[3] || i/2 == r[4] || i/2 == r[5]){
			if(k == 0){
				printf("-\t%d\t %d\t %c-----\n", i/2, i, ascChar[i/2 * 2]);
				k++;
			} else {
				printf("-\t%d\t %d\t %c-----\n", i/2, i, ascChar[i/2 * 2 +1]);
				k--;
			}
		} else {
			printf("-\t%d\t %d\t ?-----\n", i/2, i);
		}
	}

}

void Randomize() {
	time_t t;
	srand((unsigned) time(&t));
}

void Init() {
	printf(RED_BOLD"Step1: Initialization\n"RESET);
	printf(YEL_BOLD"Process 0:\n"RESET);
	printf(BLU_BOLD"*******Page Table*******\n"RESET);
	printf("-------Page   Frame-----\n");
	printf("-        -1      -1-----\n");
	printf("-        -1      -1-----\n");
	printf("-        -1      -1-----\n");
	printf(YEL_BOLD"Process 1:\n"RESET);
	printf(BLU_BOLD"*******Page Table*******\n"RESET);
	printf("-------Page   Frame-----\n");
	printf("-        -1      -1-----\n");
	printf("-        -1      -1-----\n");
	printf("-        -1      -1-----\n");
	printf(BLU_BOLD"*****Logical Memory*****\n"RESET);
	printf("----Page/Entry  Data----\n");
	printf("-      0     0     ?----\n");
	printf("-      0     1     ?----\n");
	printf("-      1     2     ?----\n");
	printf("-      1     3     ?----\n");
	printf("-      2     4     ?----\n");
	printf("-      2     5     ?----\n");
	printf("-      3     6     ?----\n");
	printf("-      3     7     ?----\n");
	printf("-      4     8     ?----\n");
	printf("-      4     9     ?----\n");
	printf("-      5    10     ?----\n");
	printf("-      5    11     ?----\n");
	printf(BLU_BOLD"*****Physical Memory*****\n"RESET);
	printf("----Page/Entry  Data----\n");
	printf("-      0     0     ?----\n");
	printf("-      0     1     ?----\n");
	printf("-      1     2     ?----\n");
	printf("-      1     3     ?----\n");
	printf("-      2     4     ?----\n");
	printf("-      2     5     ?----\n");
	printf("-      3     6     ?----\n");
	printf("-      3     7     ?----\n");
	printf("-      4     8     ?----\n");
	printf("-      4     9     ?----\n");
	printf("-      5    10     ?----\n");
	printf("-      5    11     ?----\n");
	printf("-      6    12     ?----\n");
	printf("-      6    13     ?----\n");
	printf("-      7    14     ?----\n");
	printf("-      7    15     ?----\n");
	printf("-      8    16     ?----\n");
	printf("-      8    17     ?----\n");
	printf("-      9    18     ?----\n");
	printf("-      9    19     ?----\n");
	printf("-     10    20     ?----\n");
	printf("-     10    21     ?----\n");
	printf("-     11    22     ?----\n");
	printf("-     11    23     ?----\n");
	printf("-     12    24     ?----\n");
	printf("-     12    25     ?----\n");
	printf("-     13    26     ?----\n");
	printf("-     13    27     ?----\n");
	printf("-     14    28     ?----\n");
	printf("-     14    29     ?----\n");
	printf("-     15    30     ?----\n");
	printf("-     15    31     ?----\n");
	printf(GRN_BOLD"FreeFrameList[16]: 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15\n\n"RESET);
}
