#include "jogador.h"

// Construtor PADRÃO
jogador::jogador()
    : membro_clube(), posicao("Nao informador"), gols_marcados(0) {}

//Construtor
jogador::jogador(const string& nome, int idade, double salario, const string& posicao, int gols_feitos)
    : membro_clube(nome, idade, salario), posicao(posicao), gols_marcados(gols_feitos) {}

//Destrutor
jogador:: ~jogador(){}

// Getters
string jogador::get_posicao() const {
    return posicao;
}

int jogador::get_gols_marcados() const {
    return gols_marcados;
}

// Setters
void jogador::set_posicao(const string& nova_posicao) {
    if (nova_posicao == "goleiro" || "zagueiro" || "meio-campo" || "atacante"){
        posicao = nova_posicao;
    }
}

void jogador::set_gols_marcados(int novos_gols) {
    if (novos_gols >= 0) {
        gols_marcados = novos_gols;
    } else {
        cout << "O número de gols não pode ser negativo." << endl;
    }
}

// Método implementado de membro_clube para calcular o salário
double jogador::calcular_salario() const {
    return get_salario() + (gols_marcados * 100); // Exemplo de cálculo
}

// Sobrecarga do operador <
bool jogador::operator<(const jogador& outro) const {
    return gols_marcados < outro.gols_marcados;
}
