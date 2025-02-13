#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define Buffer_size 5
#define Num_item 10

int buffer[Buffer_size];
int count=0;
int in=0,out=0;

void producer(){
  for(int i=1;i<=Num_item;i++){
  while(count== Buffer_size);
  
  #pragma omp critical
  {
      buffer[in]=i;
      printf("Produced :%d\n",i);
      in=(in+1)%Buffer_size;
      count++;} } }

void consumer(){
  for(int i=1;i<=Num_item;i++){
  while(count==0);
  
  #pragma omp critical
  {
    int item=buffer[out];
    printf("Consumed :%d\n",item);
    out=(out+1)%Buffer_size;
    count--; } } }
int main(){
  #pragma omp parallel sections
  {
    #pragma omp section
    producer();
    
    #pragma omp section
    consumer();
  }
  return 0;
}
/*int Buffer_size = 5;  // Global variable instead of #define or const
int Num_item = 10;    // Global variable instead of #define or const

int buffer[5];  // Directly using a size of 5
int count = 0;
int in = 0, out = 0; instead of  

#define Buffer_size 5
#define Num_item 10

int buffer[Buffer_size];
int count=0;
int in=0,out=0;*/
