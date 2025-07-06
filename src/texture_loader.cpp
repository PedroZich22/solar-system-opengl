#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"
#include "../include/texture_loader.h"

GLuint loadTexture(const char *filename)
{
  GLuint textureID;
  int width, height, nrChannels;

  unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);

  if (!data)
  {
    std::cerr << "Failed to load texture: " << filename << std::endl;
  }

  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  stbi_image_free(data);
  return textureID;
};
