/* R. Fabbri, 2024 */
#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "treasure_hunt.h"

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    No* mundo = criar_mundo();
    No* jogador = mundo;
    bool jogo_terminado = false;

    // Game loop
    int ch;
    while (true) {
        clear(); // Clear the screen

        // Draw map and status
        mvprintw(0, 0, "Bem-vindo ao Caça ao Tesouro! Use as setas para mover, 'q' para sair.");
        mvprintw(1, 0, "Seu objetivo é encontrar o tesouro escondido.");
        desenhar_mapa(jogador, mundo);
        mvprintw(10, 0, "Você está em: %s", jogador->nome);

        // Check for treasure
        if (jogador->tem_tesouro) {
            mvprintw(11, 0, "Você encontrou o tesouro! Parabéns!");
            mvprintw(12, 0, "Pressione 'q' para sair.");
            jogo_terminado = true;
        }

        refresh(); // Update the screen

        ch = getch(); // Wait for user input

        if (ch == 'q') {
            break;
        }

        if (!jogo_terminado) {
            if (ch == KEY_UP) {
                if (jogador->cima) {
                    jogador = jogador->cima;
                }
            } else if (ch == KEY_DOWN) {
                if (jogador->baixo) {
                    jogador = jogador->baixo;
                }
            } else if (ch == KEY_LEFT) {
                if (jogador->esquerda) {
                    jogador = jogador->esquerda;
                }
            } else if (ch == KEY_RIGHT) {
                if (jogador->direita) {
                    jogador = jogador->direita;
                }
            }
        }
    }

    // End ncurses mode
    endwin();

    destruir_mundo(mundo);
    return 0;
}
