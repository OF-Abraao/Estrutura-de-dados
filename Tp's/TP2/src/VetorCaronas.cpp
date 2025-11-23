#include "VetorCaronas.hpp"

// Construtor: cria vetor para armazenar ponteiros para caronas
VetorCaronas::VetorCaronas(int capacidade)
: m_capacidade(capacidade), m_tamanho(0) {
    if (m_capacidade < 1) m_capacidade = 1;
    m_dados = new Carona*[m_capacidade];  // Aloca array de ponteiros
    // Inicializa todos os ponteiros como nulos
    for (int i = 0; i < m_capacidade; ++i) m_dados[i] = nullptr;
}

// Destrutor: libera cada carona individualmente e depois o array
VetorCaronas::~VetorCaronas() {
    for (int i = 0; i < m_tamanho; ++i) delete m_dados[i];
    delete[] m_dados;
}

// Adiciona uma carona ao vetor
bool VetorCaronas::adicionar(Carona *c) {
    if (m_tamanho >= m_capacidade) return false;  // Vetor cheio
    m_dados[m_tamanho++] = c;                     // Armazena ponteiro e incrementa
    return true;
}

// Métodos de acesso às caronas
Carona* VetorCaronas::obter(int i) const { return m_dados[i]; }
int VetorCaronas::tamanho() const { return m_tamanho; }