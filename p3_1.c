#include<stdio.h>
#include<omp.h>

int main(){
long long count=0,count1=0;
int i;

double arr1[10000];
double arr2[10000];
for(int i=0;i<10000;i++){
  arr1[i]=i+2;
}
for(int i=9999;i>0;i--){
  arr2[i]=i+4;
  
}
double start1=omp_get_wtime();
for(i=0;i<10000;i++){
count=count+arr1[i]*arr2[i];

}
double end1=omp_get_wtime();
printf("Sequential Count =%lld\n",count);
printf("Sequential time =%f\n",end1-start1);

double start=omp_get_wtime();
#pragma opm parallel for reduction(+:count1)
for(i=0;i<10000;i++){
count1=count1+arr1[i]*arr2[i];

}
double end=omp_get_wtime();
printf("Prallel Count =%lld\n",count1);
printf("Prallel Time =%f",end-start);
return 0;
}
