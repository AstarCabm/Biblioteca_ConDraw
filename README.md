# ConDraw

Biblioteca simple para dibujar en la consola en C++ (Windows/Linux/macOS).
Permite limpiar la pantalla, mover el cursor, dibujar texto, líneas y rectángulos.

---

## Estructura del proyecto

```
ConDraw/
├─ include/
│  └─ Consola.h      # Header principal
├─ src/
│  └─ Consola.cpp    # Implementación de la biblioteca
├─ examples/
│  └─ demo.cpp       # Ejemplo de uso
└─ README.md
```

---

## Funciones principales

```cpp
void limpiarPantalla();
void moverCursor(int x, int y);
void dibujarTexto(int x, int y, const std::string& texto);
void dibujarLinea(int x1, int y1, int x2, int y2);
void dibujarRectangulo(int x, int y, int ancho, int alto);
```

---

## Compilar la biblioteca como DLL (Windows)

1. Desde la carpeta raíz del proyecto (`ConDraw/`), compila la DLL:

```bash
g++ -Iinclude -DCONDRAW_EXPORTS -shared src/Consola.cpp -o ConDraw.dll
```

- `-Iinclude` → indica dónde están los headers.
- `-DCONDRAW_EXPORTS` → define la macro para exportar funciones.
- `-shared` → genera la DLL.

---

## Usar la DLL en otro proyecto

1. Copia los siguientes archivos en tu proyecto:

```
Consola.h
ConDraw.dll
```

2. Incluye el header en tu código:

```cpp
#include "Consola.h"

int main() {
    ConDraw::limpiarPantalla();
    ConDraw::dibujarTexto(10, 5, "Hola desde ConDraw.dll!");
    ConDraw::dibujarRectangulo(5, 3, 20, 6);
}
```

3. Compila tu proyecto enlazando la DLL:

```bash
g++ -Iinclude main.cpp -L. -lConDraw -o miJuego.exe
```

- `-L.` → indica la carpeta donde está la DLL.
- `-lConDraw` → enlaza con la biblioteca.

4. Ejecuta el `.exe` **en la misma carpeta que la DLL**, o agrega la DLL al PATH.

---

## Ejecutar ejemplo demo

```bash
g++ -Iinclude examples/demo.cpp -L. -lConDraw -o demo.exe
./demo.exe
```

---

## Notas

- En Linux/macOS la DLL se reemplaza por `.so` y no necesitas `__declspec`.
- Puedes añadir más funciones de dibujo, animaciones y utilidades de consola.
- Licencia: MIT (opcional, si quieres permitir que otros lo usen libremente).

