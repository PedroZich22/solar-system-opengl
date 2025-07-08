
#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <cmath>

#include <GL/freeglut.h>

#include "../include/stb_image.h"
#include "../include/textures.h"
#include "../include/planet_radii.h"
#include "../include/orbit_radii.h"
#include "../include/planet_speeds.h"
#include "../include/texture_loader.h"
#include "../include/input_handler.h"

GLuint starsTextures[6], sunTexture, mercuryTexture, moonTexture, venusTexture, earthTexture, marsTexture, jupiterTexture, saturnTexture, saturnRingTexture, uranusTexture, neptuneTexture;
float rotationAngle = 0.0;

void init()
{
  glEnable(GL_TEXTURE_2D);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  GLfloat light_pos[] = {0.0f, 0.0f, 0.0f, 1.0f};
  GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

  starsTextures[0] = loadTexture(STARS_BACK_TEXTURE);
  starsTextures[1] = loadTexture(STARS_BACK_TEXTURE);
  starsTextures[2] = loadTexture(STARS_TOP_TEXTURE);
  starsTextures[3] = loadTexture(STARS_BOTTOM_TEXTURE);
  starsTextures[4] = loadTexture(STARS_BACK_TEXTURE);
  starsTextures[5] = loadTexture(STARS_BACK_TEXTURE);

  sunTexture = loadTexture(SUN_TEXTURE);
  mercuryTexture = loadTexture(MERCURY_TEXTURE);
  venusTexture = loadTexture(VENUS_TEXTURE);
  moonTexture = loadTexture(MOON_TEXTURE);
  earthTexture = loadTexture(EARTH_TEXTURE);
  marsTexture = loadTexture(MARS_TEXTURE);
  jupiterTexture = loadTexture(JUPITER_TEXTURE);
  saturnTexture = loadTexture(SATURN_TEXTURE);
  uranusTexture = loadTexture(URANUS_TEXTURE);
  neptuneTexture = loadTexture(NEPTUNE_TEXTURE);
  saturnRingTexture = loadTexture(SATURN_RING_TEXTURE);
};

void renderText(const char *text, float x, float y, float z, float s = 0.3) 
{
  glPushAttrib(GL_LIGHTING_BIT);
  glDisable(GL_LIGHTING);

  glColor3f(1.0f, 1.0f, 1.0f);
  float currY = y;
  for (const char *start = text; *start;) {
    const char *end = start;
    while (*end != '\n' && *end != '\0') {
      end++;
    }
    glRasterPos3f(x, currY, z);
    for (const char *c = start; c < end; ++c) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    if (*end == '\0') break;
    start = end + 1;
    currY -= s;
  }
  glPopAttrib();
};

void drawTexturedSphere(GLuint texture, float radius)
{
  glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
  GLUquadric *quad = gluNewQuadric();
  gluQuadricTexture(quad, GL_TRUE);
  glBindTexture(GL_TEXTURE_2D, texture);
  gluSphere(quad, radius, 36, 18);
  gluDeleteQuadric(quad);
};

void drawStarfield(float size) {
  glPushAttrib(GL_ENABLE_BIT);
  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);

  float hs = size / 2.0f;
  
  float vertices[6][4][3] = {
    {{ hs, -hs, -hs}, { hs, -hs,  hs}, { hs,  hs,  hs}, { hs,  hs, -hs}},
    {{-hs, -hs,  hs}, {-hs, -hs, -hs}, {-hs,  hs, -hs}, {-hs,  hs,  hs}},
    {{-hs,  hs, -hs}, { hs,  hs, -hs}, { hs,  hs,  hs}, {-hs,  hs,  hs}},
    {{-hs, -hs,  hs}, { hs, -hs,  hs}, { hs, -hs, -hs}, {-hs, -hs, -hs}},
    {{-hs, -hs,  hs}, { hs, -hs,  hs}, { hs,  hs,  hs}, {-hs,  hs,  hs}},
    {{ hs, -hs, -hs}, {-hs, -hs, -hs}, {-hs,  hs, -hs}, { hs,  hs, -hs}}
  };

  float texCoords[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

  glPushMatrix();
  
  for (int i = 0; i < 6; i++) {
    glBindTexture(GL_TEXTURE_2D, starsTextures[i]);
    glBegin(GL_QUADS);
    for (int j = 0; j < 4; j++) {
      glTexCoord2fv(texCoords[j]);
      glVertex3fv(vertices[i][j]);
    }
    glEnd();
  }
  
  glPopMatrix();
  glPopAttrib();
}

void drawOrbit(float radius)
{
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; ++i)
  {
    float theta = i * 3.14159f / 180.0f;
    glVertex3f(radius * cos(theta), 0.0f, radius * sin(theta));
  }
  glEnd();
};

