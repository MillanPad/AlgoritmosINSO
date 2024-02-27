#include "ListaContigua.h"
//#include "assertdomjudge.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
	ListaContigua::ListaContigua(int incremento){
		this->capacidad = incremento;
		this->incremento = incremento;
		this->n = 0;
		this->vector= new int[incremento];	
	}
	
	int ListaContigua::getValor(int posicion){
		//assertdomjudge((posicion >= 0) && (posicion < n));
		return this->vector[posicion];
	} 
	void ListaContigua::setValor(int posicion, int nuevoValor){
		//assertdomjudge((posicion >= 0) && (posicion < n));
		this->vector[posicion] = nuevoValor;
	}
	int ListaContigua::getN(){
		return this->n;
	}
	int ListaContigua::getCapacidad(){
		return this->capacidad;
	}
	void ListaContigua::insertar(int posicion, int nuevoValor){
		//assertdomjudge((posicion >= 0) && (posicion <= n));
		int nuevapos=posicion+1;
        if(this->n == this ->capacidad){
            this->capacidad+=incremento;
            this->vector=(int*) realloc(vector,(sizeof(this->incremento)*this->capacidad));
            
        }

		memmove(&vector[nuevapos],&vector[posicion],sizeof(int)*(this->n-posicion));
		this->vector[posicion]=nuevoValor;
        this->n++;
		
	}
	void ListaContigua::eliminar(int posicion){
	
		//assertdomjudge((posicion >= 0) && (posicion < n));
		int nuevapos=posicion+1;
		memmove(&vector[posicion],&this->vector[nuevapos],(this->capacidad-posicion)*sizeof(int));
		this->n--;
		if(this->n <= this->capacidad-2*this->incremento){
        	this->capacidad -= this->incremento;
        	this->vector = (int*) realloc(vector, this->capacidad*sizeof(this->incremento));
    	}
	}
	void ListaContigua::concatenar(ListaContigua *lista){
		for(int i = 0; i < lista->n; i++){
        	insertar(this->n, lista->vector[i]);
    	}
	}
	int ListaContigua::buscar(int elemento){
		for(int i=0;i<=this->n;i++){
			if(this->vector[i]==elemento){
				return i;
			}
		}
		return -1;
	}
	ListaContigua::~ListaContigua(){
		delete this->vector;
	}
