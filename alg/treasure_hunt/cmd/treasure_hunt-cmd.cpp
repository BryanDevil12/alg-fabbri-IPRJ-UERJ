/* R. Fabbri, 2024 */
#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include <vector>
#include "treasure_hunt.h"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    No* mundo = criar_mundo();
    No* jogador = mundo;
    int passos = 0;
    bool jogo_terminado = false;

    // Find the optimal path (gabarito)
    No* no_tesouro = encontrar_no_do_tesouro(mundo);
    std::vector<No*> caminho_otimo = encontrar_menor_caminho(mundo, no_tesouro);
    int passos_otimos = caminho_otimo.size() - 1;

    // --- Game Loop ---
    int ch;
    while (true) {
        clear();

        // --- Display Headers ---
        mvprintw(0, 0, "Bem-vindo ao Caça ao Tesouro! Use as setas para mover, 'q' para sair.");
        mvprintw(1, 0, "Objetivo: Encontre o tesouro com o mínimo de passos.");

        // --- Display Map and Status ---
        desenhar_mapa(jogador, mundo);
        mvprintw(15, 0, "Você está em: %s | Seus Passos: %d", jogador->nome, passos);

        // --- Win Condition Check ---
        if (jogador->tem_tesouro) {
            mvprintw(17, 0, "Você encontrou o tesouro em %d passos!", passos);
            if (passos == passos_otimos) {
                mvprintw(18, 0, "Avaliação: Excelente! (Caminho perfeito)");
            } else if (passos <= passos_otimos * 1.5) {
                mvprintw(18, 0, "Avaliação: Ótimo!");
            } else if (passos <= passos_otimos * 2) {
                mvprintw(18, 0, "Avaliação: Bom.");
            } else {
                mvprintw(18, 0, "Avaliação: Péssimo. Tente novamente para melhorar.");
            }

            // Display the optimal path at the end
            mvprintw(20, 0, "Gabarito (Menor Caminho): %d passos", passos_otimos);
            printw(" -> Partindo de %s: ", caminho_otimo[0]->nome);
            for (size_t i = 0; i < caminho_otimo.size() - 1; ++i) {
                printw("%s%s", obter_direcao(caminho_otimo[i], caminho_otimo[i+1]), (i < caminho_otimo.size() - 2) ? " -> " : "");
            }

            mvprintw(22, 0, "Pressione 'q' para sair.");
            jogo_terminado = true;
        }

        refresh();
        ch = getch();

        if (ch == 'q') {
            break;
        }

        // --- Player Movement ---
        if (!jogo_terminado) {
            No* proximo_no = jogador;
            if (ch == KEY_UP && jogador->cima) proximo_no = jogador->cima;
            else if (ch == KEY_DOWN && jogador->baixo) proximo_no = jogador->baixo;
            else if (ch == KEY_LEFT && jogador->esquerda) proximo_no = jogador->esquerda;
            else if (ch == KEY_RIGHT && jogador->direita) proximo_no = jogador->direita;

            if (proximo_no != jogador) {
                jogador = proximo_no;
                passos++;
            }
        }
    }

    endwin();
    destruir_mundo(mundo);
    return 0;
}