void drawSun(bool withLighting)
{
  glPushMatrix();

  GLfloat emission[] = {1.5f, 1.2f, 0.5f, 1.0f};
  glMaterialfv(GL_FRONT, GL_EMISSION, emission);

  glRotatef(rotationAngle, 0.0, 1.0, 0.0);
  drawTexturedSphere(sunTexture, SUN_RADIUS);

  if (withLighting)
  {
    glPushAttrib(GL_ENABLE_BIT);

    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);

    GLUquadric *halo = gluNewQuadric();
    gluQuadricTexture(halo, GL_FALSE);

    float scales[10] = {1.2f, 1.4f, 1.6f, 1.85f, 2.1f, 2.4f, 2.8f, 3.3f, 3.8f, 4.5f};
    float alphas[10] = {0.35f, 0.30f, 0.25f, 0.20f, 0.16f, 0.12f, 0.08f, 0.05f, 0.03f, 0.015f};

    for (int i = 0; i < 10; i++)
    {
      glColor4f(1.0f, 0.80f - i * 0.04f, 0.4f - i * 0.035f, alphas[i]);
      gluSphere(halo, SUN_RADIUS * scales[i], 48, 24);
    }

    gluDeleteQuadric(halo);

    glDepthMask(GL_TRUE);

    glPopAttrib();
  }
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  GLfloat noEmission[] = {0.0f, 0.0f, 0.0f, 1.0f};
  glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
  glPopMatrix();
};

void drawSaturnRing(float innerRadius, float outerRadius)
{
  int numDisks = 25;
  GLUquadric *quad = gluNewQuadric();
  glBindTexture(GL_TEXTURE_2D, saturnTexture);
  gluQuadricTexture(quad, GL_TRUE);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  float radiusStep = (outerRadius - innerRadius) / numDisks;

  for (int i = 0; i < numDisks; ++i)
  {
    float offset = 0.0;
    if (i % 2 == 0)
    {
      offset = .5;
    }
    float currentInnerRadius = innerRadius + i * radiusStep + offset;
    float currentOuterRadius = currentInnerRadius + radiusStep;

    float alpha = (float)i / (float)(numDisks - 1);

    glColor4f(1.0f, 1.0f, 1.0f, alpha);

    glPushMatrix();
    glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
    gluDisk(quad, currentInnerRadius, currentOuterRadius, 64, 64);
    glPopMatrix();
  }

  glDisable(GL_BLEND);

  gluDeleteQuadric(quad);
};

void drawMoon(float earthAngle, float earthOrbitRadius, float moonOrbitRadius, float moonOrbitSpeed, float moonRadius)
{
  glPushMatrix();
  glRotatef(earthAngle, 0.0, 1.0, 0.0);
  glTranslatef(earthOrbitRadius, 0.0, 0.0);
  glRotatef(5.14f, 1.0, 0.0, 0.0);
  glRotatef(rotationAngle * moonOrbitSpeed, 0.0, 1.0, 0.0);
  glTranslatef(moonOrbitRadius, 0.0, 0.0);
  drawTexturedSphere(moonTexture, moonRadius);
  glPopMatrix();
}

