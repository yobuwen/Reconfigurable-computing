#include <stdio.h>

#define N 5
#define M 5

int c_data[M] = {0};

int A_data[M*N] = \
		{4,10,10,0,24,1,17,5,2,23,3,11,18,13,1,16,5,4,7,18,17,18,20,8,20};

int HLSResult_c[M] = {100,89,159,136,236};

void ceck_result(int *CorrectResult, int *HLSResult){
	for(int i=0; i<M; i++){
		printf("Idx %d: ERROR = %d \r\n", i, CorrectResult[i] - HLSResult[i]);
	}
}

int main(void){



	printf("checking result:\r\n");

	test(&A_data);

	ceck_result(&HLSResult_c[0], &A_data[0]);
	return 0;
}

