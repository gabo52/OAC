#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


extern float asmInnerProd(float *arr1,float *arr2,int N);
extern float simdInnerProd(float *arr1,float *arr2,int N);


float cInnerProd(float *arr1,float *arr2,int N){
    float sol=0;
    for(int i=0;i<N;i++){
        sol+=(arr1[i]*arr2[i]);
    }
    return sol;
}

int main(){
    float *arr1,*arr2,N=16;
    float sol;
    arr1 = (float *)malloc(N*sizeof(float));
    arr2 = (float *)malloc(N*sizeof(float));

    for(int i=0;i<N;i++){
        arr1[i]=i;
        arr2[i]=i;
    }

    sol=cInnerProd(arr1,arr2,N);
    printf("La solución en C es: %.2f\n",sol);
    sol=asmInnerProd(arr1,arr2,N);
    printf("La solución en ASM es: %.2f\n",sol);
    sol=simdInnerProd(arr1,arr2,N);
    printf("La solución con SIMD es: %.2f\n",sol);
}
