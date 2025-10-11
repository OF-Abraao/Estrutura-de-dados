#include <iostream>
#include <string>
#include <sstream>
#include "objeto.hpp"
#include "cena.hpp"
#include "mergesort.hpp"

using namespace std;

// Função de comparação para ordenar objetos por Y crescente (mais distantes primeiro)
bool compareObjectsByY(const Object &a, const Object &b) {
    return a.y < b.y;
}

// Encontra o índice de um objeto no array pelo ID
int findIndexById(Object objects[], int n, int id) {
    for (int i = 0; i < n; ++i) {
        if (objects[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Adiciona novo objeto ou atualiza se já existir
void addOrUpdate(Object objects[], int &n, int id, double x, double y, double width) {
    int idx = findIndexById(objects, n, id);
    if (idx >= 0) {
        // Atualiza objeto existente
        objects[idx].x = x;
        objects[idx].y = y;
        objects[idx].width = width;
        return;
    }
    if (n < SCENE_MAX_SIZE) {
        // Adiciona novo objeto
        objects[n] = Object(id, x, y, width);
        ++n;
        return;
    }
}

// Move objeto para novas coordenadas
void moveObject(Object objects[], int n, int id, double x, double y) {
    int idx = findIndexById(objects, n, id);
    if (idx >= 0) {
        objects[idx].move(x, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Object objects[SCENE_MAX_SIZE];
    int numObjects = 0;
    string line;
    
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        char command;
        ss >> command;
        
        if (command == '0' || command == 'O') {
            // Comando para adicionar/atualizar objeto
            int id;
            double x, y, width;
            if (ss >> id >> x >> y >> width) {
                addOrUpdate(objects, numObjects, id, x, y, width);
            }
        } else if (command == 'M') {
            // Comando para mover objeto
            int time, id;
            double x, y;
            if (ss >> time >> id >> x >> y) {
                moveObject(objects, numObjects, id, x, y);
            }
        } else if (command == 'C') {
            // Comando para gerar cena
            int time;
            if (ss >> time && numObjects > 0) {
                // Ordena objetos por Y crescente (mais distantes primeiro)
                mergesort(objects, numObjects, compareObjectsByY);
                
                Scene scene;
                // Processa do mais distante para o mais próximo
                for (int i = 0; i < numObjects; i++) {
                    scene.addObject(objects[i]);
                }
                scene.writeScene(cout, time);
            }
        }
    }
    
    return 0;
}