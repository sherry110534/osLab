#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MemorySize 32
#define PageSize 2

int r[6];
int ascChar[32];

void init(){
	int i;
	printf("STEP1:Initialization\n");
	//processA
	printf("Process A:\n");
	printf("*******Page Table******\n");
	printf("-----Page-----Frame----\n");
	for(i = 0; i < 3; i++){
		printf("-\t-1\t-1-----\n");
	}
	//processB
	printf("Process B:\n");
	printf("*******Page Table******\n");
	printf("-----Page-----Frame----\n");
	for(i = 0; i < 3; i++){
		printf("-\t-1\t-1-----\n");
	}
	//logical memory
	printf("****Logical Memory*****\n");
	printf("--Page/Entry----Data---\n");
	for(i = 0; i < 12; i++){
		printf("-  %d\t%d \t   ?---\n", i/2, i);
	}
	//physical memory
	printf("****Physical Memory****\n");
	printf("-Frame/Entry----Data---\n");
	for(i = 0; i < MemorySize; i++){
		printf("-  %d\t%d \t   ?---\n", i/2, i);
	}
	printf("FreeFrameList[16]: ");
	for(i = 0; i < 16; i++){
		printf("%d ",i);
	}
	printf("\n");
}
void paging(){
	printf("STEP2:Paging\n");
	time_t t;
	srand((unsigned) time(&t));
	int i, j, asc = 65;
	//produce six non-repetitive numbers
	for(i = 0; i < 6; i++){
		r[i] = rand() % 16;
		if(i != 0){
			for(j = 0; j < i; j++){
				if(r[j] == r[i]){
					i--;
					break;
				}
			}
		}
	}
	for(i = 0; i < 6; i++){
		if(i < 3){
			printf("Process 0 Page(%d) -> frame(%d)\n", i, r[i]);
		}
		else{
			printf("Process 1 Page(%d) -> frame(%d)\n", i, r[i]);
		}
		ascChar[r[i]*2] = asc;
		asc++;
		ascChar[r[i]*2 + 1] = asc;
		asc++;
	}
}
void result(){
	int i, j, asc = 65;
	printf("STEP3:Result\n");
	//processA
	printf("Process A:\n");
	printf("*******Page Table******\n");
	printf("-----Page-----Frame----\n");
	for(i = 0; i < 3; i++){
		printf("-\t%d \t%2d-----\n", i, r[i]);
	}
	//processB
	printf("Process B:\n");
	printf("*******Page Table******\n");
	printf("-----Page-----Frame----\n");
	for(i = 3; i < 6; i++){
		printf("-\t%d \t%2d-----\n", i, r[i]);
	}
	//logical memory
	printf("****Logical Memory*****\n");
	printf("--Page/Entry----Data---\n");
	for(i = 0; i < 12; i++, asc++){
		printf("-  %d\t%d \t   %c---\n", i/2, i, asc);
	}
	//physical memory
	printf("****Physical Memory****\n");
	printf("-Frame/Entry----Data---\n");
	j = 0;
	for(i = 0; i < MemorySize; i++){
		if(i/2 == r[0] || i/2 == r[1] || i/2 == r[2] || i/2 == r[3] || i/2 == r[4] || i/2 == r[5]){
			if(j == 0){
				printf("-  %d\t%d \t   %c---\n", i/2, i, ascChar[i/2 *2]);
				j++;
			}
			else{
				printf("-  %d\t%d \t   %c---\n", i/2, i, ascChar[i/2 *2 +1]);
				j--;
			}
		}
		else{
			printf("-  %d\t%d \t   ?---\n", i/2, i);
		}
	}
	printf("FreeFrameList[16]: ");
	for(i = 0; i < 16; i++){
		if(i == r[0] || i == r[1] || i == r[2] || i == r[3] || i == r[4] || i == r[5]){
			continue;
		}
		else{
			printf("%d ",i);
		}
	}
	printf("\n");

}

int main(){
	init();
	paging();
	result();
	return 0;
}
