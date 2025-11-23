#pragma once

class VetorDemandas; // Declaração antecipada para evitar inclusão circular

class Carona {
public:
    explicit Carona(int capacidade);
    ~Carona();

    // Adiciona uma demanda à carona pelo seu índice
    bool adicionarIndice(int indiceDemanda);
    
    // Obtém informações sobre a carona
    int obterQuantidade() const;  // Número atual de passageiros
    int obterIndice(int i) const; // Índice da i-ésima demanda na carona

    // Cálculos que dependem dos dados reais das demandas
    double distanciaRotaTotal(const VetorDemandas &D) const; // Distância total percorrida
    double somaOD(const VetorDemandas &D) const; // Soma das distâncias individuais origem-destino

private:
    int *m_indices;      // Array com índices das demandas nesta carona
    int m_capacidade;    // Número máximo de passageiros
    int m_quantidade;    // Número atual de passageiros
};