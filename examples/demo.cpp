#include "../include/Consola.h"
#include <thread>
#include <chrono>

int main() {
    ConDraw::limpiarPantalla();
    ConDraw::dibujarTexto(10, 5, "Hola, ConDraw!");
    ConDraw::dibujarRectangulo(5, 3, 20, 6);

    std::this_thread::sleep_for(std::chrono::seconds(3));
}