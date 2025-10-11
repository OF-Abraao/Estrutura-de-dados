#include "cena.hpp"
#include <iomanip>
#include <cmath>

using namespace std;

// Construtor - inicializa contador de fragmentos como zero
Scene::Scene() : numFragments(0) {}

// Limpa a cena - remove todos os fragmentos
void Scene::clear() {
    numFragments = 0;
}

// Adiciona objeto à cena aplicando lógica de oclusão
// Retorna true se algum fragmento foi adicionado
bool Scene::addObject(const Object &obj) {
    double objStart = obj.start();
    double objEnd = obj.end();

    // Verifica se objeto é válido (tem comprimento positivo)
    if (objEnd <= objStart) return false;

    // Arrays para armazenar segmentos visíveis do objeto atual
    double segmentsStart[SCENE_MAX_SIZE];
    double segmentsEnd[SCENE_MAX_SIZE];
    int numSegments = 1;
    segmentsStart[0] = objStart;
    segmentsEnd[0] = objEnd;

    // Para cada fragmento existente na cena (oclusores)
    for (int i = 0; i < numFragments && numSegments > 0; ++i) {
        double occluderStart = fragments[i].start;
        double occluderEnd = fragments[i].end;
        
        double newStart[SCENE_MAX_SIZE];
        double newEnd[SCENE_MAX_SIZE];
        int numNew = 0;

        // Processa cada segmento contra o fragmento oclusor
        for (int j = 0; j < numSegments; ++j) {
            double segStart = segmentsStart[j];
            double segEnd = segmentsEnd[j];

            // Verifica se há sobreposição com o oclusor
            if (occluderEnd <= segStart || occluderStart >= segEnd) {
                // Sem sobreposição - mantém segmento intacto
                newStart[numNew] = segStart;
                newEnd[numNew] = segEnd;
                numNew++;
            } else {
                // Com sobreposição - recorta o segmento
                
                // Parte esquerda do oclusor (se existir)
                if (segStart < occluderStart) {
                    newStart[numNew] = segStart;
                    newEnd[numNew] = occluderStart;
                    numNew++;
                }
                
                // Parte direita do oclusor (se existir)
                if (segEnd > occluderEnd) {
                    newStart[numNew] = occluderEnd;
                    newEnd[numNew] = segEnd;
                    numNew++;
                }
            }
        }
        
        // Atualiza segmentos para próxima iteração
        numSegments = numNew;
        for (int k = 0; k < numSegments; ++k) {
            segmentsStart[k] = newStart[k];
            segmentsEnd[k] = newEnd[k];
        }
    }

    // Adiciona segmentos visíveis restantes à cena
    int added = 0;
    for (int k = 0; k < numSegments && numFragments < SCENE_MAX_SIZE; ++k) {
        if (segmentsEnd[k] > segmentsStart[k]) {
            fragments[numFragments].id = obj.id;
            fragments[numFragments].start = segmentsStart[k];
            fragments[numFragments].end = segmentsEnd[k];
            numFragments++;
            added++;
        }
    }
    
    return added > 0;
}

// Escreve a cena formatada no stream de saída
void Scene::writeScene(ostream &os, int time) const {
    if (numFragments == 0) return;

    // Cria cópia dos fragmentos para ordenação
    Fragment sorted[SCENE_MAX_SIZE];
    for (int i = 0; i < numFragments; i++) {
        sorted[i] = fragments[i];
    }

    // Ordenação por inserção (estável) - ordena por ID e depois por início
    for (int i = 1; i < numFragments; i++) {
        Fragment key = sorted[i];
        int j = i - 1;
        
        // Critério: ID crescente, depois início crescente
        while (j >= 0 && (sorted[j].id > key.id || 
               (sorted[j].id == key.id && sorted[j].start > key.start))) {
            sorted[j + 1] = sorted[j];
            j--;
        }
        sorted[j + 1] = key;
    }

    // Escreve fragmentos ordenados
    for (int i = 0; i < numFragments; i++) {
        os << "S " << time << " " << sorted[i].id << " ";
        
        // Formata início - verifica se é número inteiro
        double start = sorted[i].start;
        if (fabs(start - round(start)) < 1e-12) {
            os << static_cast<int>(round(start));
        } else {
            os << fixed << setprecision(2) << start;
        }
        
        os << " ";
        
        // Formata fim - verifica se é número inteiro
        double end = sorted[i].end;
        if (fabs(end - round(end)) < 1e-12) {
            os << static_cast<int>(round(end));
        } else {
            os << fixed << setprecision(2) << end;
        }
        
        os << '\n';
    }
}