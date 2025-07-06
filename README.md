# 🌌 Sistema Solar - OpenGL

Este projeto apresenta uma visualização 3D do sistema solar usando OpenGL com C/C++. O objetivo foi criar uma representação interativa dos corpos celestes, incluindo o Sol, os planetas e os anéis de Saturno. O projeto demonstra as capacidades do OpenGL para simulações dinâmicas e visualmente ricas, permitindo que os usuários explorem órbitas planetárias.

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
