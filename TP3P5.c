#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILAS 5

void CargaNombres(char **matriz);
void MuestraNombres(char **matriz);
void LiberaMemoria(char **matriz);
int main(){
    char **matriz;
    matriz=(char**)malloc(sizeof(char*)*FILAS);
    CargaNombres(matriz);
    MuestraNombres(matriz);
    LiberaMemoria(matriz);
}
void CargaNombres(char **matriz){
    int i;
    for(i=0;i<FILAS;i++){
        int cantLetras;
        printf("\nIngrese la cantidad de letras del nombre %d:  ", i+1);
        scanf("%d", &cantLetras);
        matriz[i]=(char*)malloc(sizeof(char)*(cantLetras+1));
        printf("\nNOMBRE:  ");
        fflush(stdin);
        gets(matriz[i]);     
    }
}
void MuestraNombres(char **matriz){
    int i;
    for(i=0;i<FILAS;i++){
        printf("\nNOMBRE %d:  %s", (i+1), matriz[i]);
    }
}
void LiberaMemoria(char **matriz){
    int i=0;
    for(i=0;i<FILAS;i++){
        free(matriz[i]);
    }
    free(matriz);
}