
#include "declaraciones.h"
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILA 17
#define MAX_COLUMNA 17

GtkWidget *labturno;
GtkWidget *labestado;
GtkWidget *tablero;
int lleno(){
	GtkWidget *dialog_ganoS,*dialog_ganoP;
	int i,j;
	/*
	 	 * En ambos casos el contador empieza en 6, y cada vez que hay una pieza distinta a ^ o /
	 	 * disminuye uno, el primero que llega a 0 gana
	*/

	for (i=3; i<=4; i++){
		for (j=7; j<=9; j++){
			if(TableroPrincipal[i][j]!=' '){
				cont_1++;
			}
		}
	}
	for(i=12; i<=13; i++){
		for (j=7; j<=9; j++){
			if (TableroPrincipal[i][j]!=' '){
				cont_2++;
			}
		}
	}

	if (cont_2==6){
		g_print("\nGANARON LOS SUFFRAGETOS!\n");
		dialog_ganoS = gtk_message_dialog_new(GTK_WINDOW(ventana_Tablero),
																												GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,
																								GTK_BUTTONS_OK, "GANARON LOS SUFFRAGETOS!");
								if(gtk_dialog_run(GTK_DIALOG(dialog_ganoS) ) == GTK_RESPONSE_OK)
								   gtk_widget_destroy(GTK_WIDGET(dialog_ganoS) );
									gtk_widget_show_all (ventana_inicio);
									gtk_widget_hide(ventana_Tablero);
		return 0;
	}
	else if(cont_1==6){
		g_print("\nGANARON LOS POLICIAS!\n");
		dialog_ganoP = gtk_message_dialog_new(GTK_WINDOW(ventana_Tablero),
																														GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,
																										GTK_BUTTONS_OK, "GANARON LOS POLICIAS!");
										if(gtk_dialog_run(GTK_DIALOG(dialog_ganoP) ) == GTK_RESPONSE_OK)
										   gtk_widget_destroy(GTK_WIDGET(dialog_ganoP) );
											gtk_widget_show_all (ventana_inicio);
											gtk_widget_hide(ventana_Tablero);
		return 0;
	}
	else{
		return 1;
	}
}

void tablero_cb(GtkWidget *event_box, GdkEventButton *event, gpointer data) {
	GtkWidget *dialog_error,*dialog_error2;
	guint i,j;
	i = (GUINT_FROM_LE(event->y) / 34); //las imagenes tienen son 34x34pixeles
	j= (GUINT_FROM_LE(event->x) / 34);
	if(lleno()){

		if(inicio==0){
			temp = g_strdup_printf("JUGADOR");
			gtk_label_set_text(GTK_LABEL(labturno), temp);
			if (cont==0)
			{
				i_f = i;
				i_c = j;
				gchar *temp = g_strdup_printf("Presiono la imagen coordenada [%d,%d]", i,j);
				gtk_label_set_text(GTK_LABEL(labestado), temp);
				if(!coord_inicial()){
					cont=1;
					inicio = 0;
				}
				else{
					dialog_error2 = gtk_message_dialog_new(GTK_WINDOW(ventana_Tablero),
																										GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,
																						GTK_BUTTONS_OK, "ERROR, NO SELECCIONASTE BIEN !!!");
						if(gtk_dialog_run(GTK_DIALOG(dialog_error2) ) == GTK_RESPONSE_OK)
						   gtk_widget_destroy(GTK_WIDGET(dialog_error2) );
					cont = 0;
				}
				g_print("EL VALOR INICIAL : %d-%d\n", i, j);
			}
			else if(cont==1){

	//			x = (GUINT_FROM_LE(event->y) / 34); //las imagenes tienen son 34x34pixeles
	//			y= (GUINT_FROM_LE(event->x) / 34);
				f_f = i;
				f_c = j;
				g_print("EL VALOR FINAL%d-%d\n", i, j);
				gchar *temp = g_strdup_printf("Presiono la imagen coordenada [%d,%d]", i,j);
				gtk_label_set_text(GTK_LABEL(labestado), temp);
				if(!coord_final()){
					cont = 0;
					inicio = 1;
					tablero_inicio();
				}
				else{
					dialog_error = gtk_message_dialog_new(GTK_WINDOW(ventana_Tablero),
																								GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,
																				GTK_BUTTONS_OK, "ERROR JUGADA NO VALIDA !!!");
					if(gtk_dialog_run(GTK_DIALOG(dialog_error) ) == GTK_RESPONSE_OK)
						gtk_widget_destroy(GTK_WIDGET(dialog_error) );
					cont=1;
					inicio = 0;
				}
			}
		}
		if (inicio == 1){
			temp = g_strdup_printf("JUGADOR 2");
			gtk_label_set_text(GTK_LABEL(labturno), temp);
			jugador2();
		}
	}
	else if(lleno()==1){
		g_print("\nGANARON LOS POLICIAS!\n");
	}
	else if(lleno()==1){
		g_print("\nGANARON LOS SUFFRAGETOS!\n");
	}
	g_free(temp);
}

