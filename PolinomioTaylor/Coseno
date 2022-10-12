#include <stdio.h>
#include <math.h>
#include <stdlib.h>

extern double  hallaPotenciaASM(int i,int x);
extern double  hallaFactorialASM(int i);
double hallaPotencia(int n,int x);
double hallaFactorial(int i);

double hallaCosTaylorASM(int x,int n){
    double potencia,factorial,resultado=0;
    for(int i=0;i<n;i++){
        potencia=hallaPotenciaASM(i,x);
        factorial=hallaFactorialASM(i);
        resultado+=(potencia/factorial);
        printf("%lf %lf\n",factorial,potencia);
    }
    return resultado;
}

double hallaCosTaylor(int x,int iteraciones){
    double potencia,factorial,resultado=0;
    for(int i=0;i<iteraciones;i++){
        potencia=hallaPotencia(i,x);
        factorial=hallaFactorial(i);
        resultado+=(potencia/factorial);
        printf("%lf %lf\n",factorial,potencia);
    }
    printf("\n");
    return resultado;
}
double hallaPotencia(int n,int x){
    int veces=2*n;
    double aux=1;
    for(int i=0;i<veces;i++){
        aux*=x;
    }
    if(n%2!=0)aux*=-1;
    return aux;
}

double hallaFactorial(int i){
    int limite=i*2;
    double resultado=1;
    for(int j=2;j<=limite;j++){
        resultado*=j;
    }
    return resultado;
}


int main(){
    int n=5;
    struct timespec ti,tf;
    double elapsed,taylorC,taylorASM;
    taylorC=hallaCosTaylor(n,20);
    taylorASM=hallaCosTaylorASM(n,20);
    printf("Hola unu");
    printf("El resultado con math es: %lf\n",cos(n));
    printf("El resultado en C es: %lf\n",taylorC);
    printf("El resultado con ASM es: %lf\n",taylorASM);
    //printf("EL factorial de %d con assembly es: %lf",n,hallaFactorialASM(5));
}
