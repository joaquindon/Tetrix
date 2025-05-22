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
    <p>Tetrix - Plan de Desarrollo</p>
  </h3>
  <h4>
    <p>🗺️ (TODO / Roadmap) 🗺️</p>
  </h4>
</div>

## 📌 Introducción

Este documento define las tareas pendientes, mejoras y correcciones que forman parte del desarrollo del proyecto **Tetrix en NASM**, en orden de prioridad y categorizadas por tipo de tarea.  
Cada tarea tiene un propósito específico y será evaluada conforme al ciclo de vida del desarrollo académico..

---

## Descripción General

Tetrix es un juego de puzzle basado en Tetris que consiste en manipular piezas geométricas para completar líneas horizontales y obtener puntos. El objetivo principal es implementar un juego funcional, estable y con una buena experiencia de usuario.

Este roadmap está organizado en tres categorías principales:

- **Features:** Nuevas funcionalidades que se agregarán.
- **Bugs:** Errores o fallos identificados que requieren solución.
- **Enhancements:** Mejoras o ajustes para optimizar el juego o su rendimiento.

---

| 🧪 Nombre                      | 📝 Descripción                                                                                                                                                | 🔥 Prioridad | 🔧 Tipo        | ✅ Estado        |
|-------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------|:------------:|----------------|:----------------:|
| Detección de colisiones       | Se corregirá el fallo crítico que permite a las piezas atravesar los bordes del tablero, lo que afecta la jugabilidad y provoca errores lógicos.            | 🔴           | 🐞 Bug         | ⬜ <!-- TODO: Corregir la detección de colisiones en los bordes laterales y superiores --> |
| Detección de rotaciones       | Se implementará la lógica para que las piezas puedan rotar correctamente dentro del tablero, respetando límites y sin solapamientos indebidos.               | 2            | ✨ Enhancement | ⬜ <!-- TODO: Implementar rotaciones con validación de colisiones -->                     |
| Detección de filas completas  | Se detectará y validará cuando una fila esté completamente ocupada, para eliminarla correctamente y actualizar el puntaje del jugador.                        | 🔴           | 🧩 Feature     | ⬜ <!-- TODO: Detectar filas completas y eliminarlas dinámicamente -->                    |
| Creación de piezas            | Se desarrollarán todas las piezas clásicas de Tetrix (I, O, T, S, Z, J, L) con sus características propias para usarlas en el juego.                         | 1            | 🧩 Feature     | ⬜ <!-- TODO: Crear estructuras en memoria para cada tipo de pieza -->                     |
| Menú Principal                | Se diseñará e implementará un menú interactivo inicial que permita al usuario iniciar partida, seleccionar niveles, y salir del juego.                       | 1            | 🧩 Feature     | ⬜ <!-- TODO: Diseñar menú en pantalla de inicio -->                                     |
| Registro de puntaje           | Se añadirá una funcionalidad para almacenar y mostrar el puntaje actual y el historial.                                                                       | 5            | 🧩 Feature     | ⬜ <!-- TODO: Mostrar y almacenar el puntaje del jugador -->                             |
| Adición de música             | Se integrará una pista musical de fondo para mejorar la experiencia del jugador durante la partida.                                                          | 5            | 🎵 Feature     | ⬜ <!-- TODO: Añadir soporte para reproducción de música de fondo -->                    |
| Asociación de NASM con C++    | Se unificarán las funcionalidades implementadas en NASM con la capa gráfica escrita en C++, para que trabajen coordinadamente y sin errores.                 | 2            | 🔗 Feature     | ⬜ <!-- TODO: Enlazar correctamente NASM con C++ (extern "C") -->                        |


---

## 🎯 Priorización

| Código   | Significado                                      |
|----------|--------------------------------------------------|
| 🔴 Rojo  | Alta prioridad / bloqueante                      |
| 1-5      | Escala Fibonacci: esfuerzo estimado + urgencia   |
| 🟢 Verde | Baja prioridad / mejora opcional                 |

La escala de Fibonacci reflejara la importancia y esfuerzo estimado para cada tarea. Mientras que el rojo representara las tareas totalmente criticas que deberan resolverse de inmediato para garantizar una funcionalidad basica.

---

## 🧪 Tipos de Tarea

| Icono  | Tipo         | Descripción                                                              |
|--------|--------------|--------------------------------------------------------------------------|
| 🐞     | Bug          | Errores críticos a solucionar                                            |
| ✨     | Enhancement  | Mejoras sobre características ya existentes                              |
| 🧩     | Feature      | Nuevas funcionalidades importantes para la jugabilidad                   |
| 🎵     | Feature      | Características estéticas o de ambientación                              |
| 🔗     | Feature      | Integración entre componentes (NASM y C++)                               |

---

## 🛠️ Cómo trabajamos

Al agregar nuevas tareas, reportar los bugs o sugerir las mejoras, editamos esta tabla siguiendo el formato ya establecido, logrando asi mantener la coherencia con las tareas existentes.

---

## 🏁 Estado Actual

Este roadmap refleja el estado de desarrollo al corte del **21 de Mayo del 2025**, sujeto a ajustes conforme se avanza con nuevas iteraciones o entregables del proyecto.

---

## 📝 Notas

- Las prioridades pueden cambiar según la evolución del proyecto y los hallazgos durante el desarrollo.
- Se recomienda revisar este documento periódicamente para actualizar estados y prioridades.

---

## 🙌 Créditos

Este proyecto fue desarrollado de manera colaborativa por:

- **Mauricio Artavia Monge** – Desarrollo en lenguaje ensamblador (ASM) y lógica de bajo nivel.
- **Joaquín Donzón Avendaño** – Desarrollo gráfico y diseño de la interfaz visual.

Ambos integrantes contribuyeron de forma equitativa y conjunta en todas las fases del proyecto, combinando sus habilidades para lograr un producto sólido y cohesivo.

---

<div align="center">

🔄 Documento actualizado periódicamente por  
**Mauricio Artavia** y **Joaquín Donzón**  
✏️ *CI-0119 - Arquitectura y Ensamblador*

</div>