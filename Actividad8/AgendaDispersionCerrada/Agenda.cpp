#include "Agenda.h"
#include "assertdomjudge.h"
using namespace std;

Agenda::Agenda(int capacidad){
	this->capacidad = capacidad;
	this->n = 0;
	this->nombres = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->vacias = new bool[capacidad];
	this->borradas = new bool[capacidad];
	for(int i=0;i<capacidad;i++){
		this->nombres[i]="";
    	this->telefonos[i] = 0;
    	this->vacias[i] = true;
    	this->borradas[i] = false;
	}
}
Agenda::~Agenda(){
	delete []this->nombres;
	delete []this->telefonos;
	delete []this->vacias;
	delete []this->borradas;
}
int Agenda::obtenerPosicion(long telefono){
	int resto;
    resto = telefono % this->capacidad;
    return resto;
}
int Agenda::buscarContacto(long telefono){
	int posicion;
	posicion = this->obtenerPosicion(telefono);
	assertdomjudge(this->existeContacto(telefono));
	for(int i=posicion;i<=this->capacidad;i++){
		if(this->telefonos[i]==telefono){
			return i;
		}
	}
	return -1;
}
int Agenda::buscarHueco(long telefono){
	int i = this->obtenerPosicion(telefono);
    while(!this->vacias[i] && i<this->capacidad+1){
		i++;
    }
	return i;
}
bool Agenda::isLlena(){
	int comprobar=0;
	for(int i=0;i<=this->capacidad;i++){
		if(this->vacias[i]==false){
			comprobar++;
		}
	}
	if(this->capacidad==comprobar){
		return true;
	}
	return false;
	
}
bool Agenda::existeContacto(long telefono){
	for(int i= this->obtenerPosicion(telefono);i<this->capacidad && (!this->vacias[i] || this->borradas[i]);i++){
		if(this->telefonos[i]==telefono && !this->vacias[i]){
			return true;
		}
	}
	return false;
}
string Agenda::getContacto(long telefono){
	int posicion;
	posicion = this->buscarContacto(telefono);
	return this->nombres[posicion];
}
void Agenda::introducirContacto(long telefono, string contacto){
	int posicion;
	posicion = this->buscarHueco(telefono);
	assertdomjudge(this->vacias[posicion]==true && posicion>=0);
	this->nombres[posicion]=contacto;
	this->telefonos[posicion]=telefono;
	this->vacias[posicion]=false;
}
void Agenda::eliminarContacto(long telefono){
	int posicion;
	posicion = this->buscarContacto(telefono);
	assertdomjudge(this->existeContacto(telefono));
	this->vacias[posicion]=true;
	this->borradas[posicion]=true;
}
