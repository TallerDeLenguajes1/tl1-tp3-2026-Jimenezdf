#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char * V[]);
void buscarNombrePorID(int ID, char * V[]);
int buscarNombrePorPalabra(char * V[], char palabra[]);
int main (){
    char buff[50];
    char * V[5];
    int ID;
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

    do{
        printf("Ingrese un ID (1-5): \n");
        scanf("%i", &ID);
        }while(ID<0 || ID>5);
        buscarNombre(ID, V);

    printf("Ingrese el nombre que desea buscar: ");
    fflush(stdin);
    scanf("%s", palabra);

int resultado = buscarNombre(V, palabra);

if (resultado == -1) {
    printf("No se encontro nada, codigo de error: %d", resultado);
} else {
    printf("nombre encontrado: %s", V[resultado]);
}
}

void mostrarPersonas(char * V[]){
    int cantidad=5;
    for (int i=0;i<cantidad;i++){
        puts(V[i]);
    }
}

int buscarNombrePorPalabra(char *V[], char *palabra) { // Cambiamos void por int
    for (int i = 0; i < 5; i++) {
        if (strstr(V[i], palabra) != NULL) {
            return i; // Retornamos la posición (un número entero)
        }
    }
    return -1; // Si llegó acá es porque no encontró nada. Retornamos -1.
}

void buscarNombrePorID(int ID, char * V[]){
        if((ID - 1) >=0 && (ID - 1)<5){
            printf("El nombre con ID %i es %s", ID, V[ID-1]);
        }else{
            printf("No se encontro ningun nombre con ese ID");
        }
    }
    
