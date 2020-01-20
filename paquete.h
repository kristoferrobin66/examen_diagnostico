#ifndef PAQUETE_H
#define PAQUETE_H

#include <iostream>
#include <string>

class Paquete
{
public:
    Paquete(){}
    virtual ~Paquete(){}

    // GETTERS
    std::string getId() const;
    std::string getOrigen() const;
    std::string getDestino() const;
    float getPeso() const;

    // SETTERS
    void setId(const std::string &id);
    void setOrigen(const std::string &origen);
    void setDestino(const std::string &destino);
    void setPeso(const float &peso);

    // SOBREACARGA DE OPERADORES
    friend std::ostream& operator <<(std::ostream& os, const Paquete &paquete);
    friend std::istream& operator >>(std::istream& is, Paquete &paquete);

private:
    // EL IDENTIFICADOR DE TODOS LOS MÉTODOS COMIENZAN
    // CON "m_" PARA DIFERENCIARLOS DE OTRAS VARIABLES
    // QUE NO SEAN MIEMBRO DE ESTA CLASE
    std::string m_id;
    std::string m_origen;
    std::string m_destino;
    float m_peso;
};

#endif // PAQUETE_H
