#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char ** V, int cant);
void buscarNombrePorID(int ID, char ** V, int cant);
int buscarNombrePorPalabra(char ** V, char * palabra, int cant);
void liberarMemoria(char **V, int cant);
int main (){
    char buff[50];
    int cantNom;
    int ID;
    char palabra[50];

    printf("Ingrese una cantidad de nombres:\n");
    scanf("%i", &cantNom);
    char ** V = (char**) malloc(sizeof(char*) * cantNom);

    for (int i=0;i<cantNom;i++){
        do{
        fflush(stdin);
        fgets(buff,sizeof(buff), stdin);
        }while(strlen(buff)==0);
        int longNom = strlen(buff);
        V[i] = (char *) malloc((sizeof(char) * longNom) + 1);
        strcpy(V[i],buff);
        
    }
    printf("\n ----Nombres ingresados----\n");

    mostrarPersonas(V,cantNom);

    printf("----------- Busqueda por ID (posicion) o por Nombre (parcial o completo) -------------\n");
    int eleccion;
    do
    {
        printf("    Para busqueda por ID presione -------->   1\n");
        printf("    Para busqueda por Nombre presione ---->   2\n");
        scanf("%d", &eleccion);

    } while (eleccion != 1 && eleccion != 2);
    if(eleccion == 1){
    do{
        printf("Ingrese un ID (1-5): \n");
        scanf("%i", &ID);
        }while(ID<0 || ID>cantNom);
        buscarNombrePorID(ID, V, cantNom);
    }
    else{ 
        printf("Ingrese el nombre que desea buscar: ");
         fflush(stdin);
        scanf("%s", palabra);

        int resultado = buscarNombrePorPalabra(V, palabra, cantNom);

        if (resultado == -1) {
            printf("No se encontro nada, codigo de error: %d", resultado);
         } else {
             printf("nombre encontrado: %s", V[resultado]);
         }
    }
liberarMemoria(V,cantNom);
return 0;
}

void mostrarPersonas(char ** V, int cant){
    for (int i=0;i<cant;i++){
        puts(V[i]);
    }
}

int buscarNombrePorPalabra(char ** V, char * palabra, int cant) { 
    for (int i = 0; i < cant; i++) {
        if (strstr(V[i], palabra) != NULL) {
            return i; // 
        }
    }
    return -1; // 
}

void buscarNombrePorID(int ID, char ** V, int cant){
        if((ID - 1) >=0 && (ID - 1)<cant){
            printf("El nombre con ID %i es %s", ID, V[ID-1]);
        }else{
            printf("No se encontro ningun nombre con ese ID");
        }
    }
    
void liberarMemoria(char ** V, int cant){
for(int i=0;i<cant;i++){
    free(V[i]);
}
free(V);

}