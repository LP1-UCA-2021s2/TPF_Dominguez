/*
 * declaraciones.h
 *
 *  Created on: 31 may. 2021
 *      Author: lp1-2021
 */

#ifndef DECLARACIONES_H_
#define DECLARACIONES_H_
#include<gtk/gtk.h>
#define MAX_FILA 17
#define MAX_COLUMNA 17
#define TAM_TABLERO 17
#define M 17
GtkWidget *imagenes[17][17];
char TableroPrincipal[17][17] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', 'V', ' ', ' ', ' ', 'V', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', 'L', 'V', 'V', ' ', ' ', ' ', 'V', 'V', 'L', ' ', ' ', ' ', ' '},
					   {' ', ' ', 'L', 'V', 'V', 'V', 'V', 'V', 'L', 'V', 'V', 'V', 'V', 'V', 'L', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', 'V', 'L', 'L', 'V', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'V', 'L', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ', ' ', 'B', 'A', 'A', 'A', 'A', 'A', 'B', 'A', 'A', 'A', 'A', 'A', 'B', ' ', ' '},
					   {' ', ' ', ' ', ' ', 'B', 'A', 'A', ' ', ' ', ' ', 'A', 'A', 'B', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					   {' ' ,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

char Tablero2[17][17] ={{'H', 'H', '/', '/', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '/', 'P', 'P'},
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
GtkWidget *TableroCB();
GtkWidget *eventbox;
GtkWidget *ventana_inicio;
GtkWidget *ventana_configuracion;
GtkWidget *ventana_Tablero;
GtkWidget *ventana_info;
GtkWidget *ventana_reglas;

GtkWidget *bjugar;
GtkWidget *bdatos;
GtkWidget *breglas;
GtkWidget *bsalir;
GtkWidget *bsuf;
GtkWidget *bpolicia;
GtkWidget *bsorteo1;
GtkWidget *bjugador;
GtkWidget *bjugador2;
GtkWidget *bsorteo2;
GtkWidget *bplay;
GtkWidget *batras1;
GtkWidget *batras2;
GtkWidget *batras3;
GtkWidget *labjugador1;
GtkWidget *labjugador2;
GtkWidget *labturno;
GtkWidget *labestado;

GtkWidget *nomjugador1;
GtkWidget *nombrejugador2;
const gchar *buff1;
const gchar *buff2;
gchar *temp;
//Variables globales
int i_f; //Fila de la ficha a mover
int i_c; //Columna de la ficha a mover
int f_f; // Fila de la posicion final
int f_c; // Columna de la posicion final
char menor;//ficha normal jugador
char mayor;//ficha especial jugador
char nombre_jugador1[255], nombre_jugador2[255];
int inicio; // Turno de quien empieza
int ficha;
int lleno();
int comida_1=0;//lo que comio el usuario
int comida_2=0;//Lo que comio la cpu
int cont = 0;
int cont_1=0;//Contador para saber si esta lleno HOUSE OF COMMONS
int cont_2=0;//Contador para saber si esta lleno ALBERT HALL
char lobby;
int zonas();
int zonas_2();
int zonas_3();
int coord_inicial();
int coord_final();

//Funciones

void tablero_inicio();
void ficha_inicio();
void turno_inicio();
void jugador1();
void jugador2();
void comienzo(char ficha);
void mitad_cambio(int a, int b);
void cambio_inicio(int a, int b);
void captura();
void movimiento();
void botjugar(GtkWidget *widget, gpointer data);
void botsuf(GtkWidget *widget, gpointer data);
void botpolicia(GtkWidget *widget, gpointer data);
void botsorteo(GtkWidget *widget, gpointer data);
void botjugador1(GtkWidget *widget, gpointer data);
void botjugador2(GtkWidget *widget, gpointer data);
void botsorteo1(GtkWidget *widget, gpointer data);
void botplay(GtkWidget *widget, gpointer data);
void botinfo(GtkWidget *widget, gpointer data);
void botreglas(GtkWidget *widget, gpointer data);
void botatras1(GtkWidget *widget, gpointer data);
void botatras2(GtkWidget *widget, gpointer data);
void botatras3(GtkWidget *widget, gpointer data);
void botsalir(GtkWidget *widget, gpointer data);
#endif /* DECLARACIONES_H_ */
