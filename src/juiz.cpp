#include "juiz.h"

// Construtor padrão
juiz::juiz()
    : pessoa(), partidas_arbitradas(0) {}

// Construtor que inicializa os atributos
juiz::juiz(const std::string& nome, int idade, int partidas_arbitradas)
    : pessoa(nome, idade), partidas_arbitradas(partidas_arbitradas) {}

//Destrutor
juiz:: ~juiz(){}

// Getters
int juiz::get_partidas_arbitradas() const {
    return partidas_arbitradas;
}

// Setters
void juiz::set_partidas_arbitradas(int partidas) {
    if (partidas >= 0) {
        partidas_arbitradas = partidas;
    } else {
        cout << "O número de partidas arbitradas não pode ser negativo." << endl;
    }
}

// Método para incrementar o número de partidas arbitradas
void juiz::incrementar_partidas_arbitradas() {
    partidas_arbitradas++;
}

// Método para exibir informações
void juiz::exibir_informacoes() const {
    cout << "Nome: " << get_nome() << endl;
    cout << "Idade: " << get_idade() << endl;
    cout << "Partidas arbitradas: " << partidas_arbitradas << endl;
    cout <<"//////////////////////////////" << endl; 
}