#ifndef USUARIOS_H
#define USUARIOS_H

#include<iostream>

using std::string;




class Usuarios
{
    public:

        bool loginUsuarios();
        void menuUsuarios();
        bool buscar(string user, string passw);
        string getNombre();
        string setNombre(string nombre);

        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        alumnos(string usu, string contra);
        string setid(string usu);
        string getid();

        string setnombre(string contra);
        string getnombre();

    protected:

    private:

		string name;
		string pass;

};

#endif
