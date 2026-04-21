#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char * V[]);
void buscarNombre(char * V[], char palabra[]);
int main (){
    char buff[50];
    char * V[5];
    char palabra[50];
    printf("Ingrese 5 nombres:\n");
    for (int i=0;i<5;i++){
        do{fflush(stdin);
        gets(buff);
        }while(strlen(buff)==0);
        int longNom = strlen(buff);
        V[i] = (char *) malloc((sizeof(char) * longNom) + 1);
        strcpy(V[i],buff);
        
    }
    printf("\n ----Nombres ingresados----\n");
    mostrarPersonas(V);

    printf("Ingrese el nombre que desea buscar: ");
    fflush(stdin);
    scanf("%s", palabra);

    
    buscarNombre(V, palabra);

}

void mostrarPersonas(char * V[]){
    int cantidad=5;
    for (int i=0;i<cantidad;i++){
        puts(V[i]);
    }
}

void buscarNombre(char * V[], char palabra[]){
    int aux=-1;
    
    for(int i=0;i<5;i++){
        if (strstr(V[i], palabra) != NULL){
           printf("Se encontro el nombre %s", V[i]); 
           aux=1;
        }
    }
    if (aux== -1){
        printf("-1");
    }
}