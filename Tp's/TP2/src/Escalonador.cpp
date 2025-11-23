#include "Escalonador.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

// Função auxiliar para cálculo de distância euclidiana
static inline double euclid_s(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return std::sqrt(dx*dx + dy*dy);
}

// Construtor: inicializa o escalonador com parâmetros de configuração
Escalonador::Escalonador(int eta, double gama, double delta, double alfa, double beta, double lambda, VetorDemandas *demandas)
: m_eta(eta), m_gama(gama), m_delta(delta), m_alfa(alfa), m_beta(beta), m_lambda(lambda), m_demandas(demandas) {
    int n = (m_demandas ? m_demandas->tamanho() : 0);
    // Inicializa vetor que controla quais demandas já foram atribuídas a caronas
    m_atribuidas = new bool[n];
    for (int i = 0; i < n; ++i) m_atribuidas[i] = false;
}

// Destrutor: libera memória do vetor de controle de atribuições
Escalonador::~Escalonador() {
    delete[] m_atribuidas;
}

// Verifica se as origens e destinos de uma demanda são próximos às do grupo atual
bool Escalonador::origensEDestinosProximos(int *C, int csize, int j) const {
    for (int k = 0; k < csize; ++k) {
        int idx = C[k];
        // Verifica proximidade entre origens (dentro do raio alfa)
        if (euclid_s(m_demandas->obter(idx).obterOx(), m_demandas->obter(idx).obterOy(),
                    m_demandas->obter(j).obterOx(), m_demandas->obter(j).obterOy()) > m_alfa + 1e-9) return false;
        // Verifica proximidade entre destinos (dentro do raio beta)
        if (euclid_s(m_demandas->obter(idx).obterDx(), m_demandas->obter(idx).obterDy(),
                    m_demandas->obter(j).obterDx(), m_demandas->obter(j).obterDy()) > m_beta + 1e-9) return false;
    }
    return true;
}

// Algoritmo principal: gera grupos de caronas a partir das demandas
VetorCaronas* Escalonador::gerarCaronas() {
    int n = m_demandas->tamanho();
    VetorCaronas *V = new VetorCaronas(n);

    // Processa cada demanda não atribuída para formar caronas
    for (int i = 0; i < n; ++i) {
        if (m_atribuidas[i]) continue;  // Pula demandas já incluídas em caronas

        // Array temporário para armazenar índices das demandas da carona atual
        int *C = new int[m_eta > 0 ? m_eta : 1];
        int csize = 0;
        C[csize++] = i;  // Adiciona a demanda atual como primeira da carona
        m_atribuidas[i] = true;

        // Tenta adicionar mais demandas à mesma carona
        for (int j = i + 1; j < n && csize < m_eta; ++j) {
            if (m_atribuidas[j]) continue;  // Pula demandas já atribuídas
            // Verifica se a diferença de tempo não excede o limite delta
            if (m_demandas->obter(j).obterTempo() - m_demandas->obter(i).obterTempo() >= m_delta) break;

            // Verifica se origens e destinos são suficientemente próximos
            if (!origensEDestinosProximos(C, csize, j)) {
                break;  // Se não forem próximos, interrompe a busca
            }

            // Adiciona provisoriamente a demanda ao grupo
            C[csize++] = j;

            // Avalia a eficiência do grupo atual
            Carona tmp(csize);
            for (int p = 0; p < csize; ++p) tmp.adicionarIndice(C[p]);
            double distanciaRota = tmp.distanciaRotaTotal(*m_demandas);
            double somaODs = tmp.somaOD(*m_demandas);
            double eficiencia = 1.0;
            if (distanciaRota > 1e-12) eficiencia = somaODs / distanciaRota;

            // Verifica se a eficiência atende ao limite mínimo lambda
            if (eficiencia + 1e-12 < m_lambda) {
                // Eficiência insuficiente: remove última demanda e para
                csize--;
                break;
            } else {
                // Eficiência aceitável: confirma a inclusão da demanda
                m_atribuidas[j] = true;
            }
        }

        // Cria a carona definitiva com as demandas selecionadas
        Carona *car = new Carona(csize);
        for (int p = 0; p < csize; ++p) car->adicionarIndice(C[p]);
        V->adicionar(car);

        delete[] C;  // Libera array temporário
    }

    return V;
}

// Imprime informações detalhadas sobre as caronas geradas
void Escalonador::imprimirCaronas(const VetorCaronas &V) const {
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(2);
    
    // Para cada carona, imprime seus dados formatados
    for (int r = 0; r < V.tamanho(); ++r) {
        const Carona *car = V.obter(r);
        int c = car->obterQuantidade();
        if (c == 0) continue;  // Ignora caronas vazias
        
        // Calcula tempo de término e distância total
        double total = car->distanciaRotaTotal(*m_demandas);
        double inicio = m_demandas->obter( car->obterIndice(0) ).obterTempo();
        double termino = inicio + (total / m_gama);
        
        // Imprime cabeçalho da carona: término, distância, número de passageiros
        std::cout << std::fixed << std::setprecision(2) << termino << " " << total << " " << (2*c);
        
        // Imprime coordenadas de origem de todos os passageiros
        for (int p = 0; p < c; ++p) {
            const Demanda &d = m_demandas->obter( car->obterIndice(p) );
            std::cout << " " << std::fixed << std::setprecision(2) << d.obterOx() << " " << d.obterOy();
        }
        
        // Imprime coordenadas de destino de todos os passageiros
        for (int p = 0; p < c; ++p) {
            const Demanda &d = m_demandas->obter( car->obterIndice(p) );
            std::cout << " " << std::fixed << std::setprecision(2) << d.obterDx() << " " << d.obterDy();
        }
        std::cout << "\n";
    }
}
