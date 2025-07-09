/**
 * @file input_handler.h
 * @brief Declara funções e variáveis relacionadas ao controle de entrada do usuário.
 *
 * Este arquivo define manipuladores de entrada como teclado, mouse, zoom e controle
 * da câmera para a navegação no Sistema Solar em OpenGL.
 */

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#pragma once

#include <GL/freeglut.h>

/**
 * @enum ZoomDirection
 * @brief Direções possíveis de zoom da câmera.
 *
 * Define se a câmera deve aproximar (In) ou afastar (Out).
 */
enum class ZoomDirection
{
  In,
  Out
};

/// Ângulo da câmera no eixo X (inclinação vertical).
extern float cameraAngleX;

/// Ângulo da câmera no eixo Y (rotação horizontal).
extern float cameraAngleY;

/// Última posição X do mouse (usado para calcular movimento).
extern int lastMouseX;

/// Última posição Y do mouse (usado para calcular movimento).
extern int lastMouseY;

/// Indica se o botão esquerdo do mouse está pressionado.
extern bool leftButtonPressed;

/// Mostra ou oculta as órbitas dos planetas.
extern bool showOrbits;

/// Mostra ou oculta o fundo estelar (starfield).
extern bool showStarfield;

/// Distância da câmera em relação à origem (zoom).
extern float cameraDistance;

/// Índice do elemento atualmente selecionado.
extern int selectedElement;

/// Indica se a simulação está pausada.
extern bool paused;

/**
 * @brief Manipula o movimento do mouse com botão pressionado.
 * @param x Posição atual X do mouse.
 * @param y Posição atual Y do mouse.
 */
void mouseMotion(int x, int y);

/**
 * @brief Manipula os eventos de clique do mouse.
 * @param button Botão clicado.
 * @param state Estado do botão (pressionado/solto).
 * @param x Posição X do clique.
 * @param y Posição Y do clique.
 */
void mouseButton(int button, int state, int x, int y);

/**
 * @brief Manipula o evento da rolagem do mouse (scroll).
 * @param button Botão do mouse (scroll).
 * @param dir Direção do scroll (1 para cima, -1 para baixo).
 * @param x Posição X do mouse.
 * @param y Posição Y do mouse.
 */
void mouseWheel(int button, int dir, int x, int y);

/**
 * @brief Realiza zoom com base na direção fornecida.
 * @param direction Direção do zoom (In ou Out).
 */
void zoom(ZoomDirection direction);

/**
 * @brief Manipula a entrada de teclas pressionadas.
 * @param key Tecla pressionada.
 * @param x Posição X do mouse no momento do evento.
 * @param y Posição Y do mouse no momento do evento.
 */
void keyPressed(unsigned char key, int x, int y);

#endif // INPUT_HANDLER_H
