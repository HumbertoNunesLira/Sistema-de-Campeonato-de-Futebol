#include "pessoa.h"

// Construtor padrão
pessoa::pessoa() : nome("Desconhecido"), idade(0) {}

// Construtor parametrizado
pessoa::pessoa(const string& nome, int idade) : nome(nome), idade(idade) {}

// Destrutor
pessoa::~pessoa(){}

// Setter para idade
void pessoa::set_idade(int nova_idade) {
    idade = nova_idade;
}

// Setter para nome
void pessoa::set_nome(const string& novo_nome) {
    nome = novo_nome;
}

// Getter para idade
int pessoa::get_idade() const {
    return idade;
}

// Getter para nome
string pessoa::get_nome() const {
    return nome;
}

// Método virtual para exibir informações (definição genérica)
void pessoa:: exibir_informacoes() const {
    cout << "Nome: " << nome << ", Idade: " << idade << endl;
    cout << "\\\\\\\\\\\\\\\\\\"<< endl;
}

// Sobrecarga do operador de igualdade
bool pessoa::operator==(const pessoa& outro) const {
    return (this->nome == outro.nome && this->idade == outro.idade);
}