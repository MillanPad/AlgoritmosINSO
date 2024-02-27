#include<iostream>
#include<string.h>
using namespace std;
bool comprobacion(char * cadena, int primerCaracter, int ultimoCaracter) {
    if (primerCaracter >= ultimoCaracter){
		return 1;
	}
    if (cadena[primerCaracter] == cadena[ultimoCaracter]) {
        return comprobacion(cadena, primerCaracter + 1, ultimoCaracter - 1);
    } else {
        return 0;
    }
}
int main() {
	char cadena[50];
	int longitud;
	cin.getline(cadena,50);
	longitud=strlen(cadena);
    bool resultadoRecursivo = comprobacion(cadena, 0, longitud-1);
    cout << resultadoRecursivo;
    return 0;
}
