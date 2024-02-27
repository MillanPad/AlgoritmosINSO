#include "ColaPrioridad.h"
#include "assertdomjudge.h"
//Repasar apuntes en el que sale la lista
void ColaPrioridad::encolar(int num){
	int posicion_hijo,posicion_padre,resto;
	int valor_padre,pos;
	bool seCumple=false;
	this->vector.insertarAlFinal(num);
	while(seCumple==false){
		posicion_hijo=this->vector.buscar(num);
		if(posicion_hijo==0){
			seCumple=true;
		}else{
			posicion_padre=(posicion_hijo/2);
			valor_padre=this->vector.getValor(posicion_padre);
			if(valor_padre>num){
				this->vector.setValor(posicion_padre,num);
				this->vector.setValor(posicion_hijo,valor_padre);
			}else if(valor_padre<num){
				seCumple=true;
			}
		}
	}
}
int ColaPrioridad::desencolar(){
	assertdomjudge(!this->estaVacia());
	int aux,pos;
	pos=this->vector.getN();
	aux=this->vector.getValor(0);
	this->vector.setValor(0,this->vector.getValor(pos-1));
	this->vector.eliminarAlFinal();
	if(pos!=0){
		this->reestructurar();
	}
	return aux;
}
bool ColaPrioridad::estaVacia(){
	int pos;
	pos=this->vector.getN();
	if(pos==0){
		return true;
	}
	return false;
}
void ColaPrioridad::reestructurar(){
	int contador=0;
	bool controlador;
	if(this->vector.getN()!=0){
		controlador=true;
	}else{
		controlador=false;
	}
	int valor_padre;
	int posicion_hijo1=1,posicion_hijo2=2;
	
	int n = this->vector.getN();
	while(controlador){
		valor_padre=this->vector.getValor(contador);
		if(posicion_hijo1<n){
			if(posicion_hijo2<n){
				if(this->vector.getValor(posicion_hijo1)<=this->vector.getValor(posicion_hijo2)){
					if(this->vector.getValor(posicion_hijo1)<valor_padre){
						this->vector.setValor(contador,this->vector.getValor(posicion_hijo1));
						contador=(2*contador)+1;
						this->vector.setValor(contador,valor_padre);
					}else{
						controlador=false;
					}
				}else{
					if(this->vector.getValor(posicion_hijo1)<valor_padre){
						this->vector.setValor(contador,this->vector.getValor(posicion_hijo2));
						contador=(2*contador)+2;
						this->vector.setValor(contador,valor_padre);
					}else{
						controlador=false;
					}
				}
				posicion_hijo1 = (2*contador)+1;
                posicion_hijo2 = posicion_hijo1 + 1;
            }else{
            	if(this->vector.getValor(posicion_hijo1)<valor_padre){
            		this->vector.setValor(contador,this->vector.getValor(posicion_hijo1));
					contador=(2*contador)+1;
					this->vector.setValor(contador,valor_padre);
				}else{
					controlador=false;
				}
            }
        }else{
			controlador=false;			
		}
	}
	
}
