
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#pragma once

#include <GL/freeglut.h>

// Enum para controle de zoom
enum class ZoomDirection
{
  In,
  Out
};

// Variáveis globais de controle da câmera e estado
extern float cameraAngleX;
extern float cameraAngleY;
extern int lastMouseX;
extern int lastMouseY;
extern bool leftButtonPressed;

extern bool showOrbits;
extern float cameraDistance;
extern int selectedElement;
extern bool paused;

// Manipuladores de entrada
void mouseMotion(int x, int y);
void mouseButton(int button, int state, int x, int y);
void mouseWheel(int button, int dir, int x, int y);
void zoom(ZoomDirection direction);
void keyPressed(unsigned char key, int x, int y);

#endif
