#include "tecnico_jogador.h"

// Construtor padrão
tecnico_jogador::tecnico_jogador()
    : 
    jogador(), 
    tecnico(), // Passa o nome para a classe base técnico
    bonus_duplo_papel(0) {}

// Construtor que inicializa os atributos
tecnico_jogador::tecnico_jogador(const string& nome, int idade, double salario, const string& posicao, int gols_feitos, int experiencia, double bonus)
    : membro_clube(nome, idade, salario), // Chama o construtor da classe base membro_clube
      jogador(nome, idade, salario, posicao, gols_feitos), // Chama o construtor da classe jogador
      tecnico(nome, idade, salario, experiencia), // Chama o construtor da classe tecnico
      bonus_duplo_papel(bonus) {}

// Destrutor
tecnico_jogador:: ~tecnico_jogador(){}

// Getters
double tecnico_jogador::get_bonus_duplo_papel() const {
    return bonus_duplo_papel;
}

// Setters
void tecnico_jogador::set_bonus_duplo_papel(double novo_bonus) {
    bonus_duplo_papel = novo_bonus;
}

// Método para calcular o salário
double tecnico_jogador::calcular_salario() const {
    return jogador::calcular_salario() + tecnico::calcular_salario() + bonus_duplo_papel;
}

// Sobrecarga do operador <<
ostream& operator<<(ostream& os, const tecnico_jogador& tj) {
    os << "Nome: " << tj.jogador::get_nome() << "\n"; 
    os << "Idade: " << tj.jogador::get_idade() << "\n";
    os << "Posição: " << tj.get_posicao() << "\n";
    os << "Salário: " << tj.calcular_salario() << "\n";
    os << "Experiência: " << tj.get_experiencia() << " anos\n"; // Especifica a classe tecnico
    os << "Bônus por dupla função: " << tj.get_bonus_duplo_papel() << "\n";
    return os;
}