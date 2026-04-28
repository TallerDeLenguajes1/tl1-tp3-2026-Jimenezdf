#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto { 
int ProductoID;     //Numerado en ciclo iterativo
int Cantidad;       // entre 1 y 10 
char *TipoProducto;   // Algún valor del arreglo TiposProductos       
float PrecioUnitario;  // entre 10 - 100 
}Producto;  

typedef struct Cliente {   
int ClienteID;      // Numerado en el ciclo iterativo         
char *NombreCliente;   // Ingresado por usuario
int CantidadProductosAPedir;  // (aleatorio entre 1 y 5)  
Producto *Productos;   //El tamaño de este arreglo depende de la variable  

}Cliente;



int main(){

srand(time(NULL));
int cantClientes;
do{
   printf("----Ingrese la cantidad de clientes (1-5)----\n");
    scanf("%i", &cantClientes); 
    
 }while((cantClientes<1) || (cantClientes>5));
Cliente * Clientes = (Cliente *)malloc(sizeof(Cliente) * cantClientes);


for(int i=0;i<cantClientes;i++){
    Clientes[i].ClienteID=i+1;
    printf("Ingrese el nombre del cliente: %i\n", i+1);
    char buff[50];
    scanf("%s", buff);
    Clientes[i].NombreCliente = (char *) malloc(sizeof(char) * sizeof(strlen(buff)+1));
    strcpy(Clientes[i].NombreCliente,buff);
    int cantProd = (rand() % 4) + 1;
    Clientes[i].CantidadProductosAPedir=cantProd;

    Clientes[i].Productos = (Producto *) malloc(sizeof(Producto) * Clientes[i].CantidadProductosAPedir); 
    for(int j=0;j<Clientes[i].CantidadProductosAPedir;j++){
        Clientes[i].Productos[j].ProductoID=j+1;
        int cantTipoP = (rand()%10) + 1;
        Clientes[i].Productos[j].Cantidad = cantTipoP;
        int tipoP = (rand()%5) +1;

        Clientes[i].Productos[j].TipoProducto = TiposProductos[tipoP];
        float precio = (rand() %91) + 10;
        Clientes[i].Productos[j].PrecioUnitario=precio;
    }


}




return 0;

}