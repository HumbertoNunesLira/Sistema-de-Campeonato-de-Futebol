#include "membro_clube.h"


    // Construtor padrão
    membro_clube::membro_clube() : pessoa(), salario(0.0) {}
    
    // Construtor com parâmetros
    membro_clube::membro_clube(const string& nome, int idade, double salario) : pessoa(nome, idade), salario(salario) {}
    
    // Destrutor
    membro_clube::~membro_clube(){};
    
    // Getter para salário
    double membro_clube:: get_salario() const{
        return salario;
    }

    // Setter para salário
    void membro_clube:: set_salario(double novo_salario){
        salario = novo_salario;
    }

    // Sobrecarga do operador <<
    ostream& operator<<(std::ostream& os, const membro_clube& membro){
    // Exibe diretamente os atributos do membro
    os << "Nome: " << membro.get_nome() << "\n";
    os << "Idade: " << membro.get_idade() << "\n";
    os << "Salário: " << membro.salario << "\n"; // Acessa o atributo salário diretamente
    return os; // Retorna o fluxo de saída
}
