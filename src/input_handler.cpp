
#include "../include/input_handler.h"

float cameraAngleX = 0.0;
float cameraAngleY = 0.0;
int lastMouseX = 0;
int lastMouseY = 0;
bool leftButtonPressed = false;

bool showOrbits = false;
float cameraDistance = 50.0;
int selectedElement = -1;
bool paused = false;

void mouseMotion(int x, int y)
{
  if (leftButtonPressed)
  {
    int dx = x - lastMouseX;
    int dy = y - lastMouseY;

    cameraAngleX += dx * 0.005;
    cameraAngleY += dy * 0.005;

    if (cameraAngleY > 1.5)
      cameraAngleY = 1.5;
    if (cameraAngleY < -1.5)
      cameraAngleY = -1.5;

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
  }
}

void mouseButton(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
  {
    if (state == GLUT_DOWN)
    {
      leftButtonPressed = true;
      lastMouseX = x;
      lastMouseY = y;
    }
    else
    {
      leftButtonPressed = false;
    }
  }
}

void zoom(ZoomDirection direction)
{
  cameraDistance += (direction == ZoomDirection::In) ? -1.0f : 1.0f;

  if (cameraDistance < 5.0f)
    cameraDistance = 5.0f;
  if (cameraDistance > 100.0f)
    cameraDistance = 100.0f;

  glutPostRedisplay();
}

void mouseWheel(int button, int dir, int x, int y)
{
  if (dir > 0)
    zoom(ZoomDirection::In);
  else
    zoom(ZoomDirection::Out);
}

void keyPressed(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27: // ESC key
    exit(0);
    break;
  case 'O':
  case 'o':
    showOrbits = !showOrbits;
    break;
  case '0':
    cameraDistance = 10;
    selectedElement = 0;
    break;
  case '1':
    cameraDistance = 10;
    selectedElement = 1;
    break;
  case '2':
    cameraDistance = 10;
    selectedElement = 2;
    break;
  case '3':
    cameraDistance = 10;
    selectedElement = 3;
    break;
  case '4':
    cameraDistance = 10;
    selectedElement = 4;
    break;
  case '5':
    cameraDistance = 10;
    selectedElement = 5;
    break;
  case '6':
    cameraDistance = 10;
    selectedElement = 6;
    break;
  case '7':
    cameraDistance = 10;
    selectedElement = 7;
    break;
  case '8':
    cameraDistance = 10;
    selectedElement = 8;
    break;
  case 'a':
  case 'A':
    selectedElement = -1;
    break;
  case 'p':
  case 'P':
    paused = !paused;
    break;
  default:
    break;
  }
};
