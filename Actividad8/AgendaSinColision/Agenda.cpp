#include "Agenda.h"
#include "assertdomjudge.h"
using namespace std;
Agenda:: Agenda(int capacidad){
    this->capacidad=capacidad;
    this->nombres= new string[capacidad];
    this->telefonos= new long[capacidad];
    this->ocupados=new bool[capacidad];
    for(int i=0;i<=capacidad;i++){
    	this->telefonos[i]=0;
    	this->ocupados[i]=0;
	}
}
Agenda::~Agenda(){
    delete []this->nombres;
    delete []this->telefonos;
    delete []this->ocupados;
}
int Agenda::obtenerPosicion(long telefono){
    int resto;
    resto = telefono % this->capacidad;
    assertdomjudge(this->ocupados[resto]==1);
    return resto;
}
bool Agenda::existeContacto(long telefono){
    int resto;
    resto = this->obtenerPosicion(telefono);
    if (this->ocupados[resto]==1 && this->telefonos[resto]==telefono){
        return true;
    }else
    {
        return false;
    }
}
string Agenda::getContacto(long telefono){
    int resto;
    resto = this->obtenerPosicion(telefono);
    assertdomjudge(this->existeContacto(telefono)==true);
    return this->nombres[resto];
}
void Agenda::introducirContacto(long telefono, string contacto){
    int resto;
    resto = this->obtenerPosicion(telefono);
    assertdomjudge(this->ocupados[resto]==0 && this->telefonos[resto]!=telefono);
    this->nombres[resto]=contacto;
    this->telefonos[resto]=telefono;
    this->ocupados[resto]=1;
}
void Agenda::eliminarContacto(long telefono){
    int resto;
    resto = this->obtenerPosicion(telefono);
    assertdomjudge(this->ocupados[resto]==1 && this->telefonos[resto]==telefono);
    this->ocupados[resto]=0;
}


