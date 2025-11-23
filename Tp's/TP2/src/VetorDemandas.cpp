#include "VetorDemandas.hpp"

// Construtor: cria vetor com capacidade especificada
VetorDemandas::VetorDemandas(int capacidade)
: m_capacidade(capacidade), m_tamanho(0) {
    if (m_capacidade < 1) m_capacidade = 1;  // Garante capacidade mínima
    m_dados = new Demanda[m_capacidade];     // Aloca array de demandas
}

// Destrutor: libera memória do array
VetorDemandas::~VetorDemandas() {
    delete[] m_dados;
}

// Adiciona uma nova demanda ao vetor
bool VetorDemandas::adicionar(const Demanda &d) {
    if (m_tamanho >= m_capacidade) return false;  // Vetor cheio
    m_dados[m_tamanho++] = d;                     // Adiciona e incrementa tamanho
    return true;
}

// Métodos de acesso às demandas (versões constante e não-constante)
Demanda& VetorDemandas::obter(int i) { return m_dados[i]; }
const Demanda& VetorDemandas::obter(int i) const { return m_dados[i]; }

// Retorna informações sobre o vetor
int VetorDemandas::tamanho() const { return m_tamanho; }
int VetorDemandas::capacidade() const { return m_capacidade; }