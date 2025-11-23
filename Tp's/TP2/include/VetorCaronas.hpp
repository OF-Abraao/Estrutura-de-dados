#pragma once

#include "Carona.hpp"

class VetorCaronas {
public:
    explicit VetorCaronas(int capacidade);
    ~VetorCaronas();

    // Adiciona uma carona ao vetor (o vetor assume a responsabilidade de liberar a memória)
    bool adicionar(Carona *c);
    
    // Acesso às caronas armazenadas
    Carona* obter(int i) const;
    
    // Informações sobre o vetor
    int tamanho() const; // Número de caronas atualmente armazenadas

private:
    Carona **m_dados;    // Array de ponteiros para caronas
    int m_capacidade;    // Número máximo de caronas suportadas
    int m_tamanho;       // Número atual de caronas no vetor
};