#include<stdio.h>
#include<stdlib.h>
#define FILAS 5
#define COLUMNAS 12

void CargaMatriz(int** matriz);
void MuestraMatriz(int** matriz);
void Promedio(int **matriz);
void MaximoYMinimo(int **matriz);
int main(){
    int **matriz;
    matriz=(int**)malloc(sizeof(int*)*FILAS);
    CargaMatriz(matriz);
    MuestraMatriz(matriz);
    Promedio(matriz);
    MaximoYMinimo(matriz);

}
void CargaMatriz(int** matriz){
    int i, j;
    for(i=0;i<FILAS;i++){
        matriz[i]=(int *)malloc(sizeof(int)*COLUMNAS);
        for(j=0;j<COLUMNAS;j++){
            matriz[i][j]=rand()%40001+10000;
        }
    }
}
void MuestraMatriz(int** matriz){
    int i, j;
    for(i=0;i<FILAS;i++){
        for(j=0;j<COLUMNAS;j++){
            printf("%8d", matriz[i][j]);
        }
        printf("\n");
    }
}
void Promedio(int **matriz){
    int i,j;
    float prom;
    for(i=0;i<FILAS;i++){
        prom=0;
        for(j=0;j<COLUMNAS;j++){
            prom+= matriz[i][j];
        }
        prom /= COLUMNAS;
        printf("\nPROMEDIO %d:    %f", (i+2018),prom);
    }
}
void MaximoYMinimo(int **matriz){
    int i, j;
    int max, min;
    int indiceMax=0, indiceMin=0;
    for(i=0;i<FILAS;i++){
        max=0;
        min=9999999;
        for(j=0;j<COLUMNAS;j++){
            if(max<matriz[i][j]){
                max=matriz[i][j];
                indiceMax=j;
            }
            if(min>matriz[i][j]){
                min=matriz[i][j];
                indiceMin=j;
            }
        }
            printf("\n=======================ANIO %d ===========================\n", (i+2018));
            printf(".MAXIMO= %d", matriz[i][indiceMax]);
            printf("\n.MINIMO= %d", matriz[i][indiceMin]);
    }
}