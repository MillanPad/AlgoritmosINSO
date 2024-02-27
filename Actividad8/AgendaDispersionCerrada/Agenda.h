#include <string>
#include <iostream>
#include <stdlib.h>
#include "assertdomjudge.h"
using namespace std;

class Agenda
{
private:
    int capacidad;
    int n;
    string *nombres;
    long* telefonos;
    bool* vacias;
    bool* borradas;

public:
    Agenda(int capacidad);
    int obtenerPosicion(long telefono);
    int buscarContacto(long telefono);
    int buscarHueco(long telefono);
    bool isLlena();
    bool existeContacto(long telefono);
    string getContacto(long telefono);
    void introducirContacto(long telefono, string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
    ~Agenda();
};
