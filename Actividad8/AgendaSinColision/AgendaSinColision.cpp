#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;



void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << this->ocupados[i] << " | Telefono: " << this->telefonos[i] << " | Nombre: " << this->nombres[i] << endl;
}


