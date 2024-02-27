#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"
#include "stdlib.h"

using namespace std;
ABB::ABB(){
	this->raiz=new Nodo[this->n];
	this->n=0;
}

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}
ABB::~ABB(){
	this->eliminarSubarbol(this->raiz);
	delete []this->raiz;
}
void ABB::eliminarSubarbol(Nodo *raizSubarbol){
	if(raizSubarbol->contenido!=0LL){
    	if(raizSubarbol->hijoIzquierdo->contenido!=0LL){
    		if(raizSubarbol->hijoDerecho->contenido!=0LL){
    			eliminarSubarbol(raizSubarbol->hijoIzquierdo);
    			eliminarSubarbol(raizSubarbol->hijoDerecho);
			}else{
				eliminarSubarbol(raizSubarbol->hijoIzquierdo);
			}
		}else{
			if(raizSubarbol->hijoDerecho->contenido!=0LL){
    			eliminarSubarbol(raizSubarbol->hijoDerecho);
			}else{
				raizSubarbol->hijoIzquierdo=NULL;
				raizSubarbol->hijoDerecho=NULL;
			}
		} 
    }else{
    	raizSubarbol->contenido=0LL;
    }
}
void ABB::insertar(int nuevoElemento){
	this->raiz->padre=this->buscarHueco(this->raiz,nuevoElemento);
}

Nodo * ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){
	if(raizSubarbol->contenido!=0LL){
    	if(raizSubarbol->hijoDerecho->contenido==0LL){
    		if(raizSubarbol->hijoIzquierdo->contenido==0LL){
    			if(raizSubarbol->contenido>elementoAInsertar){
    				raizSubarbol->hijoIzquierdo->contenido=elementoAInsertar;
    				raizSubarbol->hijoIzquierdo->padre=raizSubarbol;
    				return raizSubarbol;
				}else{
					raizSubarbol->hijoDerecho->contenido=elementoAInsertar;
    				raizSubarbol->hijoDerecho->padre=raizSubarbol;
    				return raizSubarbol;
				}
			}else{
				if(raizSubarbol->contenido<elementoAInsertar){
    				raizSubarbol->hijoDerecho->contenido=elementoAInsertar;
    				raizSubarbol->hijoDerecho->padre=raizSubarbol;
    				return raizSubarbol;
				}else{
					return buscarHueco(raizSubarbol->hijoIzquierdo,elementoAInsertar);
				}
			}
		}else{
			if(raizSubarbol->hijoIzquierdo->contenido==0LL){
    			if(raizSubarbol->contenido>elementoAInsertar){
    				return buscarHueco(raizSubarbol->hijoIzquierdo,elementoAInsertar);
				}else{
					raizSubarbol->hijoDerecho->contenido=elementoAInsertar;
    				raizSubarbol->hijoDerecho->padre=raizSubarbol;
    				return raizSubarbol;
				}
			}else{
				if(raizSubarbol->contenido<elementoAInsertar){
    				return buscarHueco(raizSubarbol->hijoDerecho,elementoAInsertar);
				}else{
					return buscarHueco(raizSubarbol->hijoIzquierdo,elementoAInsertar);
				}
			}
		}
    }else{
    	raizSubarbol->contenido=elementoAInsertar;
    	return raizSubarbol->padre;
    }
}
Nodo * ABB::buscar(int elementoABuscar){
	return buscarRecursivo(this->raiz, elementoABuscar);
}
Nodo * ABB::buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar){
	if(raizSubarbol->contenido!=elementoABuscar){
    	if(raizSubarbol->hijoIzquierdo->contenido==elementoABuscar){
    		return raizSubarbol->hijoIzquierdo;
		}else{
			if(raizSubarbol->hijoDerecho->contenido==elementoABuscar){
    			return raizSubarbol->hijoDerecho;
			}else{
				if(raizSubarbol->contenido>elementoABuscar){
					return buscarRecursivo(raizSubarbol->hijoIzquierdo,elementoABuscar);
				}else{
					return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
				}
			}
		} 
    }else{
    	return raizSubarbol;
    }
}
void ABB::eliminar(int elementoAEliminar){
	//Revisar
	Nodo *aux1=this->buscar(elementoAEliminar);
	if(aux1->hijoDerecho==NULL){
		this->buscar(elementoAEliminar)==this->buscarMaximo(aux1->hijoIzquierdo);
	}else if(aux1->hijoIzquierdo==NULL){
		this->buscar(elementoAEliminar)==this->buscarMinimo(aux1->hijoDerecho);
	}else if(aux1->hijoDerecho!=NULL && aux1->hijoIzquierdo!=NULL){
		if(alturaNodo(aux1->hijoDerecho)>alturaNodo(aux1->hijoIzquierdo)){
			this->buscar(elementoAEliminar)==this->buscarMinimo(aux1->hijoDerecho);
		}else{
			this->buscar(elementoAEliminar)==this->buscarMaximo(aux1->hijoIzquierdo);
		}
	}else if(this->buscarMaximo(aux1)->hijoIzquierdo!=NULL || this->buscarMinimo(aux1)->hijoDerecho!=NULL){
		this->eliminarNodo(aux1);
	}
}
Nodo * ABB::buscarMaximo(Nodo *raizSubarbol){
	if(raizSubarbol->hijoDerecho==NULL){
		return raizSubarbol;
	}else{
		return buscarMaximo(raizSubarbol->hijoDerecho);
	}
}
Nodo * ABB::buscarMinimo(Nodo *raizSubarbol){
	if(raizSubarbol->hijoIzquierdo==NULL){
		return raizSubarbol;
	}else{
		return buscarMinimo(raizSubarbol->hijoIzquierdo);
	}
}
void ABB::eliminarNodo(Nodo *nodoParaEliminar){
	//Buscar una hoja en el arbol en 
	if(nodoParaEliminar->hijoDerecho==NULL && nodoParaEliminar->hijoIzquierdo){
		nodoParaEliminar=NULL;
		nodoParaEliminar->contenido=0LL;
	}else{
		if(alturaNodo(nodoParaEliminar->hijoIzquierdo)>alturaNodo(nodoParaEliminar->hijoDerecho)){
			eliminarNodo(nodoParaEliminar->hijoDerecho);
		}else{
			eliminarNodo(nodoParaEliminar->hijoIzquierdo);
		}
	}
	
}
int ABB::alturaNodo(Nodo *raizSubarbol){
	//Hacer un bucle while con un contador que compruebe que no tenga hijos el nodo y devuelva el contador
	if(raizSubarbol==NULL){
		return -1;
	}else{
		if(alturaNodo(raizSubarbol->hijoIzquierdo)>alturaNodo(raizSubarbol->hijoDerecho)){
			return 	alturaNodo(raizSubarbol->hijoIzquierdo) + 1;
		}else{
			return alturaNodo(raizSubarbol->hijoDerecho) + 1;
		}
	}
}
bool ABB::esABB(){
	
}
bool ABB::esAVL(){
	
}
