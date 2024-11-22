#ifndef TECNICO_JOGADOR_H
#define TECNICO_JOGADOR_H

#include <iostream>
#include <string>
#include "jogador.h"
#include "tecnico.h"

using std::string;
using std::ostream;

class tecnico_jogador : public virtual jogador, public virtual tecnico {
private:
    double bonus_duplo_papel; // Bônus para o jogador que também é técnico

public:
    // Construtor padrão
    tecnico_jogador();

    // Construtor que inicializa os atributos
    tecnico_jogador(const string& nome, int idade, double salario, const string& posicao, int gols_feitos , int experiencia, double bonus);

    //Destrutor
    ~tecnico_jogador();

    // Getters
    double get_bonus_duplo_papel() const;

    // Setters
    void set_bonus_duplo_papel(double novo_bonus);

    // Método para calcular o salário
    double calcular_salario() const override;

    // Sobrecarga do operador <<
    friend ostream& operator<<(ostream& os, const tecnico_jogador& tj);
};

#endif // TECNICO_JOGADOR_H