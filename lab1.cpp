#include <iostream>
#include <math.h>
//#include <stdlib.h>
#define tam 500
#define bloque 10

using namespace std;


void imprimir_matriz(int A[tam][tam]){
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

void multiplicacion(int A[tam][tam],int B[tam][tam],int C[tam][tam]){

	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			for(int k=0;k<tam;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
}

//en construccion por ahora

void multiplicacion2(int A[tam][tam],int B[tam][tam],int C[tam][tam]){


	for(int i1=0;i1<tam;i1=i1+bloque){
		for(int j1=0;j1<tam;j1=j1+bloque){
			for(int k1=0;k1<tam;k1=k1+bloque){

				for(int i=i1;i<=min(i1+bloque-1,tam);i++){
					for(int j=j1;j<=min(j1+bloque-1,tam);j++){
						for(int k=k1;k<=min(k1+bloque-1,tam);k++){
							C[i][j] = C[i][j]+(A[i][k]*B[k][j]);
						}
					}
				}
			}
		}
	}
}


int main(){

	int A[tam][tam];
	int B[tam][tam];
	int C[tam][tam];
	int a[tam][tam];
	int b[tam][tam];
	int c[tam][tam];

	for(int i=0; i<tam;i++){
		for(int j=0; j<tam;j++){
			A[i][j]=i+j;
			a[i][j]=i+j;
		}
	}

	for(int i=0; i<tam;i++){
		for(int j=0; j<tam;j++){
			B[i][j]=i+j;
			b[i][j]=i+j;
		}
	}

	for(int i=0; i<tam;i++){
		for(int j=0; j<tam;j++){
			C[i][j]=0;
			c[i][j]=0;
		}
	}

	/*imprimir_matriz(a);
	cout<<endl;
	imprimir_matriz(b);
	cout <<endl;*/
	multiplicacion(a,b,c);
	imprimir_matriz(c);
	cout <<endl;
	/*imprimir_matriz(A);
	cout<<endl;
	imprimir_matriz(B);
	cout <<endl;*/
	multiplicacion2(A,B,C);
	imprimir_matriz(C);
	
}