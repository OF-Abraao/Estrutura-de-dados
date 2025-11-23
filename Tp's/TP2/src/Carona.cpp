#include "Carona.hpp"
#include "VetorDemandas.hpp"
#include <cmath>

// Função auxiliar para calcular distância entre dois pontos no plano
static inline double euclid_local(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return std::sqrt(dx*dx + dy*dy);
}

// Construtor: cria uma carona com capacidade máxima de passageiros
Carona::Carona(int capacidade)
: m_capacidade(capacidade), m_quantidade(0) {
    // Garante que a capacidade seja pelo menos 1
    if (m_capacidade < 1) m_capacidade = 1;
    // Aloca espaço para armazenar os índices dos passageiros
    m_indices = new int[m_capacidade];
}

// Destrutor: libera a memória alocada para o array de índices
Carona::~Carona() {
    delete[] m_indices;
}

// Adiciona um novo passageiro à carona, se houver vaga disponível
bool Carona::adicionarIndice(int indiceDemanda) {
    // Verifica se ainda há lugares disponíveis
    if (m_quantidade >= m_capacidade) return false;
    // Adiciona o índice do passageiro e incrementa o contador
    m_indices[m_quantidade++] = indiceDemanda;
    return true;
}

// Retorna o número atual de passageiros na carona
int Carona::obterQuantidade() const { return m_quantidade; }

// Retorna o índice do i-ésimo passageiro na lista
int Carona::obterIndice(int i) const { return m_indices[i]; }

// Calcula a distância total percorrida na rota da carona
// A rota segue: origem do 1º -> origem do 2º -> ... -> destino do 1º -> destino do 2º -> ...
double Carona::distanciaRotaTotal(const VetorDemandas &D) const {
    // Se não há passageiros, distância é zero
    if (m_quantidade == 0) return 0.0;
    
    double total = 0.0;
    
    // Primeiro percurso: entre as origens dos passageiros
    double px = D.obter(m_indices[0]).obterOx();
    double py = D.obter(m_indices[0]).obterOy();
    
    // Calcula distâncias entre origens consecutivas
    for (int i = 1; i < m_quantidade; ++i) {
        double nx = D.obter(m_indices[i]).obterOx();
        double ny = D.obter(m_indices[i]).obterOy();
        total += euclid_local(px, py, nx, ny);
        px = nx; py = ny;  // Atualiza ponto atual
    }
    
    // Transição da última origem para o primeiro destino
    double fx = D.obter(m_indices[0]).obterDx();
    double fy = D.obter(m_indices[0]).obterDy();
    total += euclid_local(px, py, fx, fy);
    px = fx; py = fy;
    
    // Segundo percurso: entre os destinos dos passageiros
    for (int i = 1; i < m_quantidade; ++i) {
        double nx = D.obter(m_indices[i]).obterDx();
        double ny = D.obter(m_indices[i]).obterDy();
        total += euclid_local(px, py, nx, ny);
        px = nx; py = ny;  // Atualiza ponto atual
    }
    
    return total;
}

// Calcula a soma das distâncias diretas de cada passageiro (origem->destino)
double Carona::somaOD(const VetorDemandas &D) const {
    double s = 0.0;
    // Para cada passageiro, adiciona sua distância origem-destino
    for (int i = 0; i < m_quantidade; ++i) {
        s += D.obter(m_indices[i]).distanciaOD();
    }
    return s;
}