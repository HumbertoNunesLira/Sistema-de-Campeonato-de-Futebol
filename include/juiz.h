#ifndef JUIZ_H
#define JUIZ_H

#include <iostream>
#include <string>
#include "pessoa.h"

class juiz : public pessoa {
private:
    int partidas_arbitradas; // Número total de partidas arbitradas

public:
    // Construtor padrão
    juiz();

    // Construtor que inicializa os atributos
    juiz(const std::string& nome, int idade, int partidas_arbitradas);

    // Getters
    int get_partidas_arbitradas() const;

    // Setters
    void set_partidas_arbitradas(int partidas);

    // Método para incrementar o número de partidas arbitradas
    void incrementar_partidas_arbitradas();

    // Método para exibir informações
    void exibir_informacoes() const;
    ~juiz();
};

#endif // JUIZ_H