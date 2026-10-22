Juego de Naves en Consola

Descripción

Este proyecto consiste en un juego de naves espaciales desarrollado en C++ para ejecutarse en la consola. Fue realizado para la Actividad 8 de la materia Laboratorio de Programación (LPR), correspondiente a 5.º año.

El objetivo del juego es controlar una nave espacial, esquivar asteroides y disparar para conseguir puntos.

Objetivos del proyecto

* Aplicar los conceptos de Programación Orientada a Objetos (POO).
* Utilizar clases, atributos, métodos y constructores.
* Comprender el encapsulamiento mediante private y public.
* Practicar la organización y documentación de un proyecto.
* Utilizar Git y GitHub para registrar los cambios realizados.

Funcionalidades

* Movimiento de la nave mediante el teclado.
* Disparos utilizando la barra espaciadora.
* Asteroides que representan obstáculos.
* Sistema de vidas.
* Sistema de puntuación.
* Aumento progresivo de la dificultad.
* Menú principal con opciones para jugar, consultar las instrucciones y salir.

Tecnologías utilizadas

* Lenguaje: C++.
* Editor de código: Visual Studio Code.
* Compilador: g++ (MinGW).
* Control de versiones: Git.
* Repositorio remoto: GitHub y/o GitLab.

Controles del juego

Tecla	Acción
W	Mover hacia arriba
A	Mover hacia la izquierda
S	Mover hacia abajo
D	Mover hacia la derecha
Barra espaciadora	Disparar
ESC	Salir de la partida

Estructura del proyecto

Juego-de-naves-en-consola/
├── .gitattributes
├── .gitignore
├── LICENSE
├── README.md
├── CHANGELOG.md
├── docs/
│   └── manuales/
│       └── manual_usuario_v1.0.0.pdf
├── src/
│   └── main.cpp
└── capturas/
    └── combate_consola.png

Requisitos para ejecutar el programa

* Tener Windows.
* Tener instalado un compilador de C++ compatible, como g++.
* Contar con Visual Studio Code u otro editor de código.
* Disponer de una terminal para compilar y ejecutar el programa.

Compilación y ejecución

Desde la terminal, ingresar a la carpeta src:

cd src

Compilar el programa:

g++ main.cpp -o Juego-de-naves-en-consola.exe

Ejecutar el juego en PowerShell:

.\Juego-de-naves-en-consola.exe

Documentación

El proyecto incluye documentación complementaria:

* CHANGELOG.md: registro de los cambios realizados.
* LICENSE: licencia del proyecto.
* .gitignore: archivos que Git debe ignorar.
* .gitattributes: configuración del tratamiento de archivos por Git.
* Manual del usuario: instrucciones para utilizar el juego.

Autoría

Alma Olivola

Institución: E.E.S.T. N.º 1 — Vicente López
Materia: Laboratorio de Programación (LPR)
Curso: 5.º año
Actividad: 8 — Programación Orientada a Objetos en C++

Estado del proyecto

Proyecto escolar en desarrollo. La compilación, la ejecución y las funcionalidades deben verificarse antes de considerar finalizada la entrega.                    
