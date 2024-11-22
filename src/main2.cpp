#include <memory>
#include <vector>
#include <algorithm>
#include "campeonato.h"      // Incluir o cabeçalho da classe campeonato
#include "time_futebol.h"   // Incluir o cabeçalho da classe time_futebol
#include "tecnico.h"        // Incluir o cabeçalho da classe tecnico
#include "jogador.h"        // Incluir o cabeçalho da classe jogador
#include "tecnico_jogador.h" // Incluir o cabeçalho da classe tecnico_jogador
#include "juiz.h"          // Incluir o cabeçalho da classe juiz

using std::cout;
using std::endl;
using std::string;

int main() {
    auto juiz1 = std::make_unique<juiz>("Juiz1", 25, 10);
    juiz1->exibir_informacoes();

    auto jogador1 = std::make_unique<jogador>("Jogador 1", 25, 25000, "atacante", 10);
    auto jogador2 = std::make_unique<jogador>("Jogador 2", 30, 100000, "meio-campo", 5);

    jogador1->exibir_informacoes();
    jogador2->exibir_informacoes();

    auto tecnico1 = std::make_shared<tecnico>("tecnico1", 25, 25000, 10); // Usando shared_ptr
    auto supremo = std::make_shared<tecnico_jogador>("supremo", 25, 25000, "atacante", 10, 20, 2000); // Usando shared_ptr
    
    tecnico1->exibir_informacoes();
    supremo->exibir_informacoes();

    auto time1 = std::make_shared<time_futebol>("Flamengo", tecnico1, 0); // Usando make_shared
    auto time2 = std::make_shared<time_futebol>("Vasco", supremo, 0); // Usando make_shared

    time1->adicionar_jogador(std::move(jogador1));
    time2 ->adicionar_jogador(std::move(jogador2));

    time1->exibir_informacoes_time();
    time2->exibir_informacoes_time();

    // Primeiro, adiciona os times ao campeonato
    auto carioca = std::make_unique<campeonato>("Carioca");
    carioca->adicionar_time(time1);
    carioca->adicionar_time(time2);

    // Agora, cria o jogo
    auto jogo1 = std::make_unique<jogo>(time1, time2, std::move(juiz1)); // Move juiz1

    jogo1->registrar_resultado(2, 0);
    jogo1->exibir_informacoes();

    carioca->exibir_classificacao();

    return 0;
}

