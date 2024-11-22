#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <iostream>
#include "membro_clube.h"

using std::string;
using std:: cout;
using std:: endl;

class jogador : public virtual membro_clube { // Herança virtual

private:
    string posicao;      // Posição do jogador
    int gols_marcados;   // Número total de gols marcados

public:
    // Construtor padrão
    jogador();

    // construtor com parametros
    jogador(const string& nome, int idade, double salario, const string& posicao, int gols_feitos);

    // Destrutor virtual
    virtual ~jogador();

    // Getters
    string get_posicao() const; 
    int get_gols_marcados() const;

    // Setters
    void set_posicao(const string& nova_posicao);
    void set_gols_marcados(int novos_gols);

    //implementação do metodo calcular salario herdado de membo_clube
    double calcular_salario() const override; 

    // Sobrecarga do operador <
    bool operator<(const jogador& outro) const;
};

#endif // JOGADOR_H