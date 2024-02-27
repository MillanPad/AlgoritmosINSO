#include <iostream>
#include <stdlib.h>
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
ListaEnlazada::ListaEnlazada(){
	this->n=0;
	this->lista=NULL;
}
ListaEnlazada::~ListaEnlazada(){
	for(int i = 0; i<this->n; i++){
		this->eliminar(0);
	}
}
Nodo * ListaEnlazada::getNodo(int posicion){
	Nodo *aux1 = this->lista;
	for(int i = 0; i<posicion; i++){
	    aux1 = aux1->siguienteNodo;
	}
	return aux1;
}
int ListaEnlazada::getValor(int posicion){
	assertdomjudge(0<=posicion && posicion<this->n);
	Nodo *aux1 = this->getNodo(posicion);
	return aux1->elemento;
}
void ListaEnlazada::setValor(int posicion, int nuevoValor){
	assertdomjudge(0<=posicion && posicion<this->n);
	Nodo *aux1 = this->getNodo(posicion);
	aux1->elemento = nuevoValor;
}
int ListaEnlazada::getN(){
	return this->n;
}
void ListaEnlazada::insertar(int posicion, int nuevoValor){
	assertdomjudge(0<=posicion);
	Nodo *aux1 = new Nodo();
	Nodo *aux2 = this->getNodo(posicion-1);
	if(this->n == 0){
		this->lista = aux1;
		this->lista->siguienteNodo = this->lista;
		this->lista->elemento = nuevoValor;
	}else{
		aux1->elemento=nuevoValor;
		aux1->siguienteNodo=aux2->siguienteNodo;
		aux2->siguienteNodo=aux1;
	}
	this->n++;
}
void ListaEnlazada::eliminar(int posicion){
	assertdomjudge(0<=this->n);
	Nodo *aux1 = this->lista;
	Nodo *aux2 = aux1;
	this->lista = this->lista->siguienteNodo;
	aux1->siguienteNodo = this->lista;
	aux2 = NULL;
	delete aux2;
	aux1 = aux1->siguienteNodo;
	this->n--;
}
void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
	for(int i = 0; i < listaAConcatenar->n; i++){
        insertar(this->n, listaAConcatenar->lista->elemento);
        listaAConcatenar->eliminar(i);
    }
}
int ListaEnlazada::buscar(int elementoABuscar){
	assertdomjudge(0<=this->n);
	for(int i=0;i<=this->n;i++){
		if(this->getValor(i)==elementoABuscar){
			return i;
		}
	}
	return -1;
}
