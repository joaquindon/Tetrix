<div id="header" align="center">
  <img src="https://media.giphy.com/media/M9gbBd9nbDrOTu1Mqx/giphy.gif" width="100"/>
</div>

<div id="badges" align="center">
  <a href="https://github.com/C10743-ArtaviaM">
    <img src="https://img.shields.io/badge/GitHub-000000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub Badge"/>
  </a>
</div>

<div align="center">
  <img src="https://media.giphy.com/media/dWesBcTLavkZuG35MI/giphy.gif" width="600" height="300"/>
</div>

---

<div align="center">
  <h1>
    <p>UNIVERSIDAD DE COSTA RICA</p>
    <p>FACULTAD DE INGENIERIA</p>
    <p>ESCUELA DE CIENCIAS DE LA COMPUTACION E INFORMATICA</p>
  </h1>
</div>

<div align="center">
  <h2>
    <p>CI-0119 P.I. de Arquitectura & Lenguaje Ensamblador</p>
    <p>I CICLO 2025</p>
  </h2>
</div>


<div align="center">
  <h3>
    <p>🎮 TETRIS 🎮</p>
  </h3>
  <h4>
    <p>NASM TESTS</p>
  </h4>
</div>

## 👨‍🏫 Proyecto Académico

Desarrollo de un videojuego tetris donde la logica se manejara en lenguaje ensamblador NASM como ejercicio de aplicación de conceptos de bajo nivel, acceso a memoria, control de flujo, lógica binaria y entrada/salida por teclado y video.

---

## 🧠 Descripción del Proyecto

**Tetris en NASM** es una versión simplificada y funcional del clásico juego **Tetris**, en este directorio, se llevan a cabo pruebas primordiales para asegurar un exito durante el juego final.  
Este proyecto debe reflejar un dominio aceptable del uso de registros, memoria segmentada, interrupciones y control de ciclo principal de un juego en bajo nivel con interfaz grafica en alto nivel.

---

## 🕹️ Características

-  Manejo de colisiones  
-  Manejo de rotaciones
-  Manejo de movimiento
-  Sumas de puntajes

---

## ⚙️ Tecnologías Utilizadas

- Lenguaje: `NASM (x86 Assembly)`
- Sistema operativo: `Ubuntu 22.04.5 LTS`
- Compilador: `nasm`
- Herramientas: `make`

---

## 🚀 Instrucciones de Compilación y Ejecución

```bash
# Compilar el proyecto
make

# Ejecutar usando make
make run
```

> ⚠️ Asegúrate de tener instalado NASM y Make y DOSBox.

---

## 📂 Estructura del Directorio

```
📁 NASM/
├── bin/
│   └── test              # Binario ejecutable
├── obj/
│   ├── collision.o       # Objeto compilado de collision.asm
│   ├── rotation.o        # Objeto compilado de rotation.asm
│   └── test.o            # Objeto compilado de test.cpp
├── src/
│   ├── collision.asm     # Codigo con logica de colisiones.
│   ├── rotation.asm      # Codigo con logica de rotaciones.
│   └── test.cpp          # Código de pruebas principal.
├── Makefile              # Script de compilación
└── README.md             # Este documento
```

---

## 🎮 Caracteristicas del Juego

1. Las piezas deberan caer desde la parte superior del área de juego.
2. El jugador debera poder moverlas lateralmente o rotarlas antes de que toquen el fondo.
3. Si una línea se llena completamente, se eliminara y se suma al puntaje x puntosS.
4. El juego finaliza cuando las piezas se apilan hasta el tope.
5. El ciclo principal se ejecutara constantemente en espera de entradas.

---

## 👨‍💻 Autores

- **Mauricio Artavia M.**  
  Estudiante de Ciencias de la Computacion e Informatica 
  Universidad de Costa Rica  
  [GitHub: C10743-ArtaviaM](https://github.com/C10743-ArtaviaM)

- **Joaquin Donzon A.**  
  Estudiante de Ciencias de la Computacion e Informatica 
  Universidad de Costa Rica  
  [GitHub: joaquindon](https://github.com/joaquindon)

---

## 📄 Licencia

Este proyecto fue desarrollado exclusivamente con fines **académicos**.  
**No está permitido su uso con fines comerciales.**

---

## 🔗 Recursos y Créditos

- [Repositorio de GitHub](https://github.com/joaquindon/Tetrix)
- [Guía de Instrucciones NASM](https://www.nasm.us/doc/)

### :hammer_and_wrench: Lenguajes y Herramientas :

---

<div>
  <img src="https://github.com/devicons/devicon/blob/master/icons/cplusplus/cplusplus-plain.svg" title="C++" alt="C++" width="40" height="40"/>&nbsp;
  <img src="https://github.com/joaquindon/Tetrix/blob/main/resources/icons/NASM.svg" title="NASM" alt="NASM" width="40" height="40"/>&nbsp;
</div>
