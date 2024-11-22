#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using std:: string;
using std:: cout;
using std:: endl;

class pessoa {
private:
    string nome;
    int idade;

public:
    // Construtor padrão
    pessoa();
    
    // Construtor com parâmetros
    pessoa(const string& nome, int idade);
    
    // Destrutor
    ~pessoa();
    
    // Sobrecarga do operador ==
    bool operator==(const pessoa& outro) const;

    // Getters
    string get_nome() const;
    int get_idade() const;

    // Setters
    void set_nome(const std::string& novo_nome);
    void set_idade(int nova_idade);

    // Método para exibir as informações da pessoa
    virtual void exibir_informacoes() const;
};

#endif // PESSOA_H