#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char * V[]);
int main (){
    char buff[50];
    char * V[5];
    printf("Ingrese 5 nombres:\n");
    for (int i=0;i<5;i++){
        fflush(stdin);
        scanf("%s", buff);
        int longNom = strlen(buff);
        V[i] = (char *) malloc((sizeof(char) * longNom) + 1);
        strcpy(V[i],buff);
        
    }
    mostrarPersonas(V);
}

void mostrarPersonas(char * V[]){
    int cantidad=5;
    for (int i=0;i<cantidad;i++){
        printf("%s\n", V[i]);
    }
}