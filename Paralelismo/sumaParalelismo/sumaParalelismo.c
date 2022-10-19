#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void genVectors(float *v, int TAM);
void cVecSum(float *v, float *u, float *w, int TAM);
extern void asmVecSum(float *v, float *u, float *w, int TAM);

int main(){

	srand(time(NULL));
	float *v, *u, *wc, *wasm;
	int N = 10;
	int REPS = 5, j = 0;

	/*posix_memalign((void **)&v, 16, N * sizeof(float));

	posix_memalign((void **)&u, 16, N * sizeof(float));

	posix_memalign((void **)&wc, 16, N * sizeof(float));

	posix_memalign((void **)&wasm, 16, N * sizeof(float));*/
    v = (float *)malloc(sizeof(float)*N);
    u = (float *)malloc(sizeof(float)*N);
    wc = (float *)malloc(sizeof(float)*N);
    wasm = (float *)malloc(sizeof(float)*N);
	genVectors(v, N);
	
	genVectors(u, N);

	cVecSum(v,u,wc,N);	

	asmVecSum(v,u,wasm,N);
	
	for(j = 0; j < N; j++){
		printf("El resultado de %5.2f + %5.2f es:   en C : %5.2f  en ASM\t%5.2f\n",v[j],u[j],wc[j],wasm[j]);
	}	

	return 0;
}

void genVectors(float *v, int TAM){
	int i = 0;
	float ele = 0.0;
	for(i = 0; i < TAM; i++){
		ele = (float)(rand()%100);
		ele = (sinf(ele) + cosf(ele)) / 1.4142;
		v[i] = ele;
	}
}

void cVecSum(float *v, float *u, float *w, int TAM) {
	int i = 0;
	for(i = 0; i < TAM; i++){
		w[i] = v[i] + u[i];
	}
}
