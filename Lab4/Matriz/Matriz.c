#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void extern ASMConstrastStretch(int *matIn,int *matOut,int N,int minCs,int maxCs,int max);
void extern SIMDConstrastStretch(int *matIn,int *matOut,int N,int minCs,int maxCs,int max);


void CconstrastStretch(int *matIn,int *matOut,int N,int minCs,int maxCs,int max){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matOut[i*N+j]= round(matIn[i*N+j]*((double)(maxCs-minCs)/(max)))+minCs;
        }
    }
}

void llenaArreglo(int *matIn,int n,int m,int min,int max){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matIn[i*n+j]= rand () % (max-min+1) + min;
        }
    }
}

void imprimeArreglo(int *matriz,int m,int n){
    for(int i=0;i<n;i++){
        printf("[");
        for(int j=0;j<m;j++){
            printf("%2d ",matriz[i*n+j]);
        }
        printf("] \n");
    }
    printf("\n");
}

int main(){
    int N=4;
    int *matIn, *matOut;
    int minCs,maxCs,min,max;
    matIn = (int *)malloc(sizeof(int)*N*N);
    matOut = (int *)malloc(sizeof(int)*N*N);
    minCs=4;
    maxCs=10;
    min=0;
    max=14;
    llenaArreglo(matIn,N,N,min,max);
    imprimeArreglo(matIn,N,N);
    CconstrastStretch(matIn,matOut,N,minCs,maxCs,max);
    imprimeArreglo(matOut,N,N);
    ASMConstrastStretch(matIn,matOut,N,minCs,maxCs,max);
    imprimeArreglo(matOut,N,N);
    SIMDConstrastStretch(matIn,matOut,N,minCs,maxCs,max);
    imprimeArreglo(matOut,N,N);
    
    return 0;
}
