#include<stdio.h>
#include<omp.h>
int main(){
int a=1,b=0,c=0;
int i=0,n=0;
printf ("Enter n for fibonisis series ");
scanf("%d",&n);
int arr[n];
double start=omp_get_wtime();

#pragma omp parallel 
{
#pragma omp for 
for(i=0;i<n;i++)
 #pragma omp critical // Prevent race conditions
{
  printf(" %d",c);
 
  c=a+b;
  a=b;
  b=c;
    }
}
double end =omp_get_wtime();
double time_parallel=end-start;
printf("\n Time Taken for Parallel Execution =%f\n",time_parallel);
a=1,b=0,c=0;
double start1=omp_get_wtime();
for(i=0;i<n;i++)

{
  printf(" %d",c);
 
  c=a+b;
  a=b;
  b=c;
  

  }

double end1=omp_get_wtime();
double time_seq=end1-start1;
printf("\n Time Taken for Parallel Execution =%f",time_seq);

 int num_threads;
    
    #pragma omp parallel
    {
        #pragma omp single
        num_threads = omp_get_num_threads();
    }

    double P = 0.9; // Assuming 90% parallelizable workload
    double theoretical_speedup = 1 / ((1 - P) + (P / num_threads));
    double actual_speedup = time_seq / time_parallel;

    // Print speedup results
    printf("\nTheoretical Speedup (Amdahl’s Law) = %f", theoretical_speedup);
    printf("\nActual Speedup = %f\n", actual_speedup);
return 0;
}
