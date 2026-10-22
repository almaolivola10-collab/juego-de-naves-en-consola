/* 
   ============================================================================================
   Materia: Laboratorio de Programación (LPR) — 5° Año
   Institución: E.E.S.T. N°1" — Vicente López
   Archivo: src/main.cpp
   Actividad 8: Introducción a POO - Motor de Juego de Naves (Clases, Objetos y Constructores)
   Docente: Mansilla Muñoz York
   Estudiante: Alma Olivola
   ============================================================================================
*/


#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

const int ANCHO = 80;
const int ALTO = 25;

// ==================================================
// FUNCIONES DE CONSOLA
// ==================================================
void gotoxy(int x, int y) {
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicion;
    posicion.X = (SHORT)x;
    posicion.Y = (SHORT)y;
    SetConsoleCursorPosition(consola, posicion);
}

void ocultarCursor() {
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(consola, &cursor);
}

// ==================================================
// FUNCION EXTRA: REGISTRAR PRIMERA RESPUESTA
// Adaptacion de la idea del codigo JavaScript
// ==================================================
void registrarPrimeraRespuesta() {
    int opcion;
    string respuesta;

    system("cls");

    cout << "====================================\n";
    cout << "       MENU DE OPCIONES\n";
    cout << "====================================\n";
    cout << "1. Jugar\n";
    cout << "2. Ver instrucciones\n";
    cout << "3. Salir\n";
    cout << "Selecciona una opcion: ";

    cin >> opcion;

    switch (opcion) {
        case 1:
            respuesta = "Jugar";
            break;
        case 2:
            respuesta = "Ver instrucciones";
            break;
        case 3:
            respuesta = "Salir";
            break;
        default:
            respuesta = "Opcion no valida";
            break;
    }

    cout << "\nSu respuesta es: " << respuesta << endl;

    if (opcion == 2) {
        cout << "\nCONTROLES DEL JUEGO\n";
        cout << "W: mover hacia arriba\n";
        cout << "A: mover hacia la izquierda\n";
        cout << "S: mover hacia abajo\n";
        cout << "D: mover hacia la derecha\n";
        cout << "ESPACIO: disparar\n";
    }

    cout << "\nPresiona una tecla para continuar...";
    _getch();
}

