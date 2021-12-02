#include "Vehiculo.h"

Vehiculo::Vehiculo()
{
    strcpy(Codigo,"");
    Marca = "";
    Modelo = "";
    Color = "";
    Anio = 0;
    Recorrido = 0;
    Motor = "";
    Traccion = "";
    Precio = 0;
}

Vehiculo::Vehiculo(char *newCodigo, std::string newMarca, std::string newModelo, std::string newColor, short newAnio, float newRecorrido, std::string newMotor, std::string newTraccion, float newPrecio)
{
    strcpy(Codigo, newCodigo);
    Marca = newMarca;
    Modelo = newModelo;
    Color = newColor;
    Anio = newAnio;
    Recorrido = newRecorrido;
    Motor = newMotor;
    Traccion = newTraccion;
    Precio = newPrecio;
}

char *Vehiculo::getCodigo() const
{
    return Codigo;
}

void Vehiculo::setCodigo(char *newCodigo)
{
    Codigo = newCodigo;
}

const string &Vehiculo::getMarca() const
{
    return Marca;
}

void Vehiculo::setMarca(const string &newMarca)
{
    Marca = newMarca;
}

const string &Vehiculo::getModelo() const
{
    return Modelo;
}

void Vehiculo::setModelo(const string &newModelo)
{
    Modelo = newModelo;
}

const string &Vehiculo::getColor() const
{
    return Color;
}

void Vehiculo::setColor(const string &newColor)
{
    Color = newColor;
}

short Vehiculo::getAnio() const
{
    return Anio;
}

void Vehiculo::setAnio(short newAnio)
{
    Anio = newAnio;
}

float Vehiculo::getRecorrido() const
{
    return Recorrido;
}

void Vehiculo::setRecorrido(float newRecorrido)
{
    Recorrido = newRecorrido;
}

const string &Vehiculo::getMotor() const
{
    return Motor;
}

void Vehiculo::setMotor(const string &newMotor)
{
    Motor = newMotor;
}

const string &Vehiculo::getTraccion() const
{
    return Traccion;
}

void Vehiculo::setTraccion(const string &newTraccion)
{
    Traccion = newTraccion;
}

float Vehiculo::getPrecio() const
{
    return Precio;
}

void Vehiculo::setPrecio(float newPrecio)
{
    Precio = newPrecio;
}

void Vehiculo::Imprimir()
{
    std::cout<<"\nCódigo: "<<getCodigo()
             <<"\nMarca: "<<getMarca()
             <<"\nModelo: "<<getModelo()
             <<"\nColor: "<<getColor()
             <<"\nAño: "<<getAnio()
             <<"\nRecorrido: "<<getRecorrido()
             <<"\nMotor: "<<getMotor()
             <<"\nTracción: "<<getTraccion()
             <<"\nPrecio: "<<getPrecio()
             <<"\n\n";
}
