#pragma once
#include <string>

#ifdef _WIN32
  #ifdef CONDRAW_EXPORTS
    #define CONDRAW_API __declspec(dllexport)
  #else
    #define CONDRAW_API __declspec(dllimport)
  #endif
#else
  #define CONDRAW_API
#endif

namespace ConDraw {
    CONDRAW_API void limpiarPantalla();
    CONDRAW_API void moverCursor(int x, int y);
    CONDRAW_API void dibujarTexto(int x, int y, const std::string& texto);
    CONDRAW_API void dibujarLinea(int x1, int y1, int x2, int y2);
    CONDRAW_API void dibujarRectangulo(int x, int y, int ancho, int alto);
}
