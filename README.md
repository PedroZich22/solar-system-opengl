# 🌌 Solar System - OpenGL

This project showcases a 3D visualization of the solar system using OpenGL with C/C++. The goal was to create an interactive representation of celestial bodies, including the Sun, planets, and Saturn's rings. The project demonstrates OpenGL’s capabilities for dynamic and visually rich simulations, allowing users to explore planetary orbits and characteristics.

## Features

- **3D Visualization**: Rendering of celestial bodies.
- **Interactive Exploration**: Navigate the solar system and zoom in/out.
- **Dynamic Animation**: Planetary orbits and movement simulation.
- **Textured Models**: Detailed textures for each planet and the Sun.
- **User Interaction**: Control views and animations with keyboard and mouse inputs.

## Getting Started

### Prerequisites

- CMake
- OpenGL
- A C++ compiler (e.g., GCC, Clang)

### Build and Run

To build and run the simulation, follow these steps:

```bash
cd build
cmake ..
cmake --build . && ../bin/main
```

## Controls

```sh
--------------------------------------
🌌 Solar System Simulation Commands 🌌
--------------------------------------
❌ Quit: press 'ESC'
🔄 Toggle orbits: press 'O'
🔍 Zoom in: press 'Up Scroll Wheel'
🔎 Zoom out: press 'Down Scroll Wheel'
⏸️ Pause animation: press 'P'
🖱️ Move camera: press and hold the left mouse button and drag
🌐 View all elements: press 'A'
🌍 View individual element:
  0️⃣ SUN
  1️⃣ MERCURY
  2️⃣ VENUS
  3️⃣ EARTH
  4️⃣ MARS
  5️⃣ JUPITER
  6️⃣ SATURN
  7️⃣ URANUS
  8️⃣ NEPTUNE
--------------------------------------
```
