#include "paqueteria.h"

void Paqueteria::menu()
{
    int opc;
    do
    {
        CLEAR;
        cout << " Instrucciones: Ingrese el numero de la opción" << endl
             << " a ejecutar" << endl << endl
             << " " << INSERTAR << ") Insertar paquete"    << endl
             << " " << ELIMINAR << ") Eliminar paquete"    << endl
             << " " << MOSTRAR  << ") Mostrar paquetes"    << endl
             << " " << GUARDAR  << ") Guardar (archivo)"   << endl
             << " " << RECUPERAR<< ") Recuperar (archivo)" << endl
             << " " << SALIR    << ") Salir"               << endl
             << " Opción: ";
        cin >> opc;
        cin.ignore();
        CLEAR;
        switch(opc)
        {
            case INSERTAR:
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
                insertarInicio(tmp);
                cout << endl << " Paquete añadido" << endl;
                cin.ignore();
            }
            break;

            case ELIMINAR:
                eliminarInicio();
            break;

            case MOSTRAR:
                mostrar();
            break;

            case GUARDAR:
                guardar();
                cout << " Paquete guardado" << endl;
            break;

            case RECUPERAR:
                recuperar();
                cout << " Paquete recuperado" << endl;
            break;

            default:
            break;
        }
        cout << endl << " Presione ENTER para continuar" << endl;
        cin.get();
    } while(opc != SALIR);

    CLEAR;
}

void Paqueteria::insertarInicio(const Paquete& paquete)
{
    m_paquetes.push_back(paquete);
}

void Paqueteria::eliminarInicio()
{
    if (!m_paquetes.size())
        std::cout << " No hay paquetes para borrar" << std::endl;
    else
    {
        m_paquetes.pop_back();
        cout << " Paquete eliminado" << endl;
    }
}

void Paqueteria::mostrar()
{
    CLEAR;
    if (!m_paquetes.size())
        std::cout << " Aún no se han agregado paquetes" << endl;
    for (size_t i = 0; i < m_paquetes.size(); ++i)
    {
        std::cout << " Paquete #" << i + 1 << std::endl
                  << " ID      : " << m_paquetes[i].getId() << std::endl
                  << " Origen  : " << m_paquetes[i].getOrigen() << std::endl
                  << " Destino : " << m_paquetes[i].getDestino()<< std::endl
                  << " Peso    : " << m_paquetes[i].getPeso() << std::endl
                  << "---------------------------------------------------------"
                  << std::endl;
    }
}

void Paqueteria::guardar()
{
    ofstream salida("paquetes.txt");
    if(!salida.is_open())
        std::cout << " Error en el archivo de entrada" << std::endl;
    else
    {
        for(size_t i = 0; i < m_paquetes.size(); ++i)
        {
            salida << m_paquetes[i];
        }
        salida.close();
    }
}

void Paqueteria::recuperar()
{
    ifstream entrada("paquetes.txt");
    if(entrada.fail())
        std::cout << " Error en el archivo de salida" << std::endl;
    else
    {
        Paquete aux;
        while (entrada >> aux)
        {
            insertarInicio(aux);
        }
        entrada.close();
    }
}
