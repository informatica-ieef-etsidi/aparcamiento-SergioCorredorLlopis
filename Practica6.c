// Desarrollador: Sergio Corredor
#include <stdio.h>

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
};

struct usuario {
	char username[20];
	char password[20];
};

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(struct usuario usuarioValido, char username[], char password[]);
void recuento(struct plaza aparcamiento[], int dim, int *nLibresCoches, int *nLibresMotos);
void inicializar(struct plaza aparcamiento[], int dim);
int buscarPlazaLibre(struct plaza aparcamiento[], int dim, char tipo);
int buscarVehiculo(struct plaza aparcamiento[], int dim, char matricula[]);

void main() {
	char usuarioIntroducido[50], passwordIntroducido[50];
	struct plaza aparcamiento[50];
	struct usuario miUsuario = { "admin", "1234" };
	char eleccion, matriculaReservar[8], matriculaAbandonar[8], matriculaBuscar[8];
	int tipoReservar, salirPrograma = 0, plazaElegida, i, vehiculoAparcado,vehiculoAbandonado, vehiculoEncontrado, nLibresCoches, nLibresMotos, numPlazas=10;
	
	inicializar(aparcamiento, numPlazas);

	for (i = 0; i < 3; i++) {
		printf("Introduzca el usuario:");
		gets(usuarioIntroducido);
		printf("Introduzca la contraseña:");
		gets(passwordIntroducido);
		if (existeUsuario(miUsuario, usuarioIntroducido, passwordIntroducido) == 1)
			break;
	}
		

	while (salirPrograma == 0) {
		vehiculoAparcado = 0;
		vehiculoAbandonado = 0;
		vehiculoEncontrado = 0;
		nLibresCoches = 0;
		nLibresMotos = 0;
		eleccion = menu();

		switch (eleccion) {
		case 'r':
		case 'R':
			printf("Seleccione una de estas opciones:\n1 - Reservar una plaza de coche\n2 - Reservar una plaza de moto\n");
			scanf_s("%d", &tipoReservar);
			if (tipoReservar == 1) {
				if (buscarPlazaLibre(aparcamiento, numPlazas, 'C') == -1)
					printf("Hay 0 plazas de coche libres.\n");
				else
					printf("Hay %d plazas de coche libres.\n", buscarPlazaLibre(aparcamiento, numPlazas, 'C'));
				printf("Introduzca la plaza que desa reservar (1,2,3,4 o 5):");
				scanf_s("%d", &plazaElegida);
				if (aparcamiento[plazaElegida-1].estado==0) {
				printf("Introduzca la matricula del coche:");
				getchar();
				gets(matriculaReservar);
				if (esMatriculaValida(matriculaReservar)==1) {
					
					for (i=0; i<numPlazas/2; i++) {
						if (strcmp(aparcamiento[i].matricula, matriculaReservar) == 0) {
							if (i!=plazaElegida-1)
							vehiculoAparcado = 1;
						}
					}
					if (vehiculoAparcado==1) {
						printf("Ese coche ya esta aparcado.\n");
						break;
					}
					else {
						strcpy(aparcamiento[plazaElegida - 1].matricula, matriculaReservar);
						aparcamiento[plazaElegida - 1].estado = 1;
						printf("Ha ocupado la plaza %d.\n", plazaElegida);
						}
					}	
					else
						printf("Matricula no valida.\n");
					}
				else
					printf("La plaza esta ocupada.\n");
			}
			else if (tipoReservar == 2) {
				if (buscarPlazaLibre(aparcamiento, numPlazas, 'M')==-1)
					printf("Hay 0 plazas de moto libres.\n");
				else
					printf("Hay %d plazas de moto libres.\n", buscarPlazaLibre(aparcamiento, numPlazas, 'M'));
				printf("Introduzca la plaza que desa reservar (6,7,8,9 o 10):");
				scanf_s("%d", &plazaElegida);
				if (aparcamiento[plazaElegida - 1].estado == 0) {
					printf("Introduzca la matricula de la moto:");
					getchar();
					gets(aparcamiento[plazaElegida - 1].matricula);
					for (i = numPlazas/2; i<numPlazas; i++) {
						if (strcmp(aparcamiento[i].matricula, aparcamiento[plazaElegida - 1].matricula) == 0) {
							if (i != plazaElegida - 1)
								vehiculoAparcado = 1;
						}
					}
					if (vehiculoAparcado == 1) {
						printf("Esa moto ya esta aparcada.\n");
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
			for (i=0; i<numPlazas; i++) {
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
			for (i = 0; i < numPlazas; i++) {
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
			recuento(aparcamiento, numPlazas, &nLibresCoches, &nLibresMotos);
			if (nLibresCoches==1) {
				if (nLibresMotos==1)
					printf("Hay %d plaza de coche libre y %d plaza de moto libre.\n", nLibresCoches, nLibresMotos);
				else
					printf("Hay %d plaza de coche libre y %d plazas de moto libres.\n", nLibresCoches, nLibresMotos);
			}
			else {
				if (nLibresMotos == 1)
					printf("Hay %d plazas de coche libres y %d plaza de moto libre.\n", nLibresCoches, nLibresMotos);
				else
					printf("Hay %d plazas de coche libres y %d plazas de moto libres.\n", nLibresCoches, nLibresMotos);
			}
			system("pause");
			getchar();
			break;
		case 'b':
		case 'B':
			printf("Introduzca la matricula que quiere buscar:");
			getchar();
			gets(matriculaBuscar);
			if (buscarVehiculo(aparcamiento, numPlazas, matriculaBuscar) == -1)
				printf("Ningun vehiculo con esa matricula esta aparcado.\n");
			else
				printf("El vehiculo con esa matricula esta aparcado en la plaza %d.\n", buscarVehiculo(aparcamiento, numPlazas, matriculaBuscar));
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

char menu() {
	char eleccion;
	system("color 71");
	system("cls");
	printf("Seleccione una de estas opciones:\nR - Reservar plaza\nA - Abandonar plaza\nE - Estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
	scanf_s("%c", &eleccion);
	system("cls");
	return eleccion;
}

int esDigitoValido(char caracter) {
	int i, esValido=1;
		if (!(caracter >= '0' && caracter <= '9'))
			esValido = 0;
	return esValido;

}

int esLetraValida(char caracter) {
	int i, esValida = 1;
		if (!(caracter > 'A' && caracter <= 'Z' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U'))
			esValida = 0;
	return esValida;
}

int esMatriculaValida(char matricula[]) {
	int i, esValida=1;
	for (i = 0; matricula[i] != '\0'; i++);
	if (i != 7)
		esValida = 0;
	for (i = 0; i < 4; i++) {
		if (esDigitoValido(matricula[i]) == 0)
			esValida = 0;
	}
	for (i = 4; i < 7; i++) {
		if (esLetraValida(matricula[i]) == 0)
			esValida = 0;
	}
	return esValida;
}

int existeUsuario(struct usuario usuarioValido, char username[], char password[]) {
	int datosCorrectos = 1;
	if (strcmp(username, usuarioValido.username) == 0) {
	
		if (strcmp(password, usuarioValido.password) != 0) {
			printf("La contraseña introducida es incorrecta\n");
			datosCorrectos = 0;
		}
	}
	else {
		printf("El usuario introducido es incorrecto\n");
		datosCorrectos = 0;
	}
	return datosCorrectos;
}

void recuento(struct plaza aparcamiento[], int dim, int *nLibresCoches, int *nLibresMotos) {
	int i;
	for (i = 0; i < dim / 2; i++) {
		if (aparcamiento[i].estado == 1)
			*nLibresCoches = *nLibresCoches+1;
	}
	for (i = dim / 2; i < dim; i++) {
		if (aparcamiento[i].estado == 1)
			*nLibresMotos = *nLibresMotos+1;
	}
}

void inicializar(struct plaza aparcamiento[], int dim) {
	int i;
	for (i = 0; i < dim / 2; i++)
		aparcamiento[i].tipo = 'C';
	for (i = dim / 2; i < dim; i++)
		aparcamiento[i].tipo = 'M';
	for (i = 0; i < dim; i++)
		aparcamiento[i].estado = 0;
	for (i = 0; i < dim; i++)
		memset(aparcamiento[i].matricula, 0, 8);
}

int buscarPlazaLibre(struct plaza aparcamiento[], int dim, char tipo) {
	int i, plazasLibres=0;
	if (tipo='C') {
		for (i = 0; i < dim / 2; i++) {
			if (aparcamiento[i].estado == 0)
			plazasLibres = plazasLibres + 1;
		}
	}
	else if (tipo = 'M') {
		for (i = dim / 2; i < dim; i++) {
			if (aparcamiento[i].estado == 0)
			plazasLibres = plazasLibres + 1;
		}
	}
	if (plazasLibres == 0)
		return - 1;
	else
		return plazasLibres;
}

int buscarVehiculo(struct plaza aparcamiento[], int dim, char matricula[]) {
	int i, numPlaza=0;
	for (i = 0; i < dim; i++) {
		if (strcmp(aparcamiento[i].matricula, matricula)==0)
			numPlaza = i + 1;
	}
	if (numPlaza == 0)
		return -1;
	else
		return numPlaza;
}