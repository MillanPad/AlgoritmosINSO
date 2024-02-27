#include <iostream>
using namespace std;

int derecha(char posicion[9][9],int fila,int columna){
	int confirma=0;
	if(posicion[fila][columna+1]=='.'){
		posicion[fila][columna+1]=='X';
		confirma = 1;
	}else{
		confirma = 0;
	}
	return confirma;
}
int izquierda(char posicion[9][9],int fila,int columna){
	int confirma;
	if(posicion[fila][columna-1]=='.'){
		posicion[fila][columna-1]=='X';
		confirma=1;
	}else{
		confirma = 0;
	}
	return confirma;
}
int arriba(char posicion[9][9],int fila,int columna){
	int confirma;
	if(posicion[fila-1][columna]=='.'){
		posicion[fila-1][columna]=='X';
		confirma =1;
	}else{
		confirma = 0;
	}
	return confirma;
}
int abajo(char posicion[9][9],int fila,int columna){
	int confirma;
	if(posicion[fila+1][columna]=='.'){
		posicion[fila+1][columna]=='X';
		confirma= 1;
	}else{
		confirma = 0;
	}
	return confirma;
}
/*
bool proximoMovimiento(char mapa[9][9],int fila, int columna){
	int ayu1=derecha(mapa,fila,columna);
	int ayu2=izquierda(mapa,fila,columna);
	int ayu3=abajo(mapa,fila,columna);
	int ayu4=arriba(mapa,fila,columna);
	if(ayu1=1){
		return 1;
	}
	if(ayu2=1){
		return 1;
	}
	if(ayu3=1){
		return 1;
	}
	if(ayu4=1){
		return 1;
	}
	return 0;
	
}
*/
void recorrer(char mapa[9][9],int fila, int columna){
	int aux1,aux2,aux3,aux4;
	aux1=aux2=aux3=aux4=0;
	while(mapa[fila][columna]!='T'){
		aux1=derecha(mapa,fila,columna);
		aux2=izquierda(mapa,fila,columna);
		aux3=abajo(mapa,fila,columna);
		aux4=arriba(mapa,fila,columna);
		if(aux4=1){
			if(proximoMovimiento(mapa,fila,columna+1)==true){
				recorrer(mapa,fila,columna+1);
			}else{
				mapa[fila][columna]=='.';	
			}
		}
		if(aux1=1){
			if(proximoMovimiento(mapa,fila,columna-1)==true){
				recorrer(mapa,fila,columna-1);
			}else{
				mapa[fila][columna]=='.';	
			}
		}
		if(aux3=1){
			if(proximoMovimiento(mapa,fila+1,columna)==true){
				recorrer(mapa,fila+1,columna);
			}else{
				mapa[fila][columna]=='.';	
			}
		}
		if(aux2=1){
			if(proximoMovimiento(mapa,fila-1,columna)==true){
				recorrer(mapa,fila-1,columna);
			}else{
				mapa[fila][columna]=='.';	
			}
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<mapa[i][j];
		}
	}
	if(mapa[fila][columna]!='T'){
		cout<<"ENCONTRADO "<<fila<<" "<<columna<<endl;
	}
}
int main(){
	char laberinto[9][9];
	for(int a=0;a<10;a++){
		for(int b=0;b<10;b++){
			cin>>laberinto[a][b];
		}
	}
	recorrer(laberinto,0,0);
	return 0;
}
