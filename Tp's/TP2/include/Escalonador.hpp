#pragma once

#include "VetorDemandas.hpp"
#include "VetorCaronas.hpp"

class Escalonador {
public:
    // Construtor com todos os parâmetros da heurística
    Escalonador(int eta, double gama, double delta, double alfa, double beta, double lambda, VetorDemandas *demandas);
    ~Escalonador();

    // Executa o algoritmo de formação de caronas
    VetorCaronas* gerarCaronas();

    // Exibe as caronas no formato especificado (com 2 casas decimais)
    void imprimirCaronas(const VetorCaronas &V) const;

private:
    // Parâmetros da heurística
    int m_eta;      // Número máximo de passageiros por carona
    double m_gama;  // Velocidade do veículo
    double m_delta; // Janela de tempo máxima para agrupamento
    double m_alfa;  // Raio máximo entre origens
    double m_beta;  // Raio máximo entre destinos
    double m_lambda; // Eficiência mínima requerida

    VetorDemandas *m_demandas; // Lista de todas as demandas disponíveis
    bool *m_atribuidas;        // Controla quais demandas já foram alocadas

    // Verifica se uma nova demanda é compatível com um grupo existente
    bool origensEDestinosProximos(int *C, int csize, int j) const;
};