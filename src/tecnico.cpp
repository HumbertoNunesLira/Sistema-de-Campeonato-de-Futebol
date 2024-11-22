#include "tecnico.h"

// Construtor que inicializa os atributos
tecnico::tecnico()
    : membro_clube(), experiencia(0){}

tecnico::tecnico(const string& nome, int idade, double salario, int experiencia)
    : membro_clube(nome, idade, salario), experiencia(experiencia){}

//Destrutor
tecnico:: ~tecnico(){}

// Getters
int tecnico::get_experiencia() const {
    return experiencia;
}

// Setters
void tecnico::set_experiencia(int nova_experiencia) {
    experiencia = nova_experiencia;
}

// Método para calcular o salário
double tecnico::calcular_salario() const {
    return get_salario() + (experiencia * 200); 
}