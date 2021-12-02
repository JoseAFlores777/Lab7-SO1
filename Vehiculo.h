#ifndef VEHICULO_H
#define VEHICULO_H

/*#include <QMainWindow>*/
#include <iostream>
#include <cstring>
using std::string;

class Vehiculo /* : public QMainWindow*/
{
private:
    char *Codigo = new char[7];
    string Marca;
    string Modelo;
    string Color;
    short Anio;
    float Recorrido;
    string Motor;
    string Traccion;
    float Precio;

public:
    Vehiculo();
    Vehiculo(char *newCodigo,string newMarca,string newModelo, string newColor, short newAnio, float newRecorrido, string newMotor, string newTraccion, float newPrecio);

    char *getCodigo() const;
    void setCodigo(char *newCodigo);

    const string &getMarca() const;
    void setMarca(const string &newMarca);

    const string &getModelo() const;
    void setModelo(const string &newModelo);

    const string &getColor() const;
    void setColor(const string &newColor);

    short getAnio() const;
    void setAnio(short newAnio);

    float getRecorrido() const;
    void setRecorrido(float newRecorrido);

    const string &getMotor() const;
    void setMotor(const string &newMotor);

    const string &getTraccion() const;
    void setTraccion(const string &newTraccion);

    float getPrecio() const;
    void setPrecio(float newPrecio);

    void Imprimir();
};

#endif // VEHICULO_H
