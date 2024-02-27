#include <string>
#include <iostream>
#include <stdlib.h>
#include "assertdomjudge.h"
using namespace std;

class Agenda
{
private:
    int capacidad;
    string *nombres;
    long* telefonos;
    bool* ocupados;

public:
    Agenda(int capacidad);
    int obtenerPosicion(long telefono);
    bool existeContacto(long telefono);
    string getContacto(long telefono);
    void introducirContacto(long telefono, string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
    ~Agenda();
};

