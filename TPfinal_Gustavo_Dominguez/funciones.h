#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define M 17

char tablero[M][M] =  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', 'V', ' ', ' ', ' ', 'V', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', 'L', 'V', 'V', ' ', ' ', ' ', 'V', 'V', 'L', ' ', ' ', ' ', ' '},
					   {' ', ' ', 'L', 'V', 'V', ' ', 'V', 'V', 'L', 'V', 'V', 'V', 'V', 'V', 'L', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', 'V', 'A', ' ', 'A', ' ', 'A', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'V', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', 'B', 'A', 'A', 'A', 'A', 'A', 'B', 'A', 'A', 'A', 'A', 'A', 'B', ' ', ' '},
					   {' ', ' ', ' ', ' ', 'B', 'A', 'A', ' ', ' ', ' ', 'A', 'A', 'B', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

char tablero_aux[M][M] =  {{'H', 'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'},
					   	   {'H', 'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H', 'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H', 'H', '/', '/', '*', '*', '*', '-', '-', '-', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H' ,'/', '/', '/', '*', '*', '*', '-', '-', '-', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H', '/', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H', '/', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', '/', 'P'},
						   {'H', '/', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', '/', 'P'},
						   {'H', '/', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', '/', 'P'},
						   {'H', '/', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', '/', 'P'},
						   {'H', '/', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', '/', 'P'},
						   {'H', 'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', '/', 'P'},
						   {'H', 'H', '/', '/', '*', '*', '*', '^', '^', '^', '*', '*', '*', '/', '/', '/', 'P'},
						   {'H' ,'H', '/', '/', '*', '*', '*', '^', '^', '^', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H' ,'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H' ,'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'},
						   {'H' ,'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'}};
//Variables globales
int i_f; //Fila de la ficha a mover
int i_c; //Columna de la ficha a mover
int f_f; // Fila de la posicion final
int f_c; // Columna de la posicion final
char ficha1;//ficha normal usuario
char ficha2;//ficha especial usuario
char fichacpu1;//ficha normal cpu
char fichacpu2;//ficha especial usuario
int turno; // Turno de quien empieza
int ficha;
int captura1=0;//contador de capturas del jugador
int captura2=0;
int c2=0;//tu mina


//Funciones
void inicio();
void imprimir_tablero();
void comienzo_ficha();
void comienzo_turno();
void mover_jugador();
void mover_cpu();
void ingresar(char ficha);

#endif /* FUNCIONES_H_ */
