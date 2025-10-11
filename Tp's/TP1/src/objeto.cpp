#include "objeto.hpp"

// Construtor padrão - inicializa com valores zero
Object::Object() : id(0), x(0), y(0), width(0) {}

// Construtor com parâmetros
Object::Object(int id_, double x_, double y_, double width_) 
    : id(id_), x(x_), y(y_), width(width_) {}

// Move objeto para novas coordenadas
void Object::move(double newX, double newY) {
    x = newX;
    y = newY;
}

// Calcula posição inicial do objeto (centro - metade da largura)
double Object::start() const {
    return x - width/2.0;
}

// Calcula posição final do objeto (centro + metade da largura)
double Object::end() const {
    return x + width/2.0;
}