GtkWidget *TableroCB(){
	int i, j;
	//GtkWidget *imagenes; //auxiliar para cargar la imagen
	GtkWidget *eventbox;
	eventbox = gtk_event_box_new();
	tablero= gtk_grid_new();
	for (i = 0; i < MAX_FILA; i++) {
		for (j = 0; j < MAX_COLUMNA; j++) {
			if(Tablero2[i][j]=='H' || Tablero2[i][j]=='P'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/carcel.jpg");
			}
			if(Tablero2[i][j]=='/'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/patio.jpg");
			}
			if(Tablero2[i][j]=='*'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/arena.jpg");
			}
			if (Tablero2[i][j]=='^' || Tablero2[i][j]=='-'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/blanco.jpg");
			}
			//imagenes fichas suffragettto
			if(TableroPrincipal[i][j]=='V' && Tablero2[i][j]=='*'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/c_s.jpg");
			}
			if(TableroPrincipal[i][j]=='L' && Tablero2[i][j]=='*'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/c_sl.jpg");
			}
			if(TableroPrincipal[i][j]=='V' && Tablero2[i][j]=='/'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/n_s.jpg");
			}
			if(TableroPrincipal[i][j]=='L' && Tablero2[i][j]=='/'){
				imagenes[i][j]= gtk_image_new_from_file("./IMG/n_sl.jpg");
			}
			//imagenes fichas policia
			if(TableroPrincipal[i][j]=='A' && Tablero2[i][j]=='*'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/c_p.jpg");
			}
			if(TableroPrincipal[i][j]=='B' && Tablero2[i][j]=='*'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/c_pl.jpg");
			}
			if(TableroPrincipal[i][j]=='A' && Tablero2[i][j]=='/'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/n_p.jpg");
			}
			if(TableroPrincipal[i][j]=='B' && Tablero2[i][j]=='/'){
				imagenes[i][j] = gtk_image_new_from_file("./IMG/n_pl.jpg");
			}

			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagenes[i][j]), j, i, 1, 1);
		}
	}
	gtk_container_add(GTK_CONTAINER(eventbox), tablero);
	g_signal_connect(eventbox, "button-press-event", G_CALLBACK(tablero_cb), tablero);
	return eventbox;
}
int main(int argc, char *argv[]) {

	GtkWidget *box_tablero;

	//Para el GtkBuilder
	guint ret;
	GtkBuilder *builder;
	GError *error = NULL;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	//Se carga el builder
	ret = gtk_builder_add_from_file(builder, "tablero.glade", &error);
	if (ret == 0) {
		g_print("Error en la función gtk_builder_add_from_file:\n%s",
				error->message);
		return 1;
	}

	//Ventanas
	ventana_inicio = GTK_WIDGET(gtk_builder_get_object(builder, "window_menu"));
	ventana_configuracion = GTK_WIDGET(gtk_builder_get_object(builder, "window_opciones"));
	ventana_info = GTK_WIDGET(gtk_builder_get_object(builder, "window_datos"));
	ventana_reglas = GTK_WIDGET(gtk_builder_get_object(builder, "window_reglas"));
	ventana_Tablero = GTK_WIDGET(gtk_builder_get_object(builder, "ventana"));


	//Box donde estara el Tablero
	box_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "box_tablero"));

	batras3 = GTK_WIDGET(gtk_builder_get_object(builder, "button_atrasT"));
	g_signal_connect(batras3, "clicked", G_CALLBACK(botatras3), NULL);

