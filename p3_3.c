#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
void chunksizestatic(int size){
long long num_terms = 200;
         double *arr = (double *)malloc(num_terms * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
         }
        double start,end;
	start = omp_get_wtime();
	#pragma omp parallel for schedule(static,size)
	for(int i=0;i<num_terms;i++){
                arr[i] = arr[i] + 10.098;
        }
        end = omp_get_wtime();
        printf("Chunck Size : %d \t Time required for Execution : %f\n\n",size,end-start);
}


void chunksizedynamic(int size){
long long num_terms = 200;
         double *arr = (double *)malloc(num_terms * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
         }
        double start,end;
        start = omp_get_wtime();
        #pragma omp parallel for schedule(dynamic,size)
        for(int i=0;i<num_terms;i++){
                arr[i] = arr[i] + 10.098;
        }
        end = omp_get_wtime();
        printf("Chunck Size : %d \t Time required for Execution : %f\n\n",size,end-start);
}

void chunksizenowait(){
long long num_terms = 200;
         double *arr = (double *)malloc(num_terms * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
         }
        double start,end;
        start = omp_get_wtime();
        #pragma omp parallel
	{
	#pragma omp for nowait	
        for(int i=0;i<num_terms;i++){
                arr[i] = arr[i] + 10.098;
        }
	}
        end = omp_get_wtime();
        printf("Time required for Execution : %f\n\n",end-start);
}

int main(){
	int chunksize[] = {1,5,10,15,20};
	printf("\n\t###########Static###########\n\n");
	for(int i=0;i<5;i++){
		chunksizestatic(chunksize[i]);
	}

	printf("\n\t###########Dynamic###########\n\n");
        for(int i=0;i<5;i++){
                chunksizestatic(chunksize[i]);
        }
	printf("\n\t###########Nowait###########\n\n");
	chunksizenowait();
        return 0;
}
