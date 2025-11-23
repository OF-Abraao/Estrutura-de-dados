#pragma once

#include <iosfwd>

class Demanda {
public:
    Demanda(); // Construtor padrão
    Demanda(int id, double tempo, double ox, double oy, double dx, double dy); // Construtor completo
    ~Demanda();

    // Métodos para acessar os dados da demanda
    int obterId() const;           // Identificador único
    double obterTempo() const;     // Horário de partida solicitado
    double obterOx() const;        // Coordenada X da origem
    double obterOy() const;        // Coordenada Y da origem
    double obterDx() const;        // Coordenada X do destino
    double obterDy() const;        // Coordenada Y do destino

    // Calcula a distância em linha reta entre origem e destino
    double distanciaOD() const;

    // Lê os dados de uma demanda a partir de um fluxo de entrada
    static bool lerDeStream(std::istream &is, Demanda &out);

private:
    int m_id;           // Identificador único da demanda
    double m_tempo;     // Horário em que a viagem é solicitada
    double m_ox, m_oy;  // Coordenadas de origem (x, y)
    double m_dx, m_dy;  // Coordenadas de destino (x, y)
};