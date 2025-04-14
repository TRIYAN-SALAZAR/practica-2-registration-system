/*
    nombre: Jorge Alejandro Ozuna Salazar
    tema: Registro de personas
    fecha: 11 de Abril de 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

struct info_persona {
    char nombre[30];
    char calle_num[30];
    char ciudad[30];
    char estado[30];
    char codigo_postal[10];
};

int find_register(struct info_persona data[], int data_engaged[]);
void new_register(struct info_persona data[], int count, int data_engaged[]);
void show_all_registers(struct info_persona data[], int data_engaged[]);
void show_register(int index, struct info_persona data[]);

int main() {
    struct info_persona people[TAM];
    int data[TAM] = {0, 0, 0, 0, 0};
    int count = 0;
    while(1) {
        int opc;
        printf("\nMenu:\n");
        printf("1. Nuevo registro\n");
        printf("2. Mostrar todos los registros\n");
        printf("3. Buscar registro\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                new_register(people, count, data);
                count++;
                break;
            case 2:
                show_all_registers(people, data);
                break;
            case 3:
                find_register(people, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Opcion no valida.\n");
        }
    }
}

void new_register(struct info_persona data[], int count, int data_engaged[]) {
    printf("\n---NUEVO REGISTRO---\n");
    if(count < TAM) {
        printf("Nombre: ");
        scanf("%s", data[count].nombre);
        scanf("%*[^\n]%*c");

        printf("Calle y numero: ");
        scanf("%s", data[count].calle_num);
        scanf("%*[^\n]%*c");
        
        printf("Ciudad: ");
        scanf("%s", data[count].ciudad);
        scanf("%*[^\n]%*c");
        
        printf("Estado: ");
        scanf("%s", data[count].estado);
        scanf("%*[^\n]%*c");
        
        printf("Codigo postal: ");
        scanf("%s", data[count].codigo_postal);
        scanf("%*[^\n]%*c");
        
        data_engaged[count] = 1;
    } else {
        printf("No se pueden agregar mas registros.\n");
    }
}

void show_all_registers(struct info_persona data[], int data_engaged[]) {

    printf("\n---REGISTROS---\n");
    for(int i = 0; i < TAM; i++) {
        if(strlen(data[i].nombre) > 0 && data_engaged[i] == 1) {
            printf("Registro %d:\n", i + 1);
            show_register(i, data);
        }
    }
}

void show_register(int index, struct info_persona data[]) {
    printf("Nombre: %s\n", data[index].nombre);
    printf("Calle y numero: %s\n", data[index].calle_num);
    printf("Ciudad: %s\n", data[index].ciudad);
    printf("Estado: %s\n", data[index].estado);
    printf("Codigo postal: %s\n", data[index].codigo_postal);
    printf("----------------\n");
}

int find_register(struct info_persona data[], int data_engaged[]) {
    printf("\n---BUSCAR REGISTRO---\n");
    char title[30];
    printf("Ingresa una palabra clave del titulo del libro: ");
    scanf("%s", title);
    for(int i = 0; i < TAM; i++) {
        if(strlen(data[i].nombre) > 0 && data_engaged[i] == 1) {
            if(strstr(data[i].nombre, title) != NULL) {
                show_register(i, data);
            }
        }
    }
}
