#include "campeonato.h"

// Construtor que inicializa os atributos
campeonato::campeonato(const string& nome) : nome_campeonato(nome) {}

// Getters
string campeonato::get_nome() const {
    return nome_campeonato;
}

const vector<std::shared_ptr<time_futebol>>& campeonato::get_times() const {
    return times;
}

time_futebol* campeonato::get_time(int index) {
    if (index >= 0 && index < times.size()) {
        return times[index].get(); // Retorna o ponteiro para o time
    }
    return nullptr; // Retorna nullptr se o índice for inválido
}

const vector<std::unique_ptr<jogo>>& campeonato::get_jogos() const {
    return jogos;
}

// Setters
void campeonato::set_nome(const string& nome) {
    nome_campeonato = nome;
}

// Método para adicionar um time ao campeonato
void campeonato::adicionar_time(std::shared_ptr<time_futebol> t) {
    if (t) { // Verifica se o ponteiro não é nulo
        times.push_back(t); // Não é necessário usar std::move aqui
        std::cout << "Adicionado com sucesso" << std::endl;
    } else {
        std::cout << "Erro: Tentativa de adicionar um time nulo!" << std::endl;
    }
}

// Método para adicionar um jogo ao campeonato
void campeonato::adicionar_jogo(std::unique_ptr<jogo> j) {
    jogos.push_back(std::move(j));
}

// Método para exibir a classificação dos times
void campeonato::exibir_classificacao() const {
    vector<const time_futebol*> times_copy;

    for (const auto& time_ptr : times) {
        times_copy.push_back(time_ptr.get());
    }
    
    // Ordena os times pela pontuação (usando o operador <)
    std::sort(times_copy.begin(), times_copy.end(), [](const time_futebol* a, const time_futebol* b) {
        return a->get_pontuacao() > b->get_pontuacao(); // Ordena em ordem decrescente
    });

    std::cout << "Classificacao do Campeonato: " << nome_campeonato << std::endl;
    for (const auto& time : times_copy) {
        std::cout << time->get_nome() << " - Pontuacao: " << time->get_pontuacao() << std::endl;
    }
}

// Destrutor
campeonato::~campeonato() {}