#include "paqueteria.h"

void Paqueteria::insertarInicio(const Paquete& paquete)
{
    m_paquetes.push_back(paquete);
}

void Paqueteria::eliminarInicio()
{
    m_paquetes.pop_back();
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
