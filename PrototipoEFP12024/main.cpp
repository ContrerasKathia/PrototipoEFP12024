#include <iostream>
#include "AUTENTICACION.h"
#include "Usuarios.h"
#include "Bitacora.h"

void menuGeneral();
void catalogos();
void procesos();
void reportes();
string user, contrasena;

using namespace std;

int main()
{
    AUTENTICACION ingreso(user, contrasena);

    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}
void menuGeneral()
{
    string codigoPrograma="4001";
    Bitacora Auditoria;
//---------------Trae usuario, solucion a bitacora: Pablo Palencia 9959-23-736 ----------------------PR----
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
    //----------------------------------fin arregla bitacora-------------------------------------------PR-----

    int choice;
    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   MENU GENERAL    |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Informes" << endl;
        cout << "\t\t\t 3. Seguridad" << endl;
        cout << "\t\t\t 4. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:

            //procesos();
            break;
        case 3:
            Auditoria.visualizarBitacora();
            //reportes();
            break;
        case 4:
                Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
            exit(0);
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 4);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - CATALOGOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Usuarios" << endl;
        cout << "\t\t\t 2. Pacientes" << endl;
        cout << "\t\t\t 3. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-7]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Usuarios usuario1;
            usuario1.menuUsuarios();

        }
            break;
        case 2:
        {

        }
            break;
        case 3:
        {
            menuGeneral();
        }
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 7);
}

void procesos(){

}
