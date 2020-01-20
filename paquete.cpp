#include "paquete.h"

// SOBRECARGA DE OPERADORES
std::ostream& operator <<(std::ostream &os, const Paquete& paquete)
{
    os << paquete.getId()      << "|"
       << paquete.getPeso()    << "|"
       << paquete.getOrigen()  << "|"
       << paquete.getDestino() << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Paquete& paquete)
{
    std::string aux;
    getline(is, aux, '|');
    if(aux.size() > 0)
    {
        paquete.setId(aux);

        getline(is, aux, '|');
        paquete.setPeso(stof(aux));

        getline(is, aux, '|');
        paquete.setOrigen(aux);

        getline(is, aux);
        paquete.setDestino(aux);
    }
    return is;
}

// GETTERS
std::string Paquete::getId() const
{ return m_id; }

std::string Paquete::getOrigen() const
{ return m_origen; }

std::string Paquete::getDestino() const
{ return m_destino; }

float Paquete::getPeso() const
{ return m_peso; }

// SETTERS
void Paquete::setId(const std::string &id)
{ m_id = id; }

void Paquete::setPeso(const float &peso)
{ m_peso = peso; }


void Paquete::setOrigen(const std::string &origen)
{ m_origen = origen; }

void Paquete::setDestino(const std::string &destino)
{ m_destino = destino; }
