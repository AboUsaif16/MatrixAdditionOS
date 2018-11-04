#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct strc{
	int e1 , e2;
	int *s;
};

void *add(void *var){

	struct strc *data = var;
	int sum = 0;

	sum = data->e1 + data->e2;
	*(data->s) = sum;

	pthread_exit(0);
}

int main(){

	int K;
	int M;
	printf( "Number of rows :");
	scanf("%d",&M);
	printf( "Number of columns :");
	scanf("%d",&K);
	int A[M][K];
	int B[M][K];
	int C[M][K];
	printf( "---------------\nEnter Matrix A : \n");
	int q;
	int e;
	int w;
	for (q=0;q<M;q++){
		for (w=0;w<K;w++){
			scanf("%d",&e);
			A[q][w]=e;
		}
	}
	printf( "---------------\nEnter Matrix B : \n");
	w=0;
	q=0;
	for (q=0;q<M;q++){
		for (w=0;w<K;w++){
			scanf("%d",&e);
			B[q][w]=e;
		}
	}
	int i, j;
	for (i = 0; i < M; i++){
		for (j = 0; j < K; j++){

		struct strc *data = (struct strc *)malloc(sizeof(struct strc));
		data->e1 = A[i][j];
		data->e2 = B[i][j];
		data->s = &C[i][j];

		pthread_t threadID ;
		pthread_attr_t attributes;
		pthread_attr_init(&attributes);
		pthread_create(&threadID, &attributes, add, data);
		pthread_join(threadID, NULL);
		}
	}

	printf("===============\nSum of Matrix A and B:\n");
	for (i = 0; i < M; i++)
	{
	for (j = 0; j < K; j++)
	{
	    printf("%d ", C[i][j]);
	}
	printf("\n");
	}
}

