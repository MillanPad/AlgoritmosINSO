#include <iostream>
#include <string>
#include "ListaCircular.h"
int main(){
	int ninos;
	int saltos;
	ListaCircular orden;
	do{
		cin>>ninos;
		cin>>saltos;
		if(ninos==0){
			return 0;
		}
		for(int i=0;i<ninos;i++){
			orden.insertar(i,i+1);
		}
		do{
			orden.girar(saltos);
		}while(orden.getN()!=1);
		cout<<orden.getValor(0)<<endl;
		orden.~ListaCircular();
	}while(true);
	return 0;
}
