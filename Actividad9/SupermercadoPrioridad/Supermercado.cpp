#include "Supermercado.h"
Supermercado::Supermercado(int n){
	this->cajas=new ColaPrioridad[n];
	this->n_cajas=n;
}
void Supermercado::nuevoUsuario(int n,int id){
	this->cajas[n].encolar(id);
}
void Supermercado::cerrarCaja(int n){
	int usuarios,i=0;
	while(this->cajas[n].estaVacia()==false){
		if (this->n_cajas-1<i){
			i=0;
		}		
		if(i!=n){
			usuarios=this->cajas[n].desencolar();
			this->cajas[i].encolar(usuarios);
		}
		i++;
	}
}
int Supermercado::atenderUsuario(int n){
	int usuario;
	usuario=this->cajas[n].desencolar();
	return usuario;
}
bool Supermercado::cajaVacia(int n){
	if(this->cajas[n].estaVacia()==true){
		return true;
	}
	return false;
}
