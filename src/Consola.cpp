#include "Consola.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace ConDraw {

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void moverCursor(int x, int y) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(hConsole, pos);
#else
    std::cout << "\033[" << y+1 << ";" << x+1 << "H";
#endif
}

void dibujarTexto(int x, int y, const std::string& texto) {
    moverCursor(x, y);
    std::cout << texto;
}

void dibujarLinea(int x1, int y1, int x2, int y2) {
    // Implementación simple horizontal/vertical
    if (x1 == x2) {
        for (int y = y1; y <= y2; ++y) {
            moverCursor(x1, y);
            std::cout << "|";
        }
    } else if (y1 == y2) {
        for (int x = x1; x <= x2; ++x) {
            moverCursor(x, y1);
            std::cout << "-";
        }
    }
}

void dibujarRectangulo(int x, int y, int ancho, int alto) {
    dibujarLinea(x, y, x + ancho - 1, y);
    dibujarLinea(x, y + alto - 1, x + ancho - 1, y + alto - 1);
    for (int i = 1; i < alto - 1; ++i) {
        moverCursor(x, y + i);
        std::cout << "|";
        moverCursor(x + ancho - 1, y + i);
        std::cout << "|";
    }
}
}