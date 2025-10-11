#pragma once

// TAD Objeto - Representa um objeto na cena com posição e dimensões
class Object {
public:
    int id;           // Identificador único do objeto
    double x, y;      // Coordenadas do centro do objeto
    double width;     // Largura do objeto
    
    Object();
    Object(int id_, double x_, double y_, double width_);
    void move(double newX, double newY);  // Move o objeto para novas coordenadas
    double start() const;                 // Calcula o início do objeto no eixo X
    double end() const;                   // Calcula o fim do objeto no eixo X
};