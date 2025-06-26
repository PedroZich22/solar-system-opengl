
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <GL/freeglut.h>

extern float cameraAngleX;
extern float cameraAngleY;
extern float cameraDistance;
extern bool showOrbits;
extern int selectedElement;
extern bool paused;

enum class ZoomDirection
{
  In,
  Out
};

void mouseMotion(int x, int y);
void mouseButton(int button, int state, int x, int y);
void mouseWheel(int button, int dir, int x, int y);
void keyPressed(unsigned char key, int x, int y);

#endif