void drawPlanet(GLuint texture, float orbitRadius, float orbitSpeed, float planetRadius, const char *name, bool hasRing = false, float innerRingRadius = 0.0f, float outerRingRadius = 0.0f)
{
  if (showOrbits)
  {
    drawOrbit(orbitRadius);
  }
  glPushMatrix();
  glRotatef(rotationAngle * orbitSpeed, 0.0, 1.0, 0.0);
  glTranslatef(orbitRadius, 0.0, 0.0);

  if (strcmp(name, "EARTH") == 0)
  {
    glPushMatrix();
    glRotatef(23.5f, 0.0f, 0.0f, 1.0f);
    glRotatef(rotationAngle * 1.0f, 0.0f, 1.0f, 0.0f);
    drawTexturedSphere(texture, planetRadius);
    glPopMatrix();
  }
  else
  {
    drawTexturedSphere(texture, planetRadius);
  }

  if (hasRing)
  {
    drawSaturnRing(innerRingRadius, outerRingRadius);
  }

  glPopMatrix();
};

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  gluLookAt(cameraDistance * cos(cameraAngleY) * sin(cameraAngleX),
            cameraDistance * sin(cameraAngleY),
            cameraDistance * cos(cameraAngleY) * cos(cameraAngleX),
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);

  if (showStarfield) drawStarfield(150.0); // AJUSTAR TAMANHO

  if (selectedElement == 0 || selectedElement == -1)  drawSun(false);

  switch (selectedElement)
  {
  case 0:
    drawSun(false);
    renderText(
      "SOL\n"
      "Massa: 1,989 x 10^30 kg\n"
      "Temperatura do nucleo: 5 milhoes de C (fusao nuclear)",
      0.0, SUN_RADIUS + 1.0, 0.0
    );
    break;
  case 1:
    drawPlanet(mercuryTexture, 0.0, MERCURY_SPEED, MERCURY_RADIUS, "MERCURY");
    renderText(
      "MERCURIO\n"
      "Massa: 3,285 x 10^23 kg\n"
      "Gravidade: 3,7 m/s^2",
      0.0, MERCURY_RADIUS + 1.0, 0.0
    );
    break;
  case 2:
    drawPlanet(venusTexture, 0.0, VENUS_SPEED, VENUS_RADIUS, "VENUS");
    renderText(
      "VENUS\n"
      "Massa: 4,867 x 10^24 kg\n"
      "Gravidade: 8,87 m/s^2",
      0.0, VENUS_RADIUS + 1.0, 0.0
    );
    break;
  case 3:
    drawPlanet(earthTexture, 0.0, EARTH_SPEED, EARTH_RADIUS, "EARTH");
    drawMoon(0.0f, 0.0f, MOON_ORBIT_RADIUS, MOON_SPEED, MOON_RADIUS);
    renderText(
      "TERRA\n"
      "Massa: 5,972 x 10^24 kg\n"
      "Gravidade: 9,81 m/s^2",
      0.0, EARTH_RADIUS + 1.0, 0.0
    );
    break;
  case 4:
    drawPlanet(marsTexture, 0.0, MARS_SPEED, MARS_RADIUS, "MARS");
    renderText(
      "MARTE\n"
      "Massa: 6,417 x 10^23 kg\n"
      "Gravidade: 3,71 m/s^2",
      0.0, MARS_RADIUS + 1.0, 0.0
    );
    break;
  case 5:
    drawPlanet(jupiterTexture, 0.0, JUPITER_SPEED, JUPITER_RADIUS, "JUPITER");
    renderText(
      "JUPITER\n"
      "Massa: 1,898 x 10^27 kg\n"
      "Gravidade: 24,79 m/s^2", 
      0.0, JUPITER_RADIUS + 1.0, 0.0
    );
    break;
  case 6:
    drawPlanet(saturnTexture, 0.0, SATURN_SPEED, SATURN_RADIUS, "SATURN", true, SATURN_RADIUS * 1.2f, SATURN_RADIUS * 2.0f);
    renderText(
      "SATURNO\n"
      "Massa: 5,683 x 10^26 kg\n"
      "Gravidade: 10,44 m/s^2", 
      0.0, SATURN_RADIUS + 1.0, 0.0
    );
    break;
  case 7:
    drawPlanet(uranusTexture, 0.0, URANUS_SPEED, URANUS_RADIUS, "URANUS");
    renderText(
      "URANO\n"
      "Massa: 8,681 x 10^25 kg\n"
      "Gravidade: 8,69 m/s^2", 
      0.0, URANUS_RADIUS + 1.0, 0.0
    );
    break;
  case 8:
    drawPlanet(neptuneTexture, 0.0, NEPTUNE_SPEED, NEPTUNE_RADIUS, "NEPTUNE");
    renderText(
      "NETUNO\n"
      "Massa: 1,024 x 10^26 kg\n"
      "Gravidade: 11,15 m/s^2", 
      0.0, NEPTUNE_RADIUS + 1.0, 0.0
    );
    break;
  default:
    drawSun(true);
    drawPlanet(mercuryTexture, MERCURY_ORBIT_RADIUS, MERCURY_SPEED, MERCURY_RADIUS, "MERCURY");
    drawPlanet(venusTexture, VENUS_ORBIT_RADIUS, VENUS_SPEED, VENUS_RADIUS, "VENUS");
    
    drawPlanet(earthTexture, EARTH_ORBIT_RADIUS, EARTH_SPEED, EARTH_RADIUS, "EARTH");
    drawMoon(rotationAngle * EARTH_SPEED, EARTH_ORBIT_RADIUS, MOON_ORBIT_RADIUS, MOON_SPEED, MOON_RADIUS);
    
    drawPlanet(marsTexture, MARS_ORBIT_RADIUS, MARS_SPEED, MARS_RADIUS, "MARS");
    drawPlanet(jupiterTexture, JUPITER_ORBIT_RADIUS, JUPITER_SPEED, JUPITER_RADIUS, "JUPITER");
    drawPlanet(saturnTexture, SATURN_ORBIT_RADIUS, SATURN_SPEED, SATURN_RADIUS, "SATURN", true, SATURN_RADIUS * 1.2f, SATURN_RADIUS * 2.0f);
    drawPlanet(uranusTexture, URANUS_ORBIT_RADIUS, URANUS_SPEED, URANUS_RADIUS, "URANUS");
    drawPlanet(neptuneTexture, NEPTUNE_ORBIT_RADIUS, NEPTUNE_SPEED, NEPTUNE_RADIUS, "NEPTUNE");
    break;
  }

  glutSwapBuffers();
};

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
};

void update(int value)
{
  if (!paused)
    rotationAngle += 0.5;

  glutPostRedisplay();
  glutTimerFunc(16, update, 0);
};

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1000, 800);
  glutInitWindowPosition(250, 100);
  glutCreateWindow("Solar System");

  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(16, update, 0); // 60 FPS

  glutKeyboardFunc(keyPressed);

  glutMotionFunc(mouseMotion);
  glutMouseFunc(mouseButton);
  glutMouseWheelFunc(mouseWheel);

  glutMainLoop();

  return 0;
};