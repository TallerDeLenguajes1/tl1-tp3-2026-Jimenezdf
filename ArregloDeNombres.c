#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char * V[]);
void buscarNombre(int ID, char * V[]);
int main (){
    char buff[50];
    char * V[5];
    int ID;
    printf("Ingrese 5 nombres:\n");
    for (int i=0;i<5;i++){
        fflush(stdin);
        scanf("%s", buff);
        int longNom = strlen(buff);
        V[i] = (char *) malloc((sizeof(char) * longNom) + 1);
        strcpy(V[i],buff);
        
    }
    printf("\n----Nombres ingresados----\n");
    mostrarPersonas(V);

    do{
        printf("Ingrese un ID (1-5): \n");
        scanf("%i", &ID);
        }while(ID<0 || ID>5);
        buscarNombre(ID, V);
}

void mostrarPersonas(char * V[]){
    int cantidad=5;
    for (int i=0;i<cantidad;i++){
        printf("%s\n", V[i]);
    }
}

void buscarNombre(int ID, char * V[]){
        if((ID - 1) >=0 && (ID - 1)<5){
            printf("El nombre con ID %i es %s", ID, V[ID-1]);
        }else{
            printf("No se encontro ningun nombre con ese ID");
        }
    }
    