//	Labels
	labturno = GTK_WIDGET(gtk_builder_get_object(builder, "label_turno"));
	labestado = GTK_WIDGET(gtk_builder_get_object(builder, "label_estado"));

	//Botones
	bplay = GTK_WIDGET(gtk_builder_get_object(builder, "button_jugar"));
	g_signal_connect(bplay, "clicked", G_CALLBACK(botjugar), NULL);

	bsuf = GTK_WIDGET(gtk_builder_get_object(builder, "button_suffragetto"));
	g_signal_connect(bsuf, "clicked", G_CALLBACK(botsuf), NULL);

	bpolicia = GTK_WIDGET(gtk_builder_get_object(builder, "button_policia"));
	g_signal_connect(bpolicia, "clicked", G_CALLBACK(botpolicia), NULL);

	bsorteo1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_azarF"));
	g_signal_connect(bsorteo1, "clicked", G_CALLBACK(botsorteo), NULL);

	bjugador = GTK_WIDGET(gtk_builder_get_object(builder, "button_usuario"));
	g_signal_connect(bjugador, "clicked", G_CALLBACK(botjugador1), NULL);

	bjugador2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_cpu"));
	g_signal_connect(bjugador2, "clicked", G_CALLBACK(botjugador2), NULL);

	bsorteo2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_azarT"));
	g_signal_connect(bsorteo2, "clicked", G_CALLBACK(botsorteo1), NULL);

	bplay = GTK_WIDGET(gtk_builder_get_object(builder, "button_go"));
	g_signal_connect(bplay, "clicked", G_CALLBACK(botplay), NULL);

	//Boton datos
	bdatos = GTK_WIDGET(gtk_builder_get_object(builder, "button_datos"));
	g_signal_connect(bdatos, "clicked", G_CALLBACK(botinfo), NULL);

	batras1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_atrasP"));
	g_signal_connect(batras1, "clicked", G_CALLBACK(botatras1), NULL);

	//Boton reglas
	breglas = GTK_WIDGET(gtk_builder_get_object(builder, "button_reglas"));
	g_signal_connect(breglas, "clicked", G_CALLBACK(botreglas), NULL);

	batras2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_atrasR"));
	g_signal_connect(batras2, "clicked", G_CALLBACK(botatras2), NULL);

	//salir
	bsalir = GTK_WIDGET(gtk_builder_get_object(builder, "button_salir"));
	g_signal_connect(bsalir, "clicked", G_CALLBACK (gtk_main_quit), NULL);

	labjugador1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_usuario"));
	labjugador2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_cpu"));


	nomjugador1 = GTK_WIDGET(gtk_builder_get_object(builder, "nom_usuario"));
	nombrejugador2 = GTK_WIDGET(gtk_builder_get_object(builder, "nom_cpu"));
	//temp = GTK_WIDGET(gtk_builder_get_object(builder, "temp"));
	gtk_box_pack_start(GTK_BOX(box_tablero), TableroCB(), TRUE, FALSE, 20);

	/* Connect the destroy signal of the window to gtk_main_quit
	 * When the window is about to be destroyed we get a notification and
	 * stop the main GTK+ loop
	 */
	g_signal_connect(ventana_inicio, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect(ventana_configuracion, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect(ventana_reglas, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect(ventana_info, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect(ventana_Tablero, "destroy", G_CALLBACK (gtk_main_quit), NULL);


	/* make sure that everything, window and label, are visible */
	gtk_widget_show_all(ventana_inicio);

	/* start the main loop, and let it rest there until the application is closed */
	gtk_main();


	return 0;
}

int coord_inicial(){
    if(ficha==0 && inicio==0){
       	 mayor = 'L';
		 menor = 'V';
		 lobby = '^';
    }
     if(ficha==0 && inicio==1){
		 mayor = 'B';
		 menor = 'A';
		 lobby = '-';
	}
	if(ficha==1 && inicio==1){
		mayor = 'L';
		menor = 'V';
		lobby = '^';
    }
    if(ficha==1 && inicio==0){
    	mayor = 'B';
		menor = 'A';
		lobby = '-';
    }

    if (i_f>17 || i_c>17 || i_f<0 || i_c<0) return 1;

    if (Tablero2[i_f][i_c]=='H' || Tablero2[i_f][i_c]=='P') return 1;

    if (TableroPrincipal[i_f][i_c]==mayor || TableroPrincipal[i_f][i_c]==menor)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}

int coord_final(){
    int restaF, restaC;
    restaF = abs(f_f - i_f);
    restaC = abs(f_c - i_c);

    if (f_f>17 || f_c>17 || f_f<0 || f_c<0) return 1;

    if (TableroPrincipal[f_f][f_c]!=' ') return 1;

    if (Tablero2[i_f][i_c]==lobby && Tablero2[f_f][f_c]!=lobby) return 1;

    if((TableroPrincipal[i_f][i_c]=='V' || TableroPrincipal[i_f][i_c]=='L') && Tablero2[f_f][f_c]=='-' ) return 1;

    if((TableroPrincipal[i_f][i_c]=='A' || TableroPrincipal[i_f][i_c]=='B') && Tablero2[f_f][f_c]=='^' ) return 1;

    if ((restaF==0 && restaC==1) || (restaF==1 && restaC==0) || (restaF==1 && restaC==1)){
        movimiento();
        return 0;
    }
    if ((restaF==0 && restaC==2) || (restaF==2 && restaC==0) || (restaF==2 && restaC==2)){
    	if(TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2]==' ') return 1;
        if(TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2]==mayor || TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2]==menor){
            movimiento();
            return 0;
        }
        else{
            captura();
            return 0;
        }

    }
    return 1;

}

