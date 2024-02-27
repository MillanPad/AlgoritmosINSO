#include "Matriz.h"
#include <iostream>
#include <math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}



//Asignacion de matrices

Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
	delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
	{
	  matriz[i] = new double[n_columnas];  
	  for(int j=0; j <n_columnas; j++)
	    matriz[i][j]=m.matriz[i][j];
	}
    }
  
    return(*this); 
}


// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
    {
      cout << "Fila " << i << endl;
      for (int j = 0; j < n_columnas; j++)
	{
	  cout << "Elemento " << j  << endl;
	  cin >> elemento;
	  matriz[i][j] = elemento;
        }
      cout << endl;
    }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
      {
	for (int j = 0; j < n_columnas; j++)
	  cout << matriz[i][j] << " ";       
        cout << endl;
    }
}
Matriz::Matriz() {
	this->n_filas = 0;
	this->n_columnas = 0;
	this->matriz = NULL;
}
//Crea la Matriz con parametros
Matriz::Matriz(int n_filas, int n_columnas){
       this -> n_columnas = n_columnas;     
       this -> n_filas = n_filas;
       if(n_filas > 0 && n_columnas > 0){
	       this->matriz = new double*[n_filas];
	       for(int i=0;i<n_filas;i++){
	       		this->matriz[i] = new double[n_columnas];
		   }
		}
}
//Copia la Matriz
Matriz::Matriz(Matriz &m){
    this->n_filas = m.n_filas;
	this->n_columnas = m.n_columnas;
	this->matriz = NULL;
	if (n_filas > 0 && n_columnas > 0){
		this->matriz = new double* [n_filas];
		for (int i = 0; i < m.n_filas; i++){
			this->matriz[i] = new double[n_columnas];
			for (int j = 0; j < m.n_columnas; j++)
				this->matriz[i][j] = m.matriz[i][j];
		}
	}
}
//Borra la Matriz
Matriz::~Matriz(){
    if (this->matriz != NULL){
		for (int i = 0; i < this->n_filas; i++)
			delete[] this->matriz[i];
		delete[] this->matriz;
		this->matriz = NULL;
	}
}
//Suma dos Matrices
Matriz Matriz::operator+ (const Matriz m1){
	assertdomjudge(this->n_columnas==m1.n_filas);
	Matriz m2(m1.n_filas,m1.n_columnas);
 	for(int i=0;i<(this->n_filas);i++){
        for(int j=0;j<(this->n_columnas);j++)
            m2.matriz[i][j]=this->matriz[i][j]  + m1.matriz[i][j];
    }
       
    return m2;
}
//Resta dos Matrices
 Matriz Matriz::operator - (const Matriz m1){
 	assertdomjudge(this->n_columnas==m1.n_filas);
    Matriz m2(m1.n_filas,m1.n_columnas);
    for(int i=0;i<m1.n_filas;i++){
        for(int j=0;j<(this->n_columnas);j++)
            m2.matriz[i][j]=this->matriz[i][j] -  m1.matriz[i][j];
    }
    return m2;
}
//Producto escalar de una Matriz
Matriz Matriz::operator * (int a){
    Matriz m2(this->n_filas,this->n_columnas);
    for(int i=0;i<(this->n_filas);i++){
        for(int j=0;j<(this->n_columnas);j++)
            m2.matriz[i][j]=this->matriz[i][j] * a;
    }
    return m2;
}
//Porducto por una Matriz
Matriz Matriz::operator * (const Matriz m1){
	assertdomjudge(this->n_columnas==m1.n_filas);
    Matriz m2(this->n_filas,this->n_columnas);
    for(int i=0;i<(this->n_filas);i++){
        for(int j=0;j<(m1.n_columnas);j++){
        	m2.matriz[i][j]=0;
        	for(int k=0;k<this->n_columnas;k++)
            	m2.matriz[i][j]=m2.matriz[i][j]+this->matriz[i][k] *  m1.matriz[k][j];
    	}
    }
    return m2;
}
//Calcula la Matriz transpuesta
Matriz Matriz::calcularTraspuesta (){
	assertdomjudge(this->n_filas==this->n_columnas);
    Matriz m2(this->n_filas,this->n_columnas);
    for(int i=0;i<(this->n_filas);i++){
        for(int j=0;j<(this->n_columnas);j++)
            m2.matriz[i][j]=this->matriz[j][i];
    }
    return m2;
}  
//Te dice si la matriz es simetrica
bool Matriz::esSimetrica() {
	assertdomjudge(this->n_filas == this->n_columnas);
	for (int i = 0; i < this->n_filas; i++){
		for (int j = 0; j < this->n_filas; j++){
			if (this->matriz[j][i] != this->matriz[i][j])
				return false;
		}
	}
	return true;
}
//Obtener maximo
double Matriz::obtenerMaximo() {
	double maximo = this->matriz[0][0];
	for (int i = 0; i < this->n_filas; i++) {
		for (int j = 0; j < this->n_filas; j++) {
			if (this->matriz[i][j] > maximo) {
				maximo = this->matriz[i][j];
			}
		}
	}
	return maximo;
}
 
//Obtener minimo
double Matriz::obtenerMinimo() {
	double minimo = this->matriz[0][0];
	for (int i = 0; i < this->n_filas; i++) {
		for (int j = 0; j < this->n_filas; j++) {
			if (this->matriz[i][j] < minimo) {
				minimo = this->matriz[i][j];
			}
		}
	}
	return minimo;
}
