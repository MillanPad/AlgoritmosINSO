#include <stdlib.h>
#include <iostream>
#include <math.h>
#ifndef MATRIZ_H
#define MATRIZ_H


using namespace std;

class Matriz {
 private:
  double **matriz;
  
  int n_filas;
  int n_columnas;

 public:
	Matriz();
    Matriz(int n_filas, int n_columnas);
    Matriz(Matriz &m);
    ~Matriz();
    Matriz operator + (const Matriz m1);
    Matriz operator - (const Matriz m1);
    Matriz operator * (int a);
    Matriz operator * (const Matriz m1);
    Matriz calcularTraspuesta();
    bool esSimetrica();
    double obtenerMinimo();
    double obtenerMaximo();
    double calcularDeterminante();
    
    
/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  Matriz& operator= (const Matriz &m);


/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/
  
  void rellenarManual();


/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	   Parámetro: semilla que se utiliza para el generador aleatorio
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void rellenarAleatorio(long seed);



/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void mostrarMatriz();
  
};

#endif // MATRIZ_H
