// Desarrollador: Sergio Corredor
#include <stdio.h>

void main() {

	char eleccion, matricula1[8], matricula2[8], matriculaAbandonar[8], matriculaBuscar[8];
	int plaza1=0, plaza2=0, tipoReservar, salirPrograma=0;

	while (salirPrograma==0) {

	system("color 71");
	printf("Seleccione una de estas opciones:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
	scanf_s("%c", &eleccion);
	system("cls");

	switch (eleccion) {
		case 'r':
		case 'R':
			if ((plaza1 == 1) && (plaza2 == 1)) {
				printf("Las dos plazas estan ocupadas.\n");
				break;
			}
			printf("Seleccione una de estas opciones:\n1 - Reservar una plaza de coche\n2 - Reservar una plaza de moto\n");
			scanf_s("%d", &tipoReservar);
			if (tipoReservar==1) {
				if (plaza1 == 0) {
					printf("Introduzca la matricula del coche a aparcar:");
					scanf_s("%s", matricula1, 8);
					if (strcmp(matricula1, matricula2) == 0) {
						printf("Ese coche ya esta aparcado.\n");
						break;
					}
					else {
						plaza1 = 1;
						printf("Ha ocupado la plaza 1.\n");
					}
				}
				else
					printf("La plaza 1 esta ocupada.\n");
			}
			else if (tipoReservar==2) {
				if (plaza2 == 0) {
					printf("Introduzca la matricula del coche a aparcar:");
					scanf_s("%s", matricula2, 8);
						if (strcmp(matricula1, matricula2) == 0) {
						printf("Esa moto ya esta aparcada.\n");
						break;
					}
					else {
						plaza2 = 1;
						printf("Ha ocupado la plaza 2.\n");
				}
			}
				else
					printf("La plaza 2 esta ocupada.\n");
			}
			else
				printf("Seleccione una opcion correcta.\n");
			break;
		case 'a':
		case 'A':
			if ((plaza1 == 0) && (plaza2 == 0)) {
				printf("Las dos plazas estan libres.\n");
				break;
			}
			else
				printf("Introduzca la matricula del coche a retirar:");
				scanf_s("%s", matriculaAbandonar, 8);
					if (strcmp(matricula1, matriculaAbandonar) == 0) {
						plaza1 = 0;
						printf("Ha abandonado la plaza 1.\n");
						memset(matricula1, 0, 8);
					}
					else if (strcmp(matricula2, matriculaAbandonar)==0) {
						plaza2 = 0;
						printf("Ha abandonado la plaza 2.\n");
						memset(matricula2, 0, 8);
					}
					else
						printf("Ese coche no esta aparcado.\n");
			break;
		case 'e':
		case 'E':
			if (plaza1 == 1) {
				if (plaza2 == 1) 
					printf("Plaza 1 - Coche - Ocupada - Matricula: %s\nPlaza 2 - Moto - Ocupada - Matricula: %s\n", matricula1, matricula2);
				else
					printf("Plaza 1 - Coche - Ocupada - Matricula: %s\nPlaza 2 - Moto - Libre\n", matricula1);
			}
			else {
				if (plaza2 == 1)
					printf("Plaza 1 - Coche - Libre\nPlaza 2 - Moto - Ocupada - Matricula: %s\n", matricula2);
				else
					printf("Plaza 1 - Coche - Libre\nPlaza 2 - Moto - Libre\n");
			}
			break;
		case 'b':
		case 'B':
			printf("Introduzca la matricula que quiere buscar:");
			scanf_s("%s", matriculaBuscar, 8);
				if (strcmp(matricula1, matriculaBuscar) == 0) {
					printf("El vehiculo con esa matricula esta aparcado en la plaza 1.\n");
				}
				else if (strcmp(matricula2, matriculaBuscar) == 0) {
					printf("El vehiculo con esa matricula esta aparcado en la plaza 2.\n");
				}
				else
					printf("Ningun vehiculo con esa matricula esta aparcado.\n");
			break;
		case 's':
		case 'S':
			salirPrograma = 1;
		default:
			printf("Seleccione una opcion correcta.\n");


	}
	getchar();
	}
}