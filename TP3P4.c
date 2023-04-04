#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAMA 50

typedef struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;

void CargaVector(Cliente* arre, int cant);
void MuestraVector(Cliente*arre, int cant);
float CostoTotalProducto(Cliente arre, char*producto);
float TotalPagar(Cliente arre);
void TotalPagarCadaCLiente(Cliente* arre, int cant);

int main(){
    int cantClientes;
    printf("Ingrese la cantidad de clientes que visitara:  ");
    scanf("%d",&cantClientes );
    Cliente* visitador =(Cliente*)malloc(sizeof(Cliente)*cantClientes);
    CargaVector(visitador,cantClientes);
    MuestraVector(visitador,cantClientes);

    //Costo total
    char Producto[TAMA];
    int numeroCliente;
    float costoTot;
    printf("\n*****************************COSTO PRODUCTO************************\n");
    printf("\nIngrese su id: ");
    scanf("%d",&numeroCliente);
    printf("\nIngrese de que producto desea conocer su costo total:  ");
    fflush(stdin);
    gets(Producto);
    costoTot=CostoTotalProducto(visitador[numeroCliente],Producto);
    printf("Costo total del producto %s:  %.2f", Producto, costoTot);
    printf("\n//////////////////////TOTAL PAGAR CLIENTE//////////////\n");
    TotalPagarCadaCLiente(visitador,cantClientes);
    free(visitador);
}
void CargaVector(Cliente *arre, int cant){
    int i,j;
    int cantLetras;
    int indiceTipoP;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};    
    for(i=0;i<cant;i++){
        arre[i].ClienteID=i;

        //Ingreso el nombre
        printf("\nCantidad Letras Nombre:  ");
        scanf("%d", &cantLetras);
        printf("\nNombre Cliente:  ");
        arre[i].NombreCliente=(char*)malloc(sizeof(char)*(cantLetras+1));
        fflush(stdin);
        gets(arre[i].NombreCliente);

        arre[i].CantidadProductosAPedir=1+rand()%5;
        
        //Productos
        arre[i].Productos=(Producto*)malloc(sizeof(Producto)*arre[i].CantidadProductosAPedir);
        for(j=0;j<arre[i].CantidadProductosAPedir;j++){
            arre[i].Productos[j].ProductoID=j;
            arre[i].Productos[j].Cantidad=1+rand()%10;
            //Tipo Producto
            arre[i].Productos[j].TipoProducto=TiposProductos[(rand()%5)];
            //
            arre[i].Productos[j].PrecioUnitario=10+(rand()%91)*100/100;
        }
    }
}

void MuestraVector(Cliente*arre, int cant){
    int i,j;
    for(i=0;i<cant;i++){
        printf("\n==========================DATOS CLIENTE %d =======================\n",i);
        printf("\nId:  %d", arre[i].ClienteID);
        printf("\nNombre Cliente: %s", arre[i].NombreCliente);
        printf("\nCantidad de productos a pedir: %d", arre[i].CantidadProductosAPedir);
        for(j=0;j<arre[i].CantidadProductosAPedir;j++){
            printf("\n-----------------Datos Producto %d-----------", (j+1));
            printf("\nID: %d", arre[i].Productos[j].ProductoID);
            printf("\nCantidad: %d", arre[i].Productos[j].Cantidad);
            printf("\nTipo Producto; %s",arre[i].Productos[j].TipoProducto);
            printf("\nPrecio Producto: %.2f", arre[i].Productos[j].PrecioUnitario);
        }
    }
}
float CostoTotalProducto(Cliente arre, char*producto){
    int i,j;
    float total=0;
        for(j=0;j<arre.CantidadProductosAPedir;j++){
            if(strcmp(arre.Productos[j].TipoProducto, producto)==0){
                total+=(arre.Productos[j].PrecioUnitario)*arre.Productos[j].Cantidad;
            }
        }
    return(total);
    }


float TotalPagar(Cliente arre){
    int i, j;
    float tot=0;
    for(i=0;i<arre.CantidadProductosAPedir;i++){
        tot+=(arre.Productos[i].Cantidad*arre.Productos[i].PrecioUnitario);
    }
    return(tot);
}

void TotalPagarCadaCLiente(Cliente* arre, int cant){
    int i;
    for(i=0;i<cant;i++){
        printf("\nTOTAL PAGAR CLIENTE %d:  %.2f", i, TotalPagar(arre[i]));
    }
}