#include "jogo.h"

// Construtor que inicializa os atributos
jogo::jogo(shared_ptr<time_futebol> casa, shared_ptr<time_futebol> visitante, shared_ptr<juiz> juiz)
    : time_casa(std::move(casa)), time_visitante(std::move(visitante)), juiz_principal(std::move(juiz)),
      gols_time_casa(0), gols_time_visitante(0) {}

//Destrutor
jogo:: ~jogo(){}

// Getters
const time_futebol* jogo::get_time_casa() const {
    return time_casa.get();
}

const time_futebol* jogo::get_time_visitante() const {
    return time_visitante.get();
}

const juiz* jogo::get_juiz_principal() const {
    return juiz_principal.get();
}

int jogo::get_gols_time_casa() const {
    return gols_time_casa;
}

int jogo::get_gols_time_visitante() const {
    return gols_time_visitante;
}

// Setters
void jogo::set_time_casa(shared_ptr<time_futebol> casa) {
    time_casa = std::move(casa);
}

void jogo::set_time_visitante(shared_ptr<time_futebol> visitante) {
    time_visitante = std::move(visitante);
}

void jogo::set_juiz_principal(shared_ptr<juiz> juiz) {
    juiz_principal = std::move(juiz);
}

// Método para registrar o resultado do jogo
void jogo::registrar_resultado(int gols_casa, int gols_visitante) {
    gols_time_casa = gols_casa;
    gols_time_visitante = gols_visitante;
    // Atualiza a pontuação dos times envolvidos
    if (gols_time_casa > gols_time_visitante) {
        time_casa->registro_de_resultados('V'); // Vitória para o time da casa
        time_visitante->registro_de_resultados('D'); // Derrota para o time visitante
        std::cout << "Registrado com sucesso" << std::endl;
        
    } else if (gols_time_casa < gols_time_visitante) {
        time_casa->registro_de_resultados('D'); // Derrota para o time da casa
        time_visitante->registro_de_resultados('V'); // Vitória para o time visitante
        
    } else {
        time_casa->registro_de_resultados('E'); // Empate para o time da casa
        time_visitante->registro_de_resultados('E'); // Empate para o time visitante
    }

}

// Método para exibir as informações do jogo
void jogo::exibir_informacoes() const {
    std::cout << "Jogo: " << time_casa->get_nome() << " vs " << time_visitante->get_nome() << std::endl;
    std::cout << "Juiz: " << juiz_principal->get_nome() << std::endl; 
    std::cout << "Resultado: " << gols_time_casa << " x " << gols_time_visitante << std::endl;
}