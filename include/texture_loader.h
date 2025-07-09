/**
 * @file texture_loader.h
 * @brief Fornece funcionalidade de carregamento de texturas.
 *
 * Este arquivo declara funções e inclui as bibliotecas necessárias para carregar
 * texturas utilizando a biblioteca STB image e OpenGL.
 */

#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

/**
 * @def STB_IMAGE_IMPLEMENTATION
 * @brief Define a implementação da biblioteca STB image.
 *
 * Essa macro deve ser definida exatamente uma vez no projeto para incluir
 * a implementação das funções da biblioteca STB image.
 */

#include <GL/freeglut.h>
#include <iostream>

/**
 * @brief Carrega uma textura a partir de um arquivo.
 * @param filename Caminho para o arquivo de textura.
 * @return O ID da textura no OpenGL.
 *
 * Esta função carrega uma imagem do arquivo especificado e gera
 * um objeto de textura do OpenGL.
 */
GLuint loadTexture(const char *filename);

#endif // TEXTURE_LOADER_H