void jugador2(){
	do{
		i_f = rand()%17;
		i_c = rand()%17;
		if(!coord_inicial()){
		    break;
		}
	}while(1); //fin do
	do{
		f_f = rand()%17;
		f_c = rand()%17;
		if(!coord_final()){
		    break;
		}
	}while(1);//fin do
	printf("\nLa computadora movio la ficha en  <%d,%d>\n",f_f,f_c);
	inicio = 0;
}
/*
    Si la funcion retorna:
        0 esta bien
        1 esta mal
*/

void captura(){
    int restaF, restaC;
    restaF = abs(i_f - f_f);
    restaC = abs(i_c - f_c);
    if (!zonas()){
        if(TableroPrincipal[i_f][i_c]== mayor){
			if(TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2] == menor || TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2] == mayor){ //verficar si funciona sin espacio en blanco
				TableroPrincipal[f_f][f_c] = TableroPrincipal[i_f][f_f];
				TableroPrincipal[i_f][i_c] = ' ';
				mitad_cambio(i_f, i_c);
			}
			else{
				TableroPrincipal[f_f][f_c] = TableroPrincipal[i_f][i_c];
				TableroPrincipal[i_f][i_c] = ' ';
				mitad_cambio(i_f, i_c);
				comienzo(TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2]);

				TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2] = ' ';
				mitad_cambio((i_f+f_f)/2,(i_c+f_c)/2);
				cambio_inicio(f_f,f_c);

			}

	    }
		else {
			if(restaF==2 && restaC==2 && TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2] != mayor &&  TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2] != menor){
				TableroPrincipal[f_f][f_c] = TableroPrincipal[i_f][i_c];
				TableroPrincipal[i_f][i_c] = ' ';
				mitad_cambio(i_f, i_c);
				cambio_inicio(f_f,f_c);

				comienzo(TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2]);
				TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2] = ' ';
				mitad_cambio((i_f+f_f)/2,(i_c+f_c)/2 );
			}
			else{
				TableroPrincipal[f_f][f_c] = TableroPrincipal[i_f][i_c];
				TableroPrincipal[i_f][i_c] = ' ';
				mitad_cambio((i_f),(i_c));
				cambio_inicio(f_f,f_c);
			}
		}
    }
    if(!zonas_3()){
    	g_print("Entro");
    	if(TableroPrincipal[(i_f+f_f)/2][(i_c+f_c)/2] != ' '){
			TableroPrincipal[f_f][f_c] = TableroPrincipal[i_f][i_c];
			TableroPrincipal[i_f][i_c] = ' ';
			mitad_cambio(i_f, i_c);
			cambio_inicio(f_f,f_c);
		}
    }
}

int zonas(){
    if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='*'){
        return 0;
    }
    if(Tablero2[i_f][i_c]=='/' && Tablero2[f_f][f_c]=='*'){
        return 0;
    }
    if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='-'){
        return 0;
    }
    if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='^'){
        return 0;
    }
    return 1;
}

