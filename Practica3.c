// Desarrollador: Sergio Corredor
#include <stdio.h>

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};

void main() {
	char usuario[50] = "admin", password[50] = "1234", usuarioIntroducido[50], passwordIntroducido[50];
	struct plaza plaza1 = { 0, 'C' }, plaza2 = { 0, 'M' };
	char eleccion, matriculaAbandonar[8], matriculaBuscar[8];
	int tipoReservar, salirPrograma=0, i;

	for (i = 0; i < 3; i++) {
		printf("Introduzca el usuario:");
		scanf_s("%s", usuarioIntroducido, 50);
		printf("Introduzca la contraseña:");
		scanf_s("%s", passwordIntroducido, 50);
		if (strcmp(usuario, usuarioIntroducido) == 0) {

			if (strcmp(password, passwordIntroducido) == 0) {
				salirPrograma = 0;
				break;
			}
			else
				printf("La contraseña introducida es incorrecta\n");
				salirPrograma = 1;
		}
		else
			printf("El usuario introducido es incorrecto\n");
			salirPrograma = 1;


	}

	getchar();

	while (salirPrograma==0) {

	system("color 71");
	printf("Seleccione una de estas opciones:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
	scanf_s("%c", &eleccion);
	system("cls");

	switch (eleccion) {
		case 'r':
		case 'R':
			if ((plaza1.estado == 1) && (plaza2.estado == 1)) {
				printf("Las dos plazas estan ocupadas.\n");
				break;
			}
			printf("Seleccione una de estas opciones:\n1 - Reservar una plaza de coche\n2 - Reservar una plaza de moto\n");
			scanf_s("%d", &tipoReservar);
			if (tipoReservar==1) {
				if (plaza1.estado == 0) {
					printf("Introduzca la matricula del coche a aparcar:");
					scanf_s("%s", plaza1.matricula, 8);
					if (strcmp(plaza1.matricula, plaza2.matricula) == 0) {
						printf("Ese coche ya esta aparcado.\n");
						break;
					}
					else {
						plaza1.estado = 1;
						printf("Ha ocupado la plaza 1.\n");
					}
				}
				else
					printf("La plaza 1 esta ocupada.\n");
			}
			else if (tipoReservar==2) {
				if (plaza2.estado == 0) {
					printf("Introduzca la matricula del coche a aparcar:");
					scanf_s("%s", plaza2.matricula, 8);
						if (strcmp(plaza1.matricula, plaza2.matricula) == 0) {
						printf("Esa moto ya esta aparcada.\n");
						break;
					}
					else {
						plaza2.estado = 1;
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
			if ((plaza1.estado == 0) && (plaza2.estado == 0)) {
				printf("Las dos plazas estan libres.\n");
				break;
			}
			else
				printf("Introduzca la matricula del coche a retirar:");
				scanf_s("%s", matriculaAbandonar, 8);
					if (strcmp(plaza1.matricula, matriculaAbandonar) == 0) {
						plaza1.estado = 0;
						printf("Ha abandonado la plaza 1.\n");
						memset(plaza1.matricula, 0, 8);
					}
					else if (strcmp(plaza2.matricula, matriculaAbandonar)==0) {
						plaza2.estado = 0;
						printf("Ha abandonado la plaza 2.\n");
						memset(plaza2.matricula, 0, 8);
					}
					else
						printf("Ese coche no esta aparcado.\n");
			break;
		case 'e':
		case 'E':
			if (plaza1.estado == 1) {
				if (plaza2.estado == 1) 
					printf("Plaza 1 - Coche - Ocupada - Matricula: %s\nPlaza 2 - Moto - Ocupada - Matricula: %s\n", plaza1.matricula, plaza2.matricula);
				else
					printf("Plaza 1 - Coche - Ocupada - Matricula: %s\nPlaza 2 - Moto - Libre\n", plaza1.matricula);
			}
			else {
				if (plaza2.estado == 1)
					printf("Plaza 1 - Coche - Libre\nPlaza 2 - Moto - Ocupada - Matricula: %s\n", plaza2.matricula);
				else
					printf("Plaza 1 - Coche - Libre\nPlaza 2 - Moto - Libre\n");
			}
			break;
		case 'b':
		case 'B':
			printf("Introduzca la matricula que quiere buscar:");
			scanf_s("%s", matriculaBuscar, 8);
				if (strcmp(plaza1.matricula, matriculaBuscar) == 0) {
					printf("El vehiculo con esa matricula esta aparcado en la plaza 1.\n");
				}
				else if (strcmp(plaza2.matricula, matriculaBuscar) == 0) {
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