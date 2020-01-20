#ifndef PAQUETERIA_H
#define PAQUETERIA_H

#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR std::system("cls")
#else
    #define CLEAR std::system("clear")
#endif

#include <iostream>
#include <string>
#include "lsl.h"
#include "paquete.h"
#include "fstream"

class Paqueteria
{
public:
    Paqueteria(){}
    virtual ~Paqueteria(){}

    void insertarInicio(const Paquete& paquete);
    void eliminarInicio();
    void mostrar();
    void guardar();
    void recuperar();

private:
    LSL<Paquete> m_paquetes;
};

#endif // PAQUETERIA_H
