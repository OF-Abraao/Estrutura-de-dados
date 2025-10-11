#pragma once

#include "objeto.hpp"
#include <iostream>

// Tamanho máximo da cena
const int SCENE_MAX_SIZE = 1000;

// Estrutura que representa um fragmento visível de um objeto
struct Fragment {
    int id;           // ID do objeto original
    double start;     // Posição inicial do fragmento no eixo X
    double end;       // Posição final do fragmento no eixo X
};

// TAD Cena - Gerencia os fragmentos visíveis dos objetos
class Scene {
private:
    Fragment fragments[SCENE_MAX_SIZE];  // Array de fragmentos visíveis
    int numFragments;                    // Número atual de fragmentos
    
public:
    Scene();
    void clear();                                       // Limpa a cena
    bool addObject(const Object &obj);                  // Adiciona objeto com oclusão
    void writeScene(std::ostream &os, int time) const; // Escreve cena formatada
};