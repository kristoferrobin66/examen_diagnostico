#include <iostream>
#include "paquete.h"
#include "paqueteria.h"
using namespace std;

int main()
{
    Paqueteria paq;
    int opc;
    do
    {
        CLEAR;
        cout << " Instrucciones: Ingrese el numero de la opción" << endl
             << " a ejecutar" << endl << endl
             << " 1) Insertar al inicio"   << endl
             << " 2) Eliminar al inicio"   << endl
             << " 3) Mostrar"              << endl
             << " 4) Guardar (archivo)"    << endl
             << " 5) Recuperar (archivo)"  << endl
             << " 6) Salir"                << endl
             << " Opción: ";
        cin >> opc;
        cin.ignore();
        CLEAR;
        switch(opc)
        {
            case 1:
            {
                string id;
                string origen;
                string destino;
                float peso;
                Paquete tmp;
                cout << " Ingrese los siguientes datos del paquete:" << endl
                     << endl
                     << " ID: ";
                getline(cin, id);
                cout << endl << " Origen: ";
                getline(cin, origen);
                cout << endl << " Destino: ";
                getline(cin, destino);
                cout << endl << " Peso: ";
                cin >> peso;
                tmp.setId(id);
                tmp.setPeso(peso);
                tmp.setOrigen(origen);
                tmp.setDestino(destino);
                paq.insertarInicio(tmp);
                cout << endl << " Paquete añadido" << endl;
                cin.ignore();
            }
            break;

            case 2:
                paq.eliminarInicio();
                cout << " Paquete eliminado" << endl;

            break;

            case 3:
                paq.mostrar();
            break;

            case 4:
                paq.guardar();
                cout << " Paquete guardado" << endl;
            break;

            case 5:
                paq.recuperar();
                cout << " Paquete recuperado" << endl;
            break;

            default:
            break;
        }
        cout << endl << " Presione ENTER para continuar" << endl;
        cin.get();
    }while(opc != 6);

    CLEAR;
    return 0;
}