int zonas_2(){
    if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='*'){ //arena a arena
        return 0;
    }
    if(Tablero2[i_f][i_c]=='/' && Tablero2[f_f][f_c]=='*'){// patio a arena
        return 0;
    }
    if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='/'){//arena a patio
		return 0;
	}
    if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='-'){//arena a lobby
        return 0;
    }
    if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='^'){ // arena a lobby
        return 0;
    }
    if(Tablero2[i_f][i_c]=='/' && Tablero2[f_f][f_c]=='/'){//patio a patio
		return 0;
	}
    if(Tablero2[i_f][i_c]=='^' && Tablero2[f_f][f_c]=='^'){// lobby a lobby
		return 0;
	}
    if(Tablero2[i_f][i_c]=='-' && Tablero2[f_f][f_c]=='-'){// lobby a lobby
    	return 0;
    }
    return 1;
}

int zonas_3(){
	if(Tablero2[i_f][i_c]=='/' && Tablero2[f_f][f_c]=='/'){//patio a patio
		return 0;
	}
	 if(Tablero2[i_f][i_c]=='*' && Tablero2[f_f][f_c]=='/'){//arena a patio
		return 0;
	}
	return 1;
}

void movimiento(){
    if(!zonas_2()){
        TableroPrincipal[f_f][f_c] = TableroPrincipal[i_f][i_c];
		TableroPrincipal[i_f][i_c] = ' ';
		mitad_cambio(i_f, i_c);
		cambio_inicio(f_f, f_c);
    }
}

void tablero_inicio(){
	int i,j;
	int aux;
	aux = 0;
	printf("     	  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16\n");
	printf("    	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	for(i=0; i<M; i++){
		printf("%d	", aux++);
		for (j=0; j<M; j++){
			(j<16)? printf("| %c ",TableroPrincipal[i][j]): printf("| %c |",TableroPrincipal[i][j]);
		}//fin for en j
	printf("\n   	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	}//fin for en i
	printf("     	  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16");
}

void mitad_cambio(int a, int b){

	if (Tablero2[a][b]=='/'){
		gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),("./IMG/patio.jpg"));
	}
	if (Tablero2[a][b]=='*'){
		gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),("./IMG/arena.jpg"));
	}
	if (Tablero2[a][b]=='^'){
			gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),("./IMG/blanco.jpg"));
	}
	if (Tablero2[a][b]=='-'){
			gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),("./IMG/blanco.jpg"));
	}

}
void cambio_inicio(int a, int b){
	if(TableroPrincipal[a][b]==mayor){
		//suffragetto
		if(mayor=='L'){
			if(Tablero2[a][b]=='*'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/c_sl.jpg");
			}
			if(Tablero2[a][b]=='^'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/b_sl.jpg");
			}
			if(Tablero2[a][b]=='/'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/n_sl.jpg");
			}
		}
		//policia
		if(mayor=='B'){
			if(Tablero2[a][b]=='*'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/c_pl.jpg");
			}
			if(Tablero2[a][b]=='-'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/b_pl.jpg");
			}
			if(Tablero2[a][b]=='/'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/n_pl.jpg");
			}
		}
	}
	if(TableroPrincipal[a][b]==menor){
		//suffragetto
		if(menor=='V'){
			if(Tablero2[a][b]=='*'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/c_s.jpg");
			}
			if(Tablero2[a][b]=='^'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/b_s.jpg");
			}
			if(Tablero2[a][b]=='/'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/n_s.jpg");
			}
		}
		//policia
		if(menor=='A'){
			if(Tablero2[a][b]=='*'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/c_p.jpg");
			}
			if(Tablero2[a][b]=='-'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/b_p.jpg");
			}
			if(Tablero2[f_f][f_c]=='/'){
				gtk_image_set_from_file(GTK_IMAGE(imagenes[a][b]),"./IMG/n_p.jpg");
			}
		}
	}
}


