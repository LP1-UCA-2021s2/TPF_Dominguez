#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void imprimir_tablero(){
	int i,j;
	int aux;
	aux = 0;
	printf("     	  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16\n");
	printf("    	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	for(i=0; i<M; i++){
		printf("%d	", aux++);
		for (j=0; j<M; j++){
			(j<16)? printf("| %c ",tablero[i][j]): printf("| %c |",tablero[i][j]);
		}//fin for en j
	printf("\n   	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	}//fin for en i
	printf("     	  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16");
}
void ingresar(char ficha){//con la funcion ingresar guarda las fichas a ser jugadas en las variables globales indicadas para las fichas
	if(ficha=='V' || ficha=='L'){
		if(captura1<17){
			tablero[captura1][0]=ficha;
		}
		else{
			tablero[captura1-17][1]=ficha;
		}
		captura1++;
	}
	if(ficha=='A' || ficha=='B'){
		if(captura1<17){
			tablero[captura2][16]=ficha;
		}
		else{
			tablero[33-captura2][15] = ficha;
		}
		captura2++;
	}
}

void comienzo_ficha(){// con esta funcion se guarda la configuracion del usuario para luego ser utilizado
	int opcion, elegir;
	printf("\n------ SUFFRAGETTO ------ \n");
	printf("1 - Elegir ficha \n2 - Al azar \nSeleccione una opcion: ");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:
			printf("\n Seleccione su ficha: \n");
			printf("1 - Suffrageto(V/L) \n2 - Policia(B/A): ");
			scanf("%d",&elegir);
			if (elegir==1){
				ficha = 0;
			}
			else if(elegir==2){
				ficha = 1;
			}
			break;
		case 2:
			srand(time(NULL));
			ficha = rand()% 2;
			break;
	}
	if(ficha==0){
		printf("\n Jugara como suffrageto  \n");
		ficha1= 'V';
		ficha2 = 'L';
		fichacpu1 = 'A';
		fichacpu2 = 'B';
	}
	else{
		printf("\nJugara como policia \n");
		ficha1= 'A';
		ficha2 = 'B';
		ficha1 = 'V';
		ficha2 = 'L';
	}
}
void comienzo_turno(){// La funcion recada la informacion del usuario con respecto a la configuracion del juego
	int turno, comienzo;
	printf("\n1 - seleccionar quien comienza \n2 - Al azar: ");
	scanf("%d",&turno);
	switch(turno){
		case 1:
			printf("\n1 - Jugador \n2 - Computadora \n: ");
			scanf("%d",&comienzo);
			if(comienzo==1){
				turno = 0;
			}
			else if(comienzo==2){
				turno = 1;
			}
			break;
		case 2:
			srand(time(NULL));
			turno = rand()% 2;
			break;
	}
	if(turno==0){
		printf("\nComienza el Jugador\n");
	}
	else{
		printf("\nComienza la CPU\n");
	}
}
int validar_jugada(int jugada){ // con la siguiente funcion se revizan todas las jugadas validas para el movimiento de las fichas
	int F;// resta fila
	int C; // resta columna
	char lobby;
	F = abs(f_f - i_f);
	C = abs(f_c - i_c);
	if((jugada==1 && ficha==0) || (jugada==2 && ficha==1)){
		lobby = '^';
	}
	else if((jugada==1 && ficha==1) || (jugada==2 && ficha==0)){
		lobby = '-';
	}
	if(ficha==0 && tablero[f_f][f_c]==' '){ //cuando toca suffragetto
		if(tablero_aux[i_f][i_c]!=lobby){
			if(tablero_aux[f_f][f_c]=='/' || tablero_aux[f_f][f_c]=='*' || tablero_aux[f_f][f_c]==lobby){
				//Movimientos a los costados
				if(F==0 && C==1){
					printf("Prueba 3\n");
					return 0;
				}//fin if
				// Movimiento arriba y abajo
				else if(C==0 && F==1){
					return 0;
				} //fin else if
				//Movimiento en diagonal
				else if(F==1 && C==1){
					return 0;
				}//fin else if
				//Movimientos con saltos
				else if(C==0 && F==2){
						//Saltos en columnas
					if(tablero[f_f-1][f_c]!=' '){
						return 0;
					}
					//saltos en filas
					else if(tablero[f_f+1][f_c]!=' '){
						return 0;
					}
					else{
						return 1;
					}
				}
				else if(F==0 && C==2){
						//Saltos en filas
					if(tablero[f_f][f_c-1]!=' '){
						return 0;
					}
					//Salto en columnas
					else if(tablero[f_f][f_c+1]!= ' '){
						return 0;
					}
					else{
						return 1;
					}
				}
				//Salto en diagonal
				else if(F==2 && C==2){
					if(tablero[f_f-1][f_c+1]!=' '){
						return 0;
					}
					else if(tablero[f_f+1][f_c-1]!=' '){
						return 0;
					}
					else if(tablero[f_f+1][f_c+1]!=' '){
						return 0;
					}
					else if(tablero[f_f-1][f_c-1]!=' '){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					return 1;
				}
			}
			else{
				return 1;
			}
		}
		else if (tablero_aux[i_f][i_c]==lobby && tablero_aux[f_f][f_c]==lobby){
			//Movimientos a los costados
			if(F==0 && C==1){
					return 0;
				}//fin if
				// Movimiento arriba y abajo
			else if(C==0 && F==1){
				return 0;
			} //fin else if
			//Movimiento en diagonal
			else if(F==1 && C==1){
				return 0;
			}//fin else if
			else if(F==0 && C==2){
			//Saltos en filas
				if(tablero[f_f][f_c-1]==ficha1  || tablero[f_f][f_c-1]==ficha2){
					return 0;
				}
					//Salto en columnas
				else if(tablero[f_f][f_c+1]==ficha1  || tablero[f_f][f_c+1]==ficha2){
					return 0;
				}
				else{
					return 1;
				}
			}
			else{
				return 1;
			}
		}
		else{
			return 1;
		}
	}
	else if(ficha==1 && tablero[f_f][f_c]==' '){ //cuando toca policia
		if(tablero_aux[i_f][i_c]!=lobby){
			if(tablero_aux[f_f][f_c]=='/' || tablero_aux[f_f][f_c]=='*' || tablero_aux[f_f][f_c]==lobby){
				//Movimientos a los costados
				if(F==0 && C==1){
					return 0;
				}//fin if
				// Movimiento arriba y abajo
				else if(C==0 && F==1){
					return 0;
				} //fin else if
				//Movimiento en diagonal
				else if(F==1 && C==1){
					return 0;
				}//fin else if
				//Movimientos con saltos
				else if(C==0 && F==2){
						//Saltos en columnas
					if(tablero[f_f-1][f_c]!=' '){
						return 0;
					}
					//saltos en filas
					else if(tablero[f_f+1][f_c]!=' '){
						return 0;
					}
					else{
						return 1;
					}
				}
				else if(F==0 && C==2){
					//Saltos en filas
					if(tablero[f_f][f_c-1]!=' '){
						return 0;
					}
					//Salto en columnas
					else if(tablero[f_f][f_c+1]!=' '){
						return 0;
					}
					else{
						return 1;
					}
				}
				//Salto en diagonal
				else if(F==2 && C==2){
					if(tablero[f_f-1][f_c+1]!=' '){
						return 0;
					}
					else if(tablero[f_f+1][f_c-1]!=' '){
						return 0;
					}
					else if(tablero[f_f+1][f_c+1]!=' '){
						return 0;
					}
					else if(tablero[f_f-1][f_c-1]!=' '){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					return 1;
				}
			}
			else{
				return 1;
			}
		}
		else if (tablero_aux[i_f][i_c]==lobby && tablero_aux[f_f][f_c]==lobby){
			//Movimientos a los costados
			if(F==0 && C==1){
				return 0;
			}//fin if
			// Movimiento arriba y abajo
			else if(C==0 && F==1){
				return 0;
			} //fin else if
			//Movimiento en diagonal
			else if(F==1 && C==1){
				return 0;
			}//fin else if
			else if(F==0 && C==2){
			//Saltos en filas
				if(tablero[f_f][f_c-1]!=' '){
					return 0;
				}
				//Salto en columnas
				else if(tablero[f_f][f_c+1]!=' '){
					return 0;
				}
				else{
					return 1;
				}
			}
			else{
				return 1;
			}
		}
		else{
			return 1;
		}
	}
	else{
		return 1;
	}
}
int capturar_jugador(){ // con esta funcion se actualiza el tablero de acuerdo a las jugadas validas del jugador y asi se va actualizando el tablero para las jugadas
	int F;// resta fila
	int C; // resta columna
	F = (f_f - i_f);
	C = (f_c - i_c);
	if (tablero[i_f][i_c]==ficha1){// comer en diagonal
		if((F==-2) && (C==2)){//arriba derecha
			if(tablero[f_f+1][f_c-1]!=' '){
				if(tablero[f_f+1][f_c-1]==ficha1 || tablero[f_f+1][f_c-1]==ficha2 || tablero_aux[f_f+1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c-1]);
				tablero[f_f+1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==-2) && (C==-2)){//arriba izquierda
			if(tablero[f_f+1][f_c+1]!=' '){
				if(tablero[f_f+1][f_c+1]==ficha1 || tablero[f_f+1][f_c+1]==ficha2 || tablero_aux[f_f+1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c+1]);
				tablero[f_f+1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==2)){ // abajo derecha
			if(tablero[f_f-1][f_c-1]!=' '){
				if(tablero[f_f-1][f_c-1]==ficha1 || tablero[f_f-1][f_c-1]==ficha2 || tablero_aux[f_f-1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c-1]);
				tablero[f_f-1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==-2)){//abajo izquierda
			if(tablero[f_f-1][f_c+1]!=' '){
				if(tablero[f_f-1][f_c+1]==ficha1 || tablero[f_f-1][f_c+1]==ficha2 || tablero_aux[f_f-1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c+1]);
				tablero[f_f-1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else{
			return 2;
		}
	}
	else if(tablero[i_f][i_c]==ficha2){//para las fichas especiales
		if((F==-2) && (C==2)){//arriba derecha
			if(tablero[f_f+1][f_c-1]!=' '){
				if(tablero[f_f+1][f_c-1]==ficha1 || tablero[f_f+1][f_c-1]==ficha2 || tablero_aux[f_f+1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c-1]);
				tablero[f_f+1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==-2) && (C==-2)){//arriba izquierda
			if(tablero[f_f+1][f_c+1]!=' '){
				if(tablero[f_f+1][f_c+1]==ficha1 || tablero[f_f+1][f_c+1]==ficha2 || tablero_aux[f_f+1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c+1]);
				tablero[f_f+1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==2)){ // abajo derecha
			if(tablero[f_f-1][f_c-1]!=' '){
				if(tablero[f_f-1][f_c-1]==ficha1 || tablero[f_f-1][f_c-1]==ficha2 || tablero_aux[f_f-1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c-1]);
				tablero[f_f-1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==-2)){//abajo izquierda
			if(tablero[f_f-1][f_c+1]!=' '){
				if(tablero[f_f-1][f_c+1]==ficha1 || tablero[f_f-1][f_c+1]==ficha2 || tablero_aux[f_f-1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c+1]);
				tablero[f_f-1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==0)&&(C==2)){
			if(tablero[f_f][f_c-1]!=' '){
				if(tablero[f_f][f_c-1]==ficha1 || tablero[f_f][f_c-1]==ficha2 || tablero_aux[f_f][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f][f_c-1]);
				tablero[f_f][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==0)&&(C==-2)){
			if (tablero[f_f][f_c+1]!=' '){
				if(tablero[f_f][f_c+1]==ficha1 || tablero[f_f][f_c+1]==ficha2 || tablero_aux[f_f][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f][f_c+1]);
				tablero[f_f][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2)&&(C==0)){
			if(tablero[f_f-1][f_c]!=' '){
				if(tablero[f_f-1][f_c]==ficha1 || tablero[f_f-1][f_c]==ficha2 || tablero_aux[f_f-1][f_c]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c]);
				tablero[f_f-1][f_c] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==-2)&&(C==0)){
			if(tablero[f_f+1][f_c]!= ' '){
				if(tablero[f_f+1][f_c]==ficha1 || tablero[f_f+1][f_c]==ficha2 || tablero_aux[f_f+1][f_c]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c]);
				tablero[f_f+1][f_c] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else{
			return 2;
		}
	}
	else{
		return 2;
	}
}
int capturar_cpu(){
	int F;// resta fila
	int C; // resta columna
	F = (f_f - i_f);
	C = (f_c - i_c);
	if (tablero[i_f][i_c]==fichacpu1){// comer en diagonal
		if((F==-2) && (C==2)){//arriba derecha
			if(tablero[f_f+1][f_c-1]!=' '){
				if(tablero[f_f+1][f_c-1]==fichacpu1 || tablero[f_f+1][f_c-1]==fichacpu2 || tablero_aux[f_f+1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c-1]);
				tablero[f_f+1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==-2) && (C==-2)){//arriba izquierda
			if(tablero[f_f+1][f_c+1]!=' '){
				if(tablero[f_f+1][f_c+1]==fichacpu1 || tablero[f_f+1][f_c+1]==fichacpu2 || tablero_aux[f_f+1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c+1]);
				tablero[f_f+1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==2)){ // abajo derecha
			if(tablero[f_f-1][f_c-1]!=' '){
				if(tablero[f_f-1][f_c-1]==fichacpu1 || tablero[f_f-1][f_c-1]==fichacpu2 || tablero_aux[f_f-1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c-1]);
				tablero[f_f-1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==-2)){//abajo izquierda
			if(tablero[f_f-1][f_c+1]!=' '){
				if(tablero[f_f-1][f_c+1]==fichacpu1 || tablero[f_f-1][f_c+1]==fichacpu2 || tablero_aux[f_f-1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c+1]);
				tablero[f_f-1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else{
			return 2;
		}
	}
	else if(tablero[i_f][i_c]==fichacpu2){//para las fichas especiales
		if((F==-2) && (C==2)){//arriba derecha
			if(tablero[f_f+1][f_c-1]!=' '){
				if(tablero[f_f+1][f_c-1]==fichacpu1 || tablero[f_f+1][f_c-1]==fichacpu2 || tablero_aux[f_f+1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c-1]);
				tablero[f_f+1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==-2) && (C==-2)){//arriba izquierda
			if(tablero[f_f+1][f_c+1]!=' '){
				if(tablero[f_f+1][f_c+1]==fichacpu1 || tablero[f_f+1][f_c+1]==fichacpu2 || tablero_aux[f_f+1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c+1]);
				tablero[f_f+1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==2)){ // abajo derecha
			if(tablero[f_f-1][f_c-1]!=' '){
				if(tablero[f_f-1][f_c-1]==fichacpu1 || tablero[f_f-1][f_c-1]==fichacpu2  || tablero_aux[f_f-1][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c-1]);
				tablero[f_f-1][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2) && (C==-2)){//abajo izquierda
			if(tablero[f_f-1][f_c+1]!=' '){
				if(tablero[f_f-1][f_c+1]==fichacpu1 || tablero[f_f-1][f_c+1]==fichacpu2 || tablero_aux[f_f-1][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c+1]);
				tablero[f_f-1][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==0)&&(C==2)){
			if(tablero[f_f][f_c-1]!=' '){
				if(tablero[f_f][f_c-1]==fichacpu1 || tablero[f_f][f_c-1]==fichacpu2 || tablero_aux[f_f][f_c-1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f][f_c-1]);
				tablero[f_f][f_c-1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==0)&&(C==-2)){
			if (tablero[f_f][f_c+1]!=' '){
				if(tablero[f_f][f_c+1]==fichacpu1 || tablero[f_f][f_c+1]==fichacpu2 || tablero_aux[f_f][f_c+1]!='*'){
					return 2;
				}
				ingresar(tablero[f_f][f_c+1]);
				tablero[f_f][f_c+1] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==2)&&(C==0)){
			if(tablero[f_f-1][f_c]!=' '){
				if(tablero[f_f-1][f_c]==fichacpu1 || tablero[f_f-1][f_c]==fichacpu2 || tablero_aux[f_f-1][f_c]!='*'){
					return 2;
				}
				ingresar(tablero[f_f-1][f_c]);
				tablero[f_f-1][f_c] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else if((F==-2)&&(C==0)){
			if(tablero[f_f+1][f_c]!= ' '){
				if(tablero[f_f+1][f_c]==fichacpu1 || tablero[f_f+1][f_c]==fichacpu2 || tablero_aux[f_f+1][f_c]!='*'){
					return 2;
				}
				ingresar(tablero[f_f+1][f_c]);
				tablero[f_f+1][f_c] = ' ';
				return 2;
			}
			else{
				return 3;
			}
		}
		else{
			return 2;
		}
	}
	else{
		return 2;
	}
}
void mover_jugador(){ // esta funcion recada los movimientos validos para las jugadas ingresadas por el usuario
	char jugador;
	int mover, capturar=2;
	//int comer;
	printf("\nIngrese la coordenada de la ficha a mover\n");
	do{
		printf("\nFila - Columna \n");
		printf("Fila: ");
		scanf("%d",&i_f);
		printf("Columna: ");
		scanf("%d",&i_c);
		while (getchar() != '\n');
		if (tablero[i_f][i_c]==ficha1 && tablero_aux[i_f][i_c]!='H' && tablero_aux[i_f][i_c]!='P'){
			jugador = ficha1;
			break;
		}//fin if
		else if(tablero[i_f][i_c]==ficha2 && tablero_aux[i_f][i_c]!='H' && tablero_aux[i_f][i_c]!='P'){
			jugador = ficha2;
			break;
		}//fin else if
		else{
			printf("\nPosicion no valida!\n");
		}//fin else
	}while(1); //fin do
	printf("\nUsted eligio la ficha <%d,%d>",i_f,i_c);

	do{
		printf("\nIngrese donde desea mover su ficha");
		printf("\nFila - Columna \n");
		printf("Fila: ");
		scanf("%d",&f_f);
		printf("Columna: ");
		scanf("%d",&f_c);
		while (getchar() != '\n');
		mover = validar_jugada(1);//llamamos a la funcion para comprobar si es valida la posicion final
		capturar = capturar_jugador();
		if(mover==1){
			printf("\nPosicion no valida!\n");
		}
	}while(mover==1 || capturar==3);//fin do
	if(mover==0){
		printf("\nUsted movio la ficha en  <%d,%d>\n",f_f,f_c);
		tablero[i_f][i_c]= ' ';
		tablero[f_f][f_c] = jugador;
	}
	else if(capturar==2){
		printf("\nCAPTURASTE UNA FICHA\n");
	}
}
void mover_cpu(){
	char fichaCpu;
	int resultado;
	int capturar1;
	do{
		i_f = rand()%17;
		i_c = rand()%17;
		if (tablero[i_f][i_c]==fichacpu1 && tablero_aux[i_f][i_c]!='H' && tablero_aux[i_f][i_c]!='P'){
			fichaCpu = fichacpu1;
			break;
		}//fin if
		else if(tablero[i_f][i_c]==fichacpu2 && tablero_aux[i_f][i_c]!='H' && tablero_aux[i_f][i_c]!='P'){
			fichaCpu = fichacpu2;
			break;
		}//fin else if
	}while(1); //fin do
	printf("\nLa cpu eligio la ficha <%d,%d>\n",i_f,i_c);
	do{
		f_f = rand()%17;
		f_c = rand()%17;
		resultado = validar_jugada(2);
		capturar1=capturar_cpu();
	}while(resultado==1 || capturar1==3);//fin do
	printf("\nLa computadora movio la ficha en  <%d,%d>\n",f_f,f_c);
	tablero[i_f][i_c]= ' ';
}
int lleno(){
	int i,j;
	int cont_1=6;//Contador para saber si esta lleno HOUSE OF COMMONS
	int cont_2=6;//Contador para saber si esta lleno ALBERT HALL
	/*
	 	 * En ambos casos el contador empieza en 6, y cada vez que hay una pieza distinta a ^ o /
	 	 * disminuye uno, el primero que llega a 0 gana
	*/

	for (i=3; i<=4; i++){
		for (j=7; j<=9; j++){
			if(tablero[i][j]!=' '){
				cont_1--;
			}
		}
	}
	for(i=12; i<=13; i++){
		for (j=7; j<=9; j++){
			if (tablero[i][j]!=' '){
				cont_2--;
			}
		}
	}

	if (cont_2==5){
		printf("\nGANARON LOS SUFFRAGETOS!\n");
		return 1;
	}
	else if(cont_1==5){
		printf("\nGANARON LOS POLICIAS!\n");
		return 2;
	}
	else{
		return 3;
	}
}

int main(){
	int gano=3;
	srand(time(NULL));
	comienzo_ficha();
	comienzo_turno();
	imprimir_tablero();
	while(gano==3){
		if (turno==0){
			mover_jugador();
			imprimir_tablero();
			gano=lleno();
			if(gano!=3){
				break;
			}
			mover_cpu();
			imprimir_tablero();
			gano=lleno();
		}
		else if(turno==1){
			mover_cpu();
			imprimir_tablero();
			gano=lleno();
			if(gano!=3){
				break;
			}
			mover_jugador();
			imprimir_tablero();
			gano=lleno();
		}
	}
	return EXIT_SUCCESS;
}

