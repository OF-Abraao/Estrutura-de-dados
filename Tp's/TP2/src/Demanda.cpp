#include "Demanda.hpp"
#include <cmath>
#include <iostream>

// Função auxiliar para calcular distância entre dois pontos
static inline double euclid(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return std::sqrt(dx*dx + dy*dy);
}

// Construtor padrão: inicializa uma demanda com valores zero
Demanda::Demanda()
: m_id(0), m_tempo(0.0), m_ox(0.0), m_oy(0.0), m_dx(0.0), m_dy(0.0) {}

// Construtor completo: cria uma demanda com todos os parâmetros
Demanda::Demanda(int id, double tempo, double ox, double oy, double dx, double dy)
: m_id(id), m_tempo(tempo), m_ox(ox), m_oy(oy), m_dx(dx), m_dy(dy) {}

// Destrutor
Demanda::~Demanda() {}

// Métodos de acesso aos atributos da demanda
int Demanda::obterId() const { return m_id; }
double Demanda::obterTempo() const { return m_tempo; }
double Demanda::obterOx() const { return m_ox; }
double Demanda::obterOy() const { return m_oy; }
double Demanda::obterDx() const { return m_dx; }
double Demanda::obterDy() const { return m_dy; }

// Calcula a distância direta entre origem e destino
double Demanda::distanciaOD() const {
    return euclid(m_ox, m_oy, m_dx, m_dy);
}

// Lê os dados de uma demanda a partir de um fluxo de entrada
bool Demanda::lerDeStream(std::istream &is, Demanda &out) {
    int id;
    double t, ox, oy, dx, dy;
    // Tenta ler os 6 valores esperados: id, tempo, origem(x,y), destino(x,y)
    if (!(is >> id >> t >> ox >> oy >> dx >> dy)) return false;
    out = Demanda(id, t, ox, oy, dx, dy);
    return true;
}