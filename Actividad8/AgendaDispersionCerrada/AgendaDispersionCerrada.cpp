#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << this->vacias[i] << " | Borrada: " << this->borradas[i] << " | Telefono: " << this->telefonos[i] << " | Nombre: " << this->nombres[i] << endl;
}