// ==================================================
// CLASE NAVE
// ==================================================
class Nave {
private:
    int x, y;
    int vidas;

public:
    Nave(int _x, int _y, int _vidas) {
        x = _x;
        y = _y;
        vidas = _vidas;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getVidas() const {
        return vidas;
    }

    void reducirVida() {
        if (vidas > 0) {
            vidas--;
        }
    }

    void pintar() {
        gotoxy(x, y);
        cout << " ^ ";
        gotoxy(x, y + 1);
        cout << "(O)";
        gotoxy(x, y + 2);
        cout << "^^^^";
    }

    void borrar() {
        gotoxy(x, y);
        cout << "    ";
        gotoxy(x, y + 1);
        cout << "    ";
        gotoxy(x, y + 2);
        cout << "    ";
    }

    void mover(char tecla) {
        borrar();

        if (tecla == 'a' && x > 1) x--;
        if (tecla == 'd' && x < ANCHO - 6) x++;
        if (tecla == 'w' && y > 3) y--;
        if (tecla == 's' && y < ALTO - 4) y++;

        pintar();
    }
};

// ==================================================
// CLASE ASTEROIDE
// ==================================================
class Asteroide {
private:
    int x, y;

public:
    Asteroide(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void pintar() {
        gotoxy(x, y);
        cout << "O";
    }

    void borrar() {
        gotoxy(x, y);
        cout << " ";
    }

    void mover() {
        borrar();
        y++;

        if (y >= ALTO - 1) {
            y = 3;
            x = rand() % (ANCHO - 4) + 2;
        }

        pintar();
    }

    void reiniciar() {
        borrar();
        y = 3;
        x = rand() % (ANCHO - 4) + 2;
        pintar();
    }
};

// ==================================================
// CLASE BALA
// ==================================================
class Bala {
private:
    int x, y;

public:
    Bala(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void mover() {
        gotoxy(x, y);
        cout << " ";
        y--;

        if (y >= 3) {
            gotoxy(x, y);
            cout << "|";
        }
    }

    bool fueraDeRango() const {
        return y < 3;
    }
};

// ==================================================
// JUEGO PRINCIPAL
// ==================================================
void jugar(string nombrePiloto) {
    system("cls");
    ocultarCursor();

    bool gameOver = false;
    int puntaje = 0;
    int ciclos = 0;

    Nave jugador(35, 18, 3);

    vector<Asteroide*> asteroides;
    vector<Bala*> balas;

    for (int i = 0; i < 5; i++) {
        asteroides.push_back(
            new Asteroide(rand() % (ANCHO - 4) + 2,
                          rand() % 12 + 4)
        );
    }

    jugador.pintar();

    while (!gameOver) {
        ciclos++;

        gotoxy(2, 1);
        cout << "PILOTO: " << nombrePiloto << "                 ";

        gotoxy(2, 2);
        cout << "VIDAS: " << jugador.getVidas()
             << "   PUNTAJE: " << puntaje << "          ";

        if (_kbhit()) {
            char tecla = tolower(_getch());

            if (tecla == ' ') {
                balas.push_back(
                    new Bala(jugador.getX() + 2,
                             jugador.getY() - 1)
                );
            } else {
                jugador.mover(tecla);
            }

            if (tecla == 27) {
                gameOver = true;
            }
        }

        // Mover las balas
        for (int i = 0; i < (int)balas.size();) {
            balas[i]->mover();

            if (balas[i]->fueraDeRango()) {
                delete balas[i];
                balas.erase(balas.begin() + i);
            } else {
                i++;
            }
        }

        // Mover asteroides
        int velocidad = 8 - puntaje / 50;
        if (velocidad < 2) velocidad = 2;

        if (ciclos % velocidad == 0) {
            for (int i = 0; i < (int)asteroides.size(); i++) {
                asteroides[i]->mover();
            }
        }

        // Colisiones entre balas y asteroides
        for (int i = 0; i < (int)balas.size();) {
            bool impacto = false;

            for (int j = 0; j < (int)asteroides.size(); j++) {
                if (balas[i]->getX() == asteroides[j]->getX() &&
                    abs(balas[i]->getY() -
                        asteroides[j]->getY()) <= 1) {

                    asteroides[j]->reiniciar();
                    puntaje += 10;
                    impacto = true;
                    break;
                }
            }

            if (impacto) {
                gotoxy(balas[i]->getX(), balas[i]->getY());
                cout << " ";
                delete balas[i];
                balas.erase(balas.begin() + i);
            } else {
                i++;
            }
        }

        // Colisiones entre asteroides y nave
        for (int i = 0; i < (int)asteroides.size(); i++) {
            bool colisionX =
                asteroides[i]->getX() >= jugador.getX() &&
                asteroides[i]->getX() <= jugador.getX() + 4;

            bool colisionY =
                asteroides[i]->getY() >= jugador.getY() &&
                asteroides[i]->getY() <= jugador.getY() + 2;

            if (colisionX && colisionY) {
                jugador.borrar();
                jugador.reducirVida();
                asteroides[i]->reiniciar();
                jugador.pintar();

                if (jugador.getVidas() <= 0) {
                    gameOver = true;
                }
            }
        }

        Sleep(40);
    }

    system("cls");

    gotoxy(25, 8);
    cout << "FIN DEL JUEGO";

    gotoxy(25, 10);
    cout << "Piloto: " << nombrePiloto;

    gotoxy(25, 11);
    cout << "Puntaje final: " << puntaje;

    // Liberar memoria de los objetos creados con new
    for (int i = 0; i < (int)asteroides.size(); i++) {
        delete asteroides[i];
    }

    for (int i = 0; i < (int)balas.size(); i++) {
        delete balas[i];
    }

    gotoxy(20, 14);
    system("pause");
}

// ==================================================
// MAIN
// ==================================================
int main() {
    srand((unsigned int)time(NULL));

    string nombrePiloto;

    cout << "Ingresa tu nombre y apellido: ";
    getline(cin, nombrePiloto);

    if (nombrePiloto.empty()) {
        nombrePiloto = "Piloto";
    }

    int opcion = 0;

    do {
        registrarPrimeraRespuesta();

        system("cls");
        cout << "====================================\n";
        cout << "       COMBATE ESPACIAL\n";
        cout << "====================================\n";
        cout << "1. Jugar\n";
        cout << "2. Salir\n";
        cout << "Selecciona una opcion: ";

        cin >> opcion;

        if (opcion == 1) {
            jugar(nombrePiloto);
        } else if (opcion != 2) {
            cout << "Opcion no valida.\n";
            Sleep(1000);
        }

    } while (opcion != 2);

    system("cls");
    cout << "Gracias por jugar, " << nombrePiloto << "!\n";

    return 0;
}
