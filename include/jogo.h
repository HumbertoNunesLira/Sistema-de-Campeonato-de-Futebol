#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <string>
#include <memory>
#include "time_futebol.h"
#include "juiz.h"

using std::shared_ptr;

class jogo {
private:
    shared_ptr<time_futebol> time_casa; // Time jogando em casa
    shared_ptr<time_futebol> time_visitante; // Time visitante
    shared_ptr<juiz> juiz_principal; // Juiz responsável pela partida
    int gols_time_casa; // Gols marcados pelo time da casa
    int gols_time_visitante; // Gols marcados pelo time visitante

public:
    // Construtor que inicializa os atributos
    jogo(shared_ptr<time_futebol> casa, shared_ptr<time_futebol> visitante, shared_ptr<juiz> juiz);

    // Getters
    const time_futebol* get_time_casa() const;
    const time_futebol* get_time_visitante() const;
    const juiz* get_juiz_principal() const;
    int get_gols_time_casa() const;
    int get_gols_time_visitante() const;

    // Setters
    void set_time_casa(shared_ptr<time_futebol> casa);
    void set_time_visitante(shared_ptr<time_futebol> visitante);
    void set_juiz_principal(shared_ptr<juiz> juiz);

    // Método para registrar o resultado do jogo
    void registrar_resultado(int gols_casa, int gols_visitante);

    // Método para exibir as informações do jogo
    void exibir_informacoes() const;

    ~jogo();
};

#endif // JOGO_H