#ifndef TIME_FUTEBOL_H
#define TIME_FUTEBOL_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "jogador.h"
#include "tecnico.h" // Incluindo o cabeçalho do técnico

using std::string;
using std::vector;
using std::shared_ptr;

class time_futebol {
private:
    string nome; // Nome do time
    shared_ptr<tecnico> tec; // Ponteiro para o técnico do time
    vector<std::unique_ptr<jogador>> jogadores; // Lista de jogadores
    int pontuacao; // Pontuação total do time

public:
    // Construtor que inicializa os atributos
    time_futebol();

    // Construtor que inicializa os atributos
    time_futebol(const string& nome_time, shared_ptr<tecnico> tec, int pontuacao);

    // Getters
    string get_nome() const;
    const tecnico* get_tecnico() const;
    const vector<std::unique_ptr<jogador>>& get_jogadores() const;
    int get_pontuacao() const;

    // Setters
    void set_nome(const string& novo_nome);
    void set_tecnico(shared_ptr<tecnico> tec);

    // Métodos
    void adicionar_jogador(std::unique_ptr<jogador> j);
    void registro_de_resultados(char resultado);
    void exibir_informacoes_time() const;

    // Sobrecarga do operador <
    bool operator<(const time_futebol& outro) const;

    ~time_futebol();
};

#endif // TIME_FUTEBOL_H
