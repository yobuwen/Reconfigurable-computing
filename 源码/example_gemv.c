#include<string.h>

#define N 5
#define M 5

void test(volatile int *A)
{
#pragma HLS PIPELINE

#pragma HLS INTERFACE m_axi depth=32 port=A offset=slave
#pragma HLS INTERFACE s_axilite port=return

	int b[N] = {4,2,4,4,1};

	int A_tmp[M * N]={0};
	int c_tmp[M]={0};

	memcpy(A_tmp,(int*)A, M * N * sizeof(int));

example_gemv_label1:
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			c_tmp[i] += A_tmp[i * M + j] * b[j];
		}
	}

	memcpy((int*)A, c_tmp, M * sizeof(int));

}