void comienzo(char ficha){
	if(ficha=='V'){
		if(comida_1<17){
			TableroPrincipal[comida_1][0]=ficha;
			gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_1][0]),("./IMG/g_s.jpg"));

		}
		else{
			TableroPrincipal[comida_1-17][1]=ficha;
			gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_1-17][1]),("./IMG/g_s.jpg"));
		}
		comida_1++;
	}
	if(ficha=='L'){
		if(comida_1<17){
			TableroPrincipal[comida_1][0]=ficha;
			gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_1][0]),("./IMG/g_sl.jpg"));

		}
		else{
			TableroPrincipal[comida_1-17][1]=ficha;
			gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_1-17][16]),("./IMG/g_sl.jpg"));
		}
		comida_1++;
	}
	else if(ficha=='A'){
		if(comida_2<17){
			TableroPrincipal[comida_2][16]=ficha;
			gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_2][16]),("./IMG/g_p.jpg"));
		}
		else{
			TableroPrincipal[33-comida_2][15] = ficha;
			gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_2][15]),("./IMG/g_p.jpg"));
		}
		comida_2++;
	}
	else if(ficha=='B'){
			if(comida_2<17){
				TableroPrincipal[comida_2][16]=ficha;
				gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_2][16]),("./IMG/g_pl.jpg"));
			}
			else{
				TableroPrincipal[33-comida_2][15] = ficha;
				gtk_image_set_from_file(GTK_IMAGE(imagenes[comida_2][15]),("./IMG/g_pl.jpg"));
			}
			comida_2++;
		}
}
//Funciones para los botones
//Menu
void botjugar(GtkWidget *widget, gpointer data) /* BOTON JUGAR DEL MENU PRINCIPAL */
{
	gtk_widget_show_all (ventana_configuracion);
	gtk_widget_hide(ventana_inicio);
}
void botsuf(GtkWidget *widget, gpointer data) /* BOTON ELEGIR SUFFRAGETTO */
{
	ficha = 0;
	g_print("%dS",ficha);
}
void botpolicia(GtkWidget *widget, gpointer data) /* BOTON ELEGIR POLICIA */
{
	ficha = 1;
	g_print("%dP",ficha);

}
void botsorteo(GtkWidget *widget, gpointer data) /* BOTON AZAR */
{
	srand(time(NULL));
	ficha = rand()% 2;
	g_print("%dA",ficha);
}

void botjugador1(GtkWidget *widget, gpointer data) /* BOTON EMPEZAR USUARIOS */
{
	inicio = 0;
}

void botjugador2(GtkWidget *widget, gpointer data) /* BOTON EMPEZAR CPU */
{
	inicio = 1;
	g_print("%d\n",inicio);
}
void botsorteo1(GtkWidget *widget, gpointer data) /* BOTON EMPEZAR AZAR */
{
	srand(time(NULL));
	inicio = rand()% 2;
	g_print("%d a\n",inicio);
}
void botplay(GtkWidget *widget, gpointer data) /* BOTON JUGAR DEL MENU PRINCIPAL */
{
	buff1 = gtk_entry_get_text(GTK_ENTRY(nomjugador1));
	buff2 = gtk_entry_get_text(GTK_ENTRY(nombrejugador2));
	sprintf(nombre_jugador1, "%s", buff1);
	sprintf(nombre_jugador2, "%s", buff2);
	gtk_label_set_text(GTK_LABEL(labjugador1), nombre_jugador1);
	gtk_label_set_text(GTK_LABEL(labjugador2), nombre_jugador2);

	gtk_widget_show_all (ventana_Tablero);
	gtk_widget_hide(ventana_configuracion);
}

void botinfo(GtkWidget *widget, gpointer data) /* BOTON JUGAR DEL MENU PRINCIPAL */
{
	gtk_widget_show_all (ventana_info);
	gtk_widget_hide(ventana_inicio);
}
void botatras1(GtkWidget *widget, gpointer data) /* BOTON JUGAR DEL MENU PRINCIPAL */
{
	gtk_widget_show_all (ventana_inicio);
	gtk_widget_hide(ventana_info);
}
void botatras3(GtkWidget *widget, gpointer data) /* BOTON JUGAR DEL MENU PRINCIPAL */
{
	gtk_widget_show_all (ventana_inicio);
	gtk_widget_hide(ventana_Tablero);
}
void botreglas(GtkWidget *widget, gpointer data) /* BOTON JUGAR DEL MENU PRINCIPAL */
{
	gtk_widget_show_all (ventana_reglas);
	gtk_widget_hide(ventana_inicio);
}
void botatras2(GtkWidget *widget, gpointer data) /* BOTON JUGAR DEL MENU PRINCIPAL */
{
	gtk_widget_show_all (ventana_inicio);
	gtk_widget_hide(ventana_reglas);
}

