// Desarrollador: Sergio Corredor
#include <stdio.h>
#define NPLAZAS 10

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};

void main() {
	char usuario[50] = "admin", password[50] = "1234", usuarioIntroducido[50], passwordIntroducido[50];
	struct plaza aparcamiento[NPLAZAS];
	char eleccion, matriculaAbandonar[8], matriculaBuscar[8];
	int tipoReservar, salirPrograma = 0, plazaElegida, i, vehiculoAparcado,vehiculoAbandonado, vehiculoEncontrado;

	for (i = 0; i < NPLAZAS / 2; i++)
		aparcamiento[i].tipo = 'C';
	for (i = NPLAZAS / 2; i < NPLAZAS; i++)
		aparcamiento[i].tipo = 'M';
	for (i = 0; i < NPLAZAS; i++)
		aparcamiento[i].estado = 0;
	for (i = 0; i < NPLAZAS; i++)
	memset(aparcamiento[i].matricula, 0, 8);

	for (i = 0; i < 3; i++) {
		printf("Introduzca el usuario:");
		gets(usuarioIntroducido);
		printf("Introduzca la contraseña:");
		gets(passwordIntroducido);
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

	while (salirPrograma == 0) {
		vehiculoAparcado = 0;
		vehiculoAbandonado = 0;
		vehiculoEncontrado = 0;
		system("color 71");
		system("cls");
		printf("Seleccione una de estas opciones:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
		scanf_s("%c", &eleccion);
		system("cls");

		switch (eleccion) {
		case 'r':
		case 'R':
			printf("Seleccione una de estas opciones:\n1 - Reservar una plaza de coche\n2 - Reservar una plaza de moto\n");
			scanf_s("%d", &tipoReservar);
			if (tipoReservar == 1) {
				printf("Introduzca la plaza que desa reservar (1,2,3,4 o 5):");
				scanf_s("%d", &plazaElegida);
				if (aparcamiento[plazaElegida-1].estado==0) {
				printf("Introduzca la matricula del coche:");
				getchar();
				gets(aparcamiento[plazaElegida-1].matricula);
				for (i=0; i<NPLAZAS/2; i++) {
					if (strcmp(aparcamiento[i].matricula, aparcamiento[plazaElegida - 1].matricula) == 0) {
						if (i!=plazaElegida-1)
						vehiculoAparcado = 1;
					}
				}
				if (vehiculoAparcado==1) {
					printf("Ese coche ya esta aparcado.\n");
					break;
				}
				else {
					aparcamiento[plazaElegida - 1].estado = 1;
					printf("Ha ocupado la plaza %d.\n", plazaElegida);
					}
				}
				else
					printf("La plaza esta ocupada.\n");
			}
			else if (tipoReservar == 2) {
				printf("Introduzca la plaza que desa reservar (6,7,8,9 o 10):");
				scanf_s("%d", &plazaElegida);
				if (aparcamiento[plazaElegida - 1].estado == 0) {
					printf("Introduzca la matricula de la moto:");
					getchar();
					gets(aparcamiento[plazaElegida - 1].matricula);
					for (i = NPLAZAS/2; i<NPLAZAS; i++) {
						if (strcmp(aparcamiento[i].matricula, aparcamiento[plazaElegida - 1].matricula) == 0) {
							if (i != plazaElegida - 1)
								vehiculoAparcado = 1;
						}
					}
					if (vehiculoAparcado == 1) {
						printf("Esa moto ya esta aparcado.\n");
						break;
					}
					else {
						aparcamiento[plazaElegida - 1].estado = 1;
						printf("Ha ocupado la plaza %d.\n", plazaElegida);
					}
				}
				else
					printf("La plaza esta ocupada.\n");
			}
			else {
				printf("Seleccione una opcion correcta.\n");
				getchar();
			}
			break;
		case 'a':
		case 'A':
			printf("Introduzca la matricula del vehiculo a retirar:");
			getchar();
			gets(matriculaAbandonar);
			for (i=0; i<NPLAZAS; i++) {
				if (strcmp(aparcamiento[i].matricula, matriculaAbandonar) == 0) {
					vehiculoAbandonado = 1;
					aparcamiento[i].estado = 0;
					printf("Ha abandonado la plaza %d.\n", i+1);
					memset(aparcamiento[i].matricula, 0, 8);
					system("pause");
				}
			}
			if(vehiculoAbandonado==0)
				printf("Ese coche no esta aparcado.\n");
			break;
		case 'e':
		case 'E':
			for (i = 0; i < NPLAZAS; i++) {
				if (aparcamiento[i].tipo=='C') {
					if (aparcamiento[i].estado==0)
						printf("Plaza %d - Coche - Libre - Matricula: %s\n", i + 1, aparcamiento[i].matricula);
					else if (aparcamiento[i].estado == 1)
						printf("Plaza %d - Coche - Ocupado - Matricula: %s\n", i + 1, aparcamiento[i].matricula);
				}
				else {
					if (aparcamiento[i].estado == 0)
						printf("Plaza %d - Moto - Libre - Matricula: %s\n", i + 1, aparcamiento[i].matricula);
					else if (aparcamiento[i].estado == 1)
						printf("Plaza %d - Moto - Ocupado - Matricula: %s\n", i + 1, aparcamiento[i].matricula);
				}
			}
			system("pause");
			getchar();
			break;
		case 'b':
		case 'B':
			printf("Introduzca la matricula que quiere buscar:");
			getchar();
			gets(matriculaBuscar);
			for (i=0;i<NPLAZAS; i++) {
				if (strcmp(aparcamiento[i].matricula, matriculaBuscar) == 0) {
					vehiculoEncontrado = 1;
					printf("El vehiculo con esa matricula esta aparcado en la plaza %d.\n", i+1);
				}
			}
			if(vehiculoEncontrado==0)
				printf("Ningun vehiculo con esa matricula esta aparcado.\n");
				system("pause");
			break;
		case 's':
		case 'S':
			salirPrograma = 1;
		default:
			printf("Seleccione una opcion correcta.\n");


		}
	}
}