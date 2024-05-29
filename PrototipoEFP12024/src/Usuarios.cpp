#include "Usuarios.h"

#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Bitacora.h"
#define USER "usuario"
#define PASS "1234"

using namespace std;


void Usuarios::menuUsuarios(){
    string user;
    string codigoPrograma="6001";
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

    do {
    char x;
	system("cls");
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE SEGURIDAD - Catalogos Usuarios |"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Usuarios"<<endl;
	cout<<"\t\t\t 2. Consulta Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificacion Usuarios"<<endl;
	cout<<"\t\t\t 4. Eliminacion Usuarios"<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		Auditoria.ingresoBitacora(user,codigoPrograma,"IUS"); //IUS INGRESA USUARIO
    		cout<<"\n\t\t\t Agrega otra persona(s,n): ";
    		cin>>x;
		}while(x=='s'||x=='S');
		break;
	case 2:
		desplegar();
		Auditoria.ingresoBitacora(user,codigoPrograma,"DUS"); //DUS DESPLIEGA USUARIO
		break;
	case 3:
	    Auditoria.ingresoBitacora(user,codigoPrograma,"MUS"); //DUS DESPLIEGA USUARIO
		modificar();
		break;
	case 4:
	    Auditoria.ingresoBitacora(user,codigoPrograma,"BUS"); //DUS DESPLIEGA USUARIO
		borrar();
		break;
	case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	cin.get();
	//getch();
    }while(choice!= 5);
}
bool Usuarios::buscar(string user, string passw)
{

	system("cls");
	fstream file;
	int found=0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		file >> name >> pass;
		while(!file.eof())
		{
			if(user==name)
			{
			    if (passw == pass)
                {
                    found++;
                }
			}
			file  >> name >> pass;
		}
		if(found==0)
		{
			return false;
		}
		else
            return true;
		file.close();
	}
}
string Usuarios::getNombre()
{

    return name;
}
string Usuarios::setNombre(string nombre)
{
    name=nombre;
}

void Usuarios::insertar()
{
    system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Nombre Persona     : ";
	cin>>name;
	cout<<"\t\t\tIngresa Contraseña Persona   : ";
	cin>>pass;
	file.open("Usuarios.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";
	file.close();

}

void Usuarios::desplegar()
{
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> name >> pass;
		while(!file.eof())
		{
			total++;
			cout<<"\t\t\t Nombre Persona: "<<name<<endl;
			cout<<"\t\t\t Contraseña Persona: "<<pass<<endl;
			file >> name >> pass;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	system("pause");
}

void Usuarios::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_nom;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Nombre del usuario que quiere modificar: ";
		cin>>participant_nom;
		file1.open("Record.txt",ios::app | ios::out);
		file >> name >> pass;
		while(!file.eof())
		{
			if(participant_nom!=name)
			{
			 file1 <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Nombre Persona: ";
				cin>>name;
				cout<<"\t\t\tIngrese Contraseña Persona: ";
				cin>>pass;
				file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";
				found++;
			}
			file >> name >> pass;

		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}

void Usuarios::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_nom;
	int found=0;
	cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el nombre del usuario que quiere borrar: ";
		cin>>participant_nom;
		file1.open("Record.txt",ios::app | ios::out);
		file >> name >> pass;
		while(!file.eof())
		{
			if(participant_nom!= name)
			{
				file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< pass << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> name >> pass;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}

