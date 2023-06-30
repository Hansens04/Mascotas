#include <stdio.h>

#define MAX_MASCOTAS 100

int main() {
    int opcion;
    int id = 1;
    char mascotas[MAX_MASCOTAS][100];
    int edades[MAX_MASCOTAS];
    int facturaTotal = 0;
    int serviciosRealizados[4] = {0};

    do {
        printf("----- Menu -----\n");
        printf("1. Ingresar Mascota\n");
        printf("2. Servicios\n");
        printf("3. Facturar\n");
        printf("4. Cerrar programa\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ha seleccionado 'Ingresar Mascota'\n");
                if (id < MAX_MASCOTAS) {
                    printf("Ingrese el nombre de la mascota: ");
                    scanf("%s", mascotas[id]);
                    printf("Ingrese el tipo de mascota: ");
                    scanf("%s", mascotas[id+1]);
                    printf("Ingrese la edad de la mascota: ");
                    scanf("%d", &edades[id]);
                    printf("Ingrese el nombre del dueno: ");
                    scanf("%s", mascotas[id+2]);
                    printf("La mascota con ID %d ha sido ingresada\n", id);
                    id += 3;
                } else {
                    printf("Limite de mascotas alcanzado\n");
                }
                break;
            case 2:
                printf("Ha seleccionado 'Servicios'\n");
                printf("-----------------------------------------------------\n");
                printf("| Servicio              | Descripcion             | Precio  | ID Servicio |\n");
                printf("-----------------------------------------------------\n");
                printf("| Peinado para Mascota  | Servicio de peinado     | $10     | 1           |\n");
                printf("| Spa para Mascota      | Servicio de spa         | $20     | 2           |\n");
                printf("| Lavado para Mascota   | Servicio de lavado      | $15     | 3           |\n");
                printf("| Desparasitante        | Servicio desparasitante | $5      | 4           |\n");
                printf("-----------------------------------------------------\n");
                break;
            case 3:
                printf("Ha seleccionado 'Facturar'\n");
                int idMascota;
                int servicio;
                int otroServicio;
                int precioServicio = 0;
                int totalServicios = 0;

                printf("Ingrese el ID de la mascota: ");
                scanf("%d", &idMascota);

            
                for (int i = 0; i < 4; i++) {
                    serviciosRealizados[i] = 0;
                }
                totalServicios = 0;

                printf("Ingrese el servicio realizado (Ingrese el ID del servicio): ");
                scanf("%d", &servicio);

                do {
                    switch (servicio) {
                        case 1:
                            precioServicio = 10;
                            serviciosRealizados[0] = 1;
                            break;
                        case 2:
                            precioServicio = 20;
                            serviciosRealizados[1] = 1;
                            break;
                        case 3:
                            precioServicio = 15;
                            serviciosRealizados[2] = 1;
                            break;
                        case 4:
                            precioServicio = 5;
                            serviciosRealizados[3] = 1;
                            break;
                        default:
                            printf("ID de servicio invalido. Por favor, seleccione un ID de servicio valido.\n");
                            break;
                    }

                    if (precioServicio > 0) {
                        totalServicios += precioServicio;
                        printf("Servicio agregado correctamente.\n");
                    }

                    printf("¿Desea realizar otro servicio? (1 = Si, 0 = No): ");
                    scanf("%d", &otroServicio);

                    if (otroServicio) {
                        printf("Ingrese el siguiente servicio (Ingrese el ID del servicio): ");
                        scanf("%d", &servicio);
                    }
                } while (otroServicio);

                printf("\n----- Factura -----\n");
                printf("ID Mascota: %d\n", idMascota);
                printf("Nombre: %s\n", mascotas[idMascota]);
                printf("Edad: %d\n", edades[idMascota]);
                printf("Tipo: %s\n", mascotas[idMascota+1]);
                printf("Dueno: %s\n", mascotas[idMascota+2]);
                printf("Servicios realizados:\n");

            
                printf("-----------------------------------------------------\n");
                printf("| Servicio              | Descripcion             | Precio  | ID Servicio |\n");
                printf("-----------------------------------------------------\n");
                if (serviciosRealizados[0]) {
                    printf("| Peinado para Mascota  | Servicio de peinado     | $10     | 1           |\n");
                }
                if (serviciosRealizados[1]) {
                    printf("| Spa para Mascota      | Servicio de spa         | $20     | 2           |\n");
                }
                if (serviciosRealizados[2]) {
                    printf("| Lavado para Mascota   | Servicio de lavado      | $15     | 3           |\n");
                }
                if (serviciosRealizados[3]) {
                    printf("| Desparasitante        | Servicio desparasitante | $5      | 4           |\n");
                }
                printf("-----------------------------------------------------\n");

                facturaTotal += totalServicios;
                printf("El total a pagar de todas las facturas es: %d\n", facturaTotal);
                break;
            case 4:
                printf("Cerrando programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }

        printf("\n");
    } while (opcion != 4);

    return 0;
}
