#include <stdio.h>
void jugadasvalidas(){//esta funcion controlara las jugadas validas por el usuario

}
void ganador(){// esta funcion definira el ganador del juego

}
void cpu(){//esta funcion se encargara de las jugadas de la computadora

}
int main(void){
	//Tablero();
	int i,j;
	char tablero[5][5];//se estara utilizando un array de dos dimensiones para la creacion del tablero
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			tablero[i][j]='0';
			}
		}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c",tablero[i][j]);
		}
		printf("\n");
	}
}




