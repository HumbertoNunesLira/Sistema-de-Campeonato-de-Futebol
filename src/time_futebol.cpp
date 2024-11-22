#include "time_futebol.h"

// Construtor padrão
time_futebol::time_futebol()
    : nome("desconhecido"), tec(nullptr), pontuacao(0) {}

// Construtor que inicializa os atributos
time_futebol::time_futebol(const string& nome_time, shared_ptr<tecnico> tec, int pontuacao)
    : nome(nome_time), tec(std::move(tec)), pontuacao(pontuacao) {}

// Destrutor
time_futebol:: ~time_futebol(){}

// Getters
string time_futebol::get_nome() const {
    return nome;
}

const tecnico* time_futebol::get_tecnico() const {
    return tec.get();
}

const vector<std::unique_ptr<jogador>>& time_futebol::get_jogadores() const {
    return jogadores;
}

int time_futebol::get_pontuacao() const {
    return pontuacao;
}

// Setters
void time_futebol::set_nome(const string& novo_nome) {
    nome = novo_nome;
}

void time_futebol::set_tecnico(shared_ptr<tecnico> novo_tec) {
    tec = std::move(novo_tec);
}

// Método para adicionar um jogador ao time
void time_futebol::adicionar_jogador(std::unique_ptr<jogador> j) {
    jogadores.push_back(std::move(j));
}

void time_futebol::registro_de_resultados(char resultado) {
    switch (resultado) {
        case 'V': // Vitória
            pontuacao += 3;
            std::cout << "Vitoria registrada! " << pontuacao << std::endl;
            break;
        case 'E': // Empate
            pontuacao += 1;
            std::cout << "Empate registrado! " << pontuacao << std::endl;
            break;
        case 'D': // Derrota
            std::cout << "Derrota registrada. " << pontuacao << std::endl;
            break;
        default:
            std::cout << "Resultado inválido!" << std::endl;
            break;
    }
}

// Método para exibir as informações do time
void time_futebol::exibir_informacoes_time() const {
    std::cout << "Nome do Time: " << nome << std::endl;
        if (tec) {
            std::cout << "Tecnico: " << tec->get_nome()<< std::endl; 
        } else {
            std::cout << "Tecnico: Nenhum" << std::endl;
        }
        std::cout << "Jogadores: " << jogadores.size() << std::endl;
        for (const auto& jogador : jogadores) {
            std::cout << "- " << jogador->get_nome() << std::endl; 
        }
        std::cout << "Pontuacao Total: " << pontuacao << std::endl;
        std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<< std::endl;
    }
// Sobrecarga do operador <
bool time_futebol::operator<(const time_futebol& outro) const {
    return pontuacao < outro.pontuacao;
}