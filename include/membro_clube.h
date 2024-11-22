#ifndef MEMBRO_CLUBE_H
#define MEMBRO_CLUBE_H

#include "pessoa.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class membro_clube : public pessoa {
private:
    double salario;

public:
    // Construtor padrão
    membro_clube();
    
    // Construtor com parâmetros
    membro_clube(const string& nome, int idade, double salario);
    
    // Destrutor
    ~membro_clube();
    
    // Getter para salário
    double get_salario() const;

    // Setter para salário
    void set_salario(double novo_salario);

    // Método puramente virtual
    virtual double calcular_salario() const = 0; 

    friend ostream& operator << (ostream& os, const membro_clube& membro);
};

#endif // MEMBRO_CLUBE_H