#pragma once

#include "Demanda.hpp"

class VetorDemandas {
public:
    explicit VetorDemandas(int capacidade);
    ~VetorDemandas();

    // Adiciona uma nova demanda ao vetor
    bool adicionar(const Demanda &d);

    // Acesso às demandas (versões para leitura e escrita)
    Demanda& obter(int i);             // Referência modificável
    const Demanda& obter(int i) const; // Referência somente leitura

    // Informações sobre o vetor
    int tamanho() const;     // Número de elementos atualmente armazenados
    int capacidade() const;  // Número máximo de elementos suportados

private:
    Demanda *m_dados;     // Array dinâmico que armazena as demandas
    int m_capacidade;     // Tamanho máximo do array
    int m_tamanho;        // Número atual de elementos no array
};