#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EULER 2.71828


double extern hallaPotenciaASM(int x,int i);
double extern hallaFactorialASM(int i);


double hallaPotencia(int x,int n){
    double resultado=1;
    for(int i=0;i<n;i++){
        resultado*=x;
    }
    return resultado;
}

double hallaFactorial(int n){
    double resultado=1;
    for(int i=2;i<=n;i++){
        resultado*=i;
    }
    return resultado;
}

double hallaEulerTaylor(int x,int n){
    double potencia,factorial,resultado=0;
    for(int i=0;i<n;i++){
        potencia=hallaPotencia(x,i);
        factorial=hallaFactorial(i);
        resultado+=(potencia/factorial);
    }
    return resultado;
}

double hallaEulerTaylorASM(int x,int n){
    double potencia=0,factorial=1,resultado=0;
    for(int i=0;i<n;i++){
        potencia=hallaPotenciaASM(x,i);
        factorial=hallaFactorialASM(i);
        resultado+=(potencia/factorial);
        printf(" %lf %lf\n",potencia,factorial);
    }
    return resultado;
}



int main (){
    int n=5,i=14;
    double taylorEulerC,taylorEulerASM;
    taylorEulerC=hallaEulerTaylor(n,30);
    taylorEulerASM=hallaEulerTaylorASM(5,30);
    printf("El resultado es: %lf\n",pow(EULER,n));
    printf("El resultado en C es: %lf\n",taylorEulerC);
    printf("El resultado con ASM es: %lf\n",taylorEulerASM);
}
