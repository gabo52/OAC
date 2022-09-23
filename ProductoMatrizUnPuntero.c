#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void imprimeMatriz(int *M,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%3d ",M[(i*N)+j]);
        }
    }
    printf("\n");
}

void initMatrix(int *M,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            M[(i*N)+j] = rand () % 10;
        }
    }
}


void productoMatriz(int *M1,int *M2,int *R,int N){
    for (int a = 0; a < N; a++) {
        // Dentro recorremos las filas de la primera (A)
        for (int i = 0; i < N; i++) {
            int suma = 0;
            // Y cada columna de la primera (A)
            for (int j = 0; j < N; j++) {
                // Multiplicamos y sumamos resultado
                suma += M1[(i*N)+j] * M2[(i*N)+a];
            }
            // Lo acomodamos dentro del producto
            R[(i*N)+a] = suma;
        }
    }
}

void matmatblock(int *A, int *B, int *C, int N, int block)
{
    int tmp = 0;
    for(int i = 0; i < N; i+=block)
    {
        for(int j = 0; j < N; j+=block)
        {
            for(int k = 0; k < N; k+=block)
            {
                for(int ii = i; ii < i + block; ii++)
                {
                    for(int jj = j; jj < j + block; jj++)
                    {
                        tmp = C[(ii*block)+jj];
                        for(int kk = k; kk < k + block; kk++)
                        {
                            tmp += A[(ii*N)+kk]*B[(kk*N)+jj];
                        }
                        C[(ii*block)+jj] = tmp;
                    }
                }
            }
        }
    }
}



void productoMatrizBloques(int *a,int *b,int *c,int N,int s){
    int temp;
    for(int jj=0;jj<N;jj+= s){
        for(int kk=0;kk<N;kk+= s){
            for(int i=0;i<N;i++){
                for(int j = jj; j<((jj+s)>N?N:(jj+s)); j++){
                    temp = 0;
                    for(int k = kk; k<((kk+s)>N?N:(kk+s)); k++){
                        temp += a[(i*N)+k]*b[(k*N)+j];
                    }
                    c[(i*N)+j] += temp;
                }
            }
        }
    }
}


int main(){
        int *Matrix1,*Matrix2,*Result,N=1024;
    Matrix1 = malloc(N * N *sizeof(int));
    Matrix2 = malloc(N * N *sizeof(int));
    Result = malloc(N * N * sizeof(int));

    initMatrix(Matrix1,N);
    initMatrix(Matrix2,N);

    //imprimeMatriz(Matrix1,N);
    //imprimeMatriz(Matrix2,N);
    
    struct timespec ti, tf;
    double elapsed;
    //imprimeMatriz(Result,N);

    clock_gettime(CLOCK_REALTIME, &ti);
    //productoMatrizBloques(Matrix1,Matrix2,Result,N,128);
    matmatblock(Matrix1,Matrix2,Result,N,128);
    clock_gettime(CLOCK_REALTIME, &tf);
    elapsed = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
    printf("Tiempo en nanosegundos con blocking: %.2lf\n", elapsed);
    //imprimeMatriz(Result,N);
    printf("\n");

    
    clock_gettime(CLOCK_REALTIME, &ti);
    productoMatriz(Matrix1,Matrix2,Result,N);
    clock_gettime(CLOCK_REALTIME, &tf);
    elapsed = (tf.tv_sec - ti.tv_sec) * 1e9 + (tf.tv_nsec - ti.tv_nsec);
    printf("Tiempo en nanosegundos sin blocking: %.2lf\n", elapsed);
    printf("\n");
    //imprimeMatriz(Result,N);
}
