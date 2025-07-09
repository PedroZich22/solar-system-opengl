# 🌌 Sistema Solar - OpenGL

Este projeto é destinado a matéria de Computação Gráfica 5º Semestre do IFSP Campus São Paulo, Bacharelado em Sistemas de Informação. Cujo os integrantes são:
- Pedro Barros Zich - SP3120236
- Jonas Sanjinez Lopes - SP3121976
- João Vitor Leal de Castro - SP3122972

O projeto apresenta uma visualização 3D do sistema solar usando OpenGL com C/C++. O objetivo foi criar uma representação interativa dos corpos celestes, incluindo o Sol, os planetas e os anéis de Saturno. O projeto demonstra as capacidades do OpenGL para simulações dinâmicas e visualmente ricas, permitindo que os usuários explorem órbitas planetárias.

## Funcionalidades

- **Visualização 3D**: Renderização dos corpos celestes.
- **Exploração Interativa**: Navegue pelo sistema solar e dê zoom.
- **Animação Dinâmica**: Simulação das órbitas e movimentos planetários.
- **Modelos Texturizados**: Texturas detalhadas para cada planeta e o Sol.
- **Interação do Usuário**: Controle das visualizações e animações com entradas do teclado e mouse.
- **Modo Noturno**: Altere o fundo e visualize um espaço com estrelas brilhantes.


## Getting Started

### Pré-requisitos

- CMake
- OpenGL
- Um compilador C++ (ex: GCC)

### Compilar e Executar

Para compilar e executar o sistema solar, siga as seguintes etapas:

```bash
cd build
cmake ..
cmake --build . && ../bin/main
```

### Compilar com G++


Para compilar e executar o sistema solar, siga as seguintes etapas:
Obs: Altere o caminho '/ProgramData/mingw64/mingw64/include' para onde está seu devido include do MinGW e '/ProgramData/mingw64/mingw64/lib'
```bash
cd src
g++ main.cpp input_handler.cpp texture_loader.cpp -o sistema.exe  -Iinclude -IC:/ProgramData/mingw64/mingw64/include  -LC:/ProgramData/mingw64/mingw64/lib -lfreeglut -lopengl32 -lglu32
```

## Controles

```sh
--------------------------------------  
🌌 Comandos da Simulação do Sistema Solar 🌌  
--------------------------------------  
❌ Sair: pressione 'ESC'  
🔄 Alternar órbitas: pressione 'O'  
🔍 Aproximar: use o 'Scroll Up' do mouse  
🔎 Afastar: use o 'Scroll Down' do mouse  
⏸️ Pausar animação: pressione 'P'  
🖱️ Mover câmera: segure o botão esquerdo do mouse e arraste  
🌙 Modo noturno: pressione 'N'
🌐 Ver todos os elementos: pressione 'A'  
🌍 Ver elemento individualmente:  
  0️⃣ SOL  
  1️⃣ MERCÚRIO  
  2️⃣ VÊNUS  
  3️⃣ TERRA  
  4️⃣ MARTE  
  5️⃣ JÚPITER  
  6️⃣ SATURNO  
  7️⃣ URANO  
  8️⃣ NETUNO  
--------------------------------------  
```
