#include <iostream>
#include <fstream>
#include <iomanip>
#include "Demanda.hpp"
#include "VetorDemandas.hpp"
#include "Escalonador.hpp"

int main(int argc, char** argv) {
    // Se o usuário passou um nome de arquivo, tentamos abrir esse arquivo.
    // Caso contrário (ou se a abertura falhar), continuamos lendo de stdin.
    std::istream* entrada = &std::cin;
    std::ifstream arquivo;
    if (argc >= 2) {
        arquivo.open(argv[1]);
        if (arquivo.is_open()) {
            entrada = &arquivo;
        }
        // Se não abriu, permanecemos usando stdin -- isso torna o programa
        // compatível tanto com "bin/tp2.out arquivo.txt" quanto com
        // "bin/tp2.out < arquivo.txt".
    }

    // Ler os parâmetros iniciais do mesmo fluxo de entrada (arquivo ou stdin).
    // A ordem dos itens no arquivo segue o enunciado: eta, gama, delta, alfa, beta, lambda, numDemandas.
    int eta;
    if (!(*entrada >> eta)) return 0;

    double gama, delta, alfa, beta, lambda;
    int numDemandas;
    *entrada >> gama >> delta >> alfa >> beta >> lambda >> numDemandas;

    // Alocamos o contêiner de demandas com a capacidade conhecida.
    VetorDemandas D(numDemandas);

    // Ler cada demanda do fluxo. A função Demanda::lerDeStream faz a leitura no formato requerido.
    for (int i = 0; i < numDemandas; ++i) {
        Demanda d;
        if (!Demanda::lerDeStream(*entrada, d)) return 0;
        D.adicionar(d);
    }

    // Escalonador aplica a heurística e gera as caronas.
    Escalonador escal(eta, gama, delta, alfa, beta, lambda, &D);
    VetorCaronas *caronas = escal.gerarCaronas();

    // Impressão da saída: fixa 2 casas decimais em todos os doubles.
    // Importante: não imprimir nada além do que o enunciado solicita.
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(2);
    escal.imprimirCaronas(*caronas);

    delete caronas;
    return 0;
}
