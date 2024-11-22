#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "time_futebol.h"
#include "jogo.h"

using std::string;
using std::vector;

class campeonato {
private:
    string nome_campeonato; // Nome do campeonato
    vector<std::shared_ptr<time_futebol>> times; // Lista de times no campeonato
    vector<std::unique_ptr<jogo>> jogos; // Lista de jogos no campeonato

public:
    // Construtor que inicializa os atributos
    campeonato(const string& nome);

    // Getters
    string get_nome() const;
    const vector<std::shared_ptr<time_futebol>>& get_times() const;
    time_futebol* get_time(int index);
    const vector<std::unique_ptr<jogo>>& get_jogos() const;

    // Setters
    void set_nome(const string& nome);

    // Métodos
    void adicionar_time(std::shared_ptr<time_futebol> t);
    void adicionar_jogo(std::unique_ptr<jogo> j);
    void exibir_classificacao() const;
    ~campeonato();
};

#endif // CAMPEONATO_H