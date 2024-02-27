#include"Cola.h" 
#include <iostream>
#include <stdlib.h>
Cola::Cola(){
	this->principio=NULL;
	this->final=NULL;
}
void Cola::encolar(int num){
	Nodo *aux= new Nodo(num);
	if(this->estaVacia()){
		this->principio=aux;
	}else{
		this->final->siguiente=aux;
	}
	this->final=aux;
}
int Cola::desencolar(){
    Nodo *aux1 = this->principio;
    this->principio =aux1->siguiente ;
    if (this->principio == NULL) {
        this->final = NULL;
    }
    int num = aux1->valor;
    return num;
}
bool Cola::estaVacia(){
    if(this->principio==NULL){
    	return true;
	}else{
		return false;
	}
}
