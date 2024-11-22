#ifndef TECNICO_H
#define TECNICO_H

#include <iostream>
#include <string>
#include "membro_clube.h"

using std::string;

class tecnico: public virtual membro_clube {
private:
    int experiencia;      // Anos de experiência

public:
    // Construtor que inicializa os atributos
    tecnico();

    //cosntrutor com parametros
    tecnico(const string& nome, int idade, double salario, int experiencia);
    
    // Destrutor virtual
    virtual ~tecnico();
    
    // Getters         
    int get_experiencia() const;     

    // Setters
    void set_experiencia(int nova_experiencia);

    // Método para calcular o salário
    double calcular_salario() const override; 
    
};

#endif // TECNICO_H
