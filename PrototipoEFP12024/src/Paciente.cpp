#include "Paciente.h"
#include "usuarios.h"
#include "AUTENTICACION.h"
#include "Bitacora.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std;

void PacienteCrud::Crud() {
    string user;
     string codigoPrograma="1001";
    Bitacora Auditoria;
    //-----------------------------TRAE USUARIO----------------------------
    fstream file;
    int total=0;
    file.open("bitaA.txt",ios::in);
    if(!file)
	{
		cout<<"\n\t\t\tNo hay usuarios registrados...";
		file.close();
	}
	else
	{
		file >> user;
		while(!file.eof())
		{
			total++;
			file >> user;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay usuarios...";
		}
	}
	file.close();
    //----------------------------------fin arregla bitacora------------------------------------------------

int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION - Paciente     |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Paciente"<<endl;
	cout<<"\t\t\t 2. Modificar Paciente"<<endl;
	cout<<"\t\t\t 3. Borrar Paciente"<<endl;
	cout<<"\t\t\t 4. Desplegar Paciente"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
        Ingresar();
        Auditoria.ingresoBitacora(user,codigoPrograma,"IPA"); //IPA = Create Paciente
        system("Pause");
		break;
    case 2:
        system("Cls");
        Modificar();
        Auditoria.ingresoBitacora(user,codigoPrograma,"MPA"); //MPA = MODIFICA Paciente
		system("Pause");
		break;
    case 3:
        system("Cls");
        Borrar();
        Auditoria.ingresoBitacora(user,codigoPrograma,"BPA"); //BPA = BORRA Paciente
        system("Pause");
		break;
    case 4:
        Desplegar();
        Auditoria.ingresoBitacora(user,codigoPrograma,"DPA"); //DPA = DESPLIEGUE Paciente
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}
// aqui se agregan carreras que son almacenadas
void PacienteCrud::Ingresar() {
   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Paciente--------------------------------------------"<<endl;
    Paciente paciente1;
    cout << "Ingrese el id del Paciente: ";
    cin >> paciente1.id;
    cin.ignore();
    cout << "Ingrese el nombre del Paciente: ";
    cin.getline(paciente1.nombre, 50);
    cout << "Ingrese el apellido del Paciente: ";
    cin.getline(paciente1.apellido, 50);
    cout << "Ingrese la fecha de nacimiento del Paciente: ";
    cin.getline(paciente1.fechanac, 50);
    cout << "Ingrese el genero del Paciente (1 hombre, 2 mujer): ";
    cin >> paciente1.genero;
    cin.ignore();
    cout << "Ingrese la direccion del Paciente: ";
    cin.getline(paciente1.direccion, 50);
    cout << "Ingrese el telefono del Paciente : ";
    cin >> paciente1.telefono;
    cin.ignore();
    cout << "Ingrese el estado del Paciente (1 activo, 0 inactivo): ";
    cin >> paciente1.estado;
    cin.ignore();

    ofstream archivo("Pacientes.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&paciente1), sizeof(Paciente));
    archivo.close();

    cout << "Paciente agregado exitosamente!" << endl;
}
// modificar carreras
void PacienteCrud::Modificar() {
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Modificacion de Pacientes--------------------------------------------"<<endl;
    int codigo;
    cout << "Ingrese el id del paciente a modificar: ";
    cin >> codigo;

    fstream archivo("Pacientes.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay Pacientes registrados." << endl;
        return;
    }

       Paciente paciente1;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&paciente1), sizeof(Paciente))) {
        if (paciente1.id == codigo) {
            cout << "Ingrese el nuevo nombre del Paciente: ";
            cin.ignore();
            cin.getline(paciente1.nombre,50);
            cout << "Ingrese el nuevo apellido del Paciente: ";

            cin.getline(paciente1.apellido,50);
            cout << "Ingrese la nueva fecha de nacimiento del Paciente: ";

            cin.getline(paciente1.fechanac,50);

            cout << "Ingrese la nueva direccion del Paciente: ";

            cin.getline(paciente1.direccion, 50);

            cout << "Ingrese el nuevo genero del Paciente (1 hombre, 2 mujer): ";
            cin >> paciente1.genero;

            cout << "Ingrese el nuevo telefono del Paciente : ";

            cin >> paciente1.telefono;
            cout << "Ingrese el nuevo estado del Paciente (1 activo, 0 inactivo): ";

            cin >> paciente1.estado;

            archivo.seekp(-static_cast<int>(sizeof(Paciente)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&paciente1), sizeof(Paciente));

            encontrada = true;
            break;
        }
    }

    archivo.close();


    if (!encontrada) {
        cout << "No se encontró el Paciente con el codigo ingresado." << endl;
    }
    else {
        cout << "Paciente modificado exitosamente!" << endl;
    }

}
// elimina carreras que ya no deseamos que estan registradas
void PacienteCrud::Borrar() {
    int codigo;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Eliminar Paciente--------------------------------------------"<<endl;
    cout << "Ingrese el Id del Paciente a eliminar: ";
    cin >> codigo;

    ifstream archivo("Pacientes.dat", ios::binary);
    if (!archivo) {
        cout << "No hay pacientes registradas." << endl;

    }

    ofstream archivoTmp("paciente_tmp.dat", ios::binary);
    Paciente paciente1;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&paciente1), sizeof(Paciente))) {
        if (paciente1.id != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&paciente1), sizeof(Paciente)); //reescribe en otro archivo
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("Pacientes.dat");
    rename("paciente_tmp.dat", "Pacientes.dat");

    if (eliminada) {
        cout << "Paciente eliminado exitosamente!" << endl;

    } else {
        cout << "No se encontró el Paciente con el codigo ingresado." << endl;
    }

}
// Nos muestra las carreras registradas
void PacienteCrud::Desplegar() {
    system("cls");
    cout<<"-----------------Despliegue de Pacientes registradas---------------------"<<endl;
    ifstream archivo("Pacientes.dat", ios::binary);
    if (!archivo) {
        cout << "No hay Pacientes registrados." << endl;
        return;
    }
    Paciente paciente1;
    while (archivo.read(reinterpret_cast<char*>(&paciente1), sizeof(Paciente))) {
        cout << "ID: " << paciente1.id << endl;
        cout << "Nombre: " << paciente1.nombre << endl;
        cout << "Apellido: " << paciente1.apellido << endl;
        cout << "Fecha de nacimiento: " << paciente1.fechanac << endl;
        cout << "Genero: " << paciente1.genero << endl;
        cout << "Direccion: " << paciente1.direccion << endl;
        cout << "Telefono: " << paciente1.telefono << endl;
        cout << "Estado: " << paciente1.estado << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();


    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
void PacienteCrud::Reportes(){
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------INFORMES PACIENTES --------------------------------------------"<<endl;
    int codigo;
    cout << "Ingrese el id del Paciente que desea imprimir: ";
    cin >> codigo;

    fstream archivo("Pacientes.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay Pacientes registrados." << endl;
        return;
    }

    Paciente paciente1;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&paciente1), sizeof(Paciente))) {
        if (paciente1.id == codigo) {
            cout << "ID: " << paciente1.id << endl;
            cout << "Nombre: " << paciente1.nombre << endl;
            cout << "Apellido: " << paciente1.apellido << endl;
            cout << "Fecha de nacimiento: " << paciente1.fechanac << endl;
            cout << "Genero: " << paciente1.genero << endl;
            cout << "Direccion: " << paciente1.direccion << endl;
            cout << "Telefono: " << paciente1.telefono << endl;
            cout << "Estado: " << paciente1.estado << endl;
            cout << "-----------------------------" << endl;
            FILE *arch = fopen("Reporte1_Paciente.txt", "wt");
			// Se verifica si se abrió correctamente el archivo de texto
            if (arch == NULL) {
                cerr << "Error al imprimir informe." << endl;
                // Si hay un error, se termina la ejecución del programa
                exit(1);
            }
			// Se escriben los datos del acta en el archivo de texto
            fprintf(arch, "Id: %d\n", paciente1.id);
            fprintf(arch, "Nombre:   %s\n",paciente1.nombre);
            fprintf(arch, "Apellido:   %s\n",paciente1.apellido);
            fprintf(arch, "Fecha de nacimiento:   %s\n",paciente1.fechanac);
            fprintf(arch, "Genero:   %s\n",paciente1.genero);
            fprintf(arch, "Direccion:   %s\n",paciente1.direccion);
            fprintf(arch, "Telefono:   %s\n",paciente1.telefono);
            fprintf(arch, "estado:   %s\n",paciente1.estado);
            // Se cierra el archivo de texto.
            fclose(arch);
            // Se informa al usuario que se creó el archivo de texto con los datos del acta
            cout << "Se imprimio correctamente (Reporte_Paciente)" << endl;
            getch();
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró Paciente con el codigo ingresado." << endl;
    }
    archivo.close();
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

}
