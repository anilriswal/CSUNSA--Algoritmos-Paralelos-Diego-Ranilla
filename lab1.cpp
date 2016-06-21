#include <iostream>
//#include <stdlib.h>
#define tam 800
#define bloque 80

using namespace std;

void multiplicacion(int A[tam][tam],int B[tam][tam]){
	int C[tam][tam];

	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			for(int k=0;k<tam;k++){
				C[i][j] += A[j][k]*B[k][j];
			}
		}
	}
}

//en construccion por ahora

void multiplicacion2(int A[tam][tam],int B[tam][tam]){
	int C[tam][tam];
	C[0][0]=0;

	for( int i1=0;i1<(tam/bloque);++i1)
    {
        for(int j1=0;j1<(tam/bloque);++j1)
        {
            for(int k1=0;k1<(tam/bloque);++k1)
            {
                for(int i=i1=0;i<i1+bloque-1;++i)
                {
                    for(int j=j1=0;j<j1+bloque-1;++j)
                    {
                        for(int k=k1;k<k1+bloque-1;++k)
                        {               
                            C[i][j] = C[i][j] + A[i][k] * B[k][j];
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

	for(int i=0; i<tam;i++){
		for(int j=0; j<tam;j++){
			A[i][j]=i+j;
		}
	}

	for(int i=0; i<tam;i++){
		for(int j=0; j<tam;j++){
			B[i][j]=i+j;
		}
	}

	multiplicacion(A,B);
}