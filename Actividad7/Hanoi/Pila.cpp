#include "Pila.h"


Pila::Pila(string name){
  this->cima = NULL;
  this->name = name;
}

std::string Pila::nombrePila()
{
  return this->name;
}

void Pila::apilar(int num)
{
  Nodo *aux = new Nodo(num,this->cima);
  this->cima = aux;
  cout<<"Apilando disco "<<num<<" en poste "<<this->name<<endl;
}
  
int Pila::desapilar()
{    
  Nodo *aux;
	aux = this->cima;
  this->cima = aux->siguiente;
  int num = aux->valor;
  delete[] aux;
  cout<<"Desapilando disco "<<num<<" del poste "<<this->name<<endl; 
  return num;	
}

bool Pila::estaVacia()
{
	if (this->cima == NULL)
    return true;
  else
    return false;
}

