#ifndef PACIENTE_H
#define PACIENTE_H

#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

struct Paciente {
    int id;
    char nombre[50];
    char apellido[50];
    char fechanac[50];
    int genero;
    char direccion[50];
    int telefono;
    int estado;
};


class PacienteCrud
{
    public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void Reportes();
    void Crud();
};
#endif // PACIENTE_H
