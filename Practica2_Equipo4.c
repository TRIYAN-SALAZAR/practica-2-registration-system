/*
    nombre: Jorge Alejandro Ozuna Salazar
    tema: Registro de personas
    fecha: 11 de Abril de 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define MAX_INPUT 30
#define MAX_CP 10

struct info_persona {
    char nombre[MAX_INPUT];
    char calle_num[MAX_INPUT];
    char ciudad[MAX_INPUT];
    char estado[MAX_INPUT];
    char codigo_postal[MAX_CP];
};

int find_register(struct info_persona data[], int data_engaged[]);

void menu(int *opc);
void clean_buffer();
void new_register(struct info_persona data[], int count, int data_engaged[]);
void show_all_registers(struct info_persona data[], int data_engaged[]);
void show_register(int index, struct info_persona data[]);

int main() {
    struct info_persona people[TAM];
    int data[TAM] = {0, 0, 0, 0, 0};
    int count = 0;
    while(1) {
        int opc;
        menu(&opc);

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

void menu(int *opc) {
    printf("\nMenu:\n");
    printf("1. Nuevo registro\n");
    printf("2. Mostrar todos los registros\n");
    printf("3. Buscar registro\n");
    printf("4. Salir\n");
    printf("Selecciona una opcion: ");
    scanf("%d", opc);
}

void new_register(struct info_persona data[], int count, int data_engaged[]) {
    printf("\n---NUEVO REGISTRO---\n");
    if (count < TAM) {
        printf("Nombre: ");
        if (fgets(data[count].nombre, MAX_INPUT, stdin) != NULL) {
            data[count].nombre[strcspn(data[count].nombre, "\n")] = '\0';
        } else {
            clean_buffer();
            printf("Error al leer el nombre.\n");
            return;
        }

        printf("Calle y numero: ");
        if (fgets(data[count].calle_num, MAX_INPUT, stdin) != NULL) {
            data[count].calle_num[strcspn(data[count].calle_num, "\n")] = '\0';
        } else {
            clean_buffer();
            printf("Error al leer la calle y numero.\n");
            return;
        }

        printf("Ciudad: ");
        if (fgets(data[count].ciudad, MAX_INPUT, stdin) != NULL) {
            data[count].ciudad[strcspn(data[count].ciudad, "\n")] = '\0';
        } else {
            clean_buffer();
            printf("Error al leer la ciudad.\n");
            return;
        }

        printf("Estado: ");
        if (fgets(data[count].estado, MAX_INPUT, stdin) != NULL) {
            data[count].estado[strcspn(data[count].estado, "\n")] = '\0';
        } else {
            clean_buffer();
            printf("Error al leer el estado.\n");
            return;
        }

        printf("Codigo postal: ");
        if (fgets(data[count].codigo_postal, MAX_INPUT, stdin) != NULL) {
            data[count].codigo_postal[strcspn(data[count].codigo_postal, "\n")] = '\0';
        } else {
            clean_buffer();
            printf("Error al leer el codigo postal.\n");
            return;
        }

        data_engaged[count] = 1;
        printf("Registro agregado con exito.\n");
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

void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Vacía el búfer
    }
}