#include <iostream>
#include "ListaCircular.h"


ListaCircular::ListaCircular(){
  this->lista = NULL;
  this->n = 0;
}
ListaCircular::~ListaCircular(){
  for(int i = 0; i<this->n; i++){
    this->eliminar(0);
  }
}
Nodo *ListaCircular::getNodo(int posicion){
  Nodo *aux1 = this->lista;
  for(int i = 0; i<posicion; i++){
    aux1 = aux1->siguienteNodo;
  }
  return aux1;
}
int ListaCircular::getValor(int posicion){
  Nodo *aux1 = this->getNodo(posicion);
  return aux1->elemento;
}
void ListaCircular::setValor(int posicion, int nuevoValor){
  Nodo *aux1 = this->getNodo(posicion);
  aux1->elemento = nuevoValor;
}
int ListaCircular::getN(){
 return this->n;
}
void ListaCircular::insertar(int posicion, int nuevoValor){
  Nodo *aux1 = new Nodo(); 
  if(this->n == 0){
  this->lista = aux1;
  this->lista->siguienteNodo = this->lista;
  this->lista->anteriorNodo = this->lista;
  this->lista->elemento = nuevoValor;
  }
  else{
    aux1->elemento = nuevoValor;
    Nodo *aux2 = this->getNodo(posicion);
    Nodo *aux3 = aux2->anteriorNodo;
    aux3->siguienteNodo = aux1;
    aux1->anteriorNodo = aux3;
    aux1->siguienteNodo = aux2;
    aux2->anteriorNodo = aux1;
  }
  this->n++;
}
void ListaCircular::eliminar(int posicion){
  Nodo *aux1 = this->lista;
  Nodo *aux2 = aux1;
  this->lista = this->lista->siguienteNodo;
  aux1 = aux1->anteriorNodo;
  aux1->siguienteNodo = this->lista;
  this->lista->anteriorNodo = aux1;
  aux2 = NULL;
  delete aux2;
  aux1 = aux1->siguienteNodo;
  this->n--;
}
void ListaCircular::girar(int p){
    for(int i = 0; i<p; i++){

      	this->lista = this->lista->siguienteNodo;

    }
    this->eliminar(0);
}
