#include<iostream>
using namespace std;

#define SIZE 10
int derecha(char **posicion,int fila,int columna){
	int confirma=0;
	if(posicion[fila][columna+1]=='.'){
		posicion[fila][columna+1]=='X';
		confirma = 1;
	}else{
		confirma = 0;
	}
	return confirma;
}
int izquierda(char **posicion,int fila,int columna){
	int confirma;
	if(posicion[fila][columna-1]=='.'){
		posicion[fila][columna-1]=='X';
		confirma=1;
	}else{
		confirma = 0;
	}
	return confirma;
}
int arriba(char **posicion,int fila,int columna){
	int confirma;
	if(posicion[fila-1][columna]=='.'){
		posicion[fila-1][columna]=='X';
		confirma =1;
	}else{
		confirma = 0;
	}
	return confirma;
}
int abajo(char **posicion,int fila,int columna){
	int confirma;
	if(posicion[fila+1][columna]=='.'){
		posicion[fila+1][columna]=='X';
		confirma= 1;
	}else{
		confirma = 0;
	}
	return confirma;
}

bool comprobarCoor(char **array, int dx, int dy){

    if(dx < 0 || dy < 0 || dx > 9 || dy > 9 || (array[dy][dx] == '*')){
        return false;
    }
    return true;
}



bool laberinto(char **array,int y,int x){

 int dx = x;
 int dy = y ;

    if(comprobarCoor(array, dx,dy) == false){
        return false;
    }

 return true;
}

void probar(char **array,int dx, int dy){
	int aux1,aux2,aux3,aux4;
	aux1=aux2=aux3=aux4;
	if(laberinto(array, dy, dx) == false){
    	 cout << "INALCANZABLE" << endl;
 	}else{
    	 cout << "funciona" << endl;
 	}

	do{
		int aux1 = arriba(array,dy,dx);
		int aux2 = derecha(array,dy,dx);
		int aux3 = abajo(array,dy,dx);
		int aux4 = izquierda(array,dy,dx);
		if(aux1=1){
			if(laberinto(array,dy-1,dx)== true){
				probar(array,dx,dy-1);
			}else{
				probar(array,dx,dy);
			}
		}
		if(aux2=1){
			if(laberinto(array,dy,dx+1)== true){
				probar(array,dx+1,dy);
			}else{
				probar(array,dx,dy);
			}
		}
		if(aux3=1){
			if(laberinto(array,dy+1,dx)== true){
				probar(array,dx,dy+1);
			}else{
				probar(array,dx,dy);
			}
		}
		if(aux4=1){
			if(laberinto(array,dy,dx-1)== true){
				probar(array,dx,dy-1);
			}else{
				probar(array,dx,dy);
			}
		}
		//printea laberinto completado
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << array[i][j];
        }
        cout << endl;
    }
	}while(laberinto(array,dx,dy)==true && array[dx][dy]=='T');
	//printea laberinto completado
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << array[i][j];
        }
        cout << endl;
    }
}

int main(){
 int x = 0;
 int y = 0;
 char **array;
	array = new char*[SIZE];
	
	for(int i=0; i<SIZE; i++){
        array[i] = new char[SIZE];
    }

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cin >> array[i][j];
        }
    }

//printea laberinto
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << array[i][j];
        }
        cout << endl;
    }
    probar(array,y,x);
/*
 //laberinto(array);

 if(laberinto(array, y, x) == false){
     cout << "INALCANZABLE" << endl;
 }else{
     cout << "funciona" << endl;
 }
//printea laberinto completado
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << array[i][j];
        }
        cout << endl;
    }
*/
 return 0;
}
