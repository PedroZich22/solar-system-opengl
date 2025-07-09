/**
 * @file planet_speeds.h
 * @brief Define as velocidades dos planetas.
 *
 * Este arquivo contém constantes que representam as velocidades de vários planetas.
 * As velocidades são usadas para controlar a taxa de movimento ou translação dos planetas.
 */

#ifndef PLANET_SPEEDS_H
#define PLANET_SPEEDS_H

/**
 * @var MERCURY_SPEED
 * @brief Velocidade de Mercúrio.
 *
 * A velocidade com que Mercúrio se move ou orbita, representada como um float.
 */
const float MERCURY_SPEED = 4.0;

/**
 * @var VENUS_SPEED
 * @brief Velocidade de Vênus.
 *
 * A velocidade com que Vênus se move ou orbita, representada como um float.
 */
const float VENUS_SPEED = 3.0;

/**
 * @var EARTH_SPEED
 * @brief Velocidade da Terra.
 *
 * A velocidade com que a Terra se move ou orbita, representada como um float.
 */
const float EARTH_SPEED = 2.0;

/**
 * @var MOON_SPEED
 * @brief Velocidade da Lua.
 *
 * A velocidade com que a Lua se move em relação à Terra, representada como um float.
 */
const float MOON_SPEED = (EARTH_SPEED * 0.3f); // Velocidade da Lua relativa à Terra

/**
 * @var MARS_SPEED
 * @brief Velocidade de Marte.
 *
 * A velocidade com que Marte se move ou orbita, representada como um float.
 */
const float MARS_SPEED = 1.5;

/**
 * @var JUPITER_SPEED
 * @brief Velocidade de Júpiter.
 *
 * A velocidade com que Júpiter se move ou orbita, representada como um float.
 */
const float JUPITER_SPEED = 1.0;

/**
 * @var SATURN_SPEED
 * @brief Velocidade de Saturno.
 *
 * A velocidade com que Saturno se move ou orbita, representada como um float.
 */
const float SATURN_SPEED = 0.8;

/**
 * @var URANUS_SPEED
 * @brief Velocidade de Urano.
 *
 * A velocidade com que Urano se move ou orbita, representada como um float.
 */
const float URANUS_SPEED = 0.6;

/**
 * @var NEPTUNE_SPEED
 * @brief Velocidade de Netuno.
 *
 * A velocidade com que Netuno se move ou orbita, representada como um float.
 */
const float NEPTUNE_SPEED = 0.5;

#endif // PLANET_SPEEDS_H
