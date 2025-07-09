/**
 * @file orbit_radii.h
 * @brief Define os raios orbitais dos planetas.
 *
 * Este arquivo contém constantes que representam os raios orbitais de vários planetas.
 * Esses valores são usados para determinar a distância da órbita de cada planeta em relação ao Sol.
 */

#ifndef ORBIT_RADII_H
#define ORBIT_RADII_H

/**
 * @var MERCURY_ORBIT_RADIUS
 * @brief Raio orbital de Mercúrio.
 *
 * A distância da órbita de Mercúrio em relação ao Sol, representada como um float.
 */
const float MERCURY_ORBIT_RADIUS = 5.0;

/**
 * @var VENUS_ORBIT_RADIUS
 * @brief Raio orbital de Vênus.
 *
 * A distância da órbita de Vênus em relação ao Sol, representada como um float.
 */
const float VENUS_ORBIT_RADIUS = 8.0;

/**
 * @var EARTH_ORBIT_RADIUS
 * @brief Raio orbital da Terra.
 *
 * A distância da órbita da Terra em relação ao Sol, representada como um float.
 */
const float EARTH_ORBIT_RADIUS = 11.0;

/**
 * @var MOON_ORBIT_RADIUS
 * @brief Raio orbital da Lua.
 *
 * A distância da órbita da Lua em relação à Terra, representada como um float.
 */
const float MOON_ORBIT_RADIUS = 1; // Relativo à Terra

/**
 * @var MARS_ORBIT_RADIUS
 * @brief Raio orbital de Marte.
 *
 * A distância da órbita de Marte em relação ao Sol, representada como um float.
 */
const float MARS_ORBIT_RADIUS = 14.0;

/**
 * @var JUPITER_ORBIT_RADIUS
 * @brief Raio orbital de Júpiter.
 *
 * A distância da órbita de Júpiter em relação ao Sol, representada como um float.
 */
const float JUPITER_ORBIT_RADIUS = 20.0;

/**
 * @var SATURN_ORBIT_RADIUS
 * @brief Raio orbital de Saturno.
 *
 * A distância da órbita de Saturno em relação ao Sol, representada como um float.
 */
const float SATURN_ORBIT_RADIUS = 28.0;

/**
 * @var URANUS_ORBIT_RADIUS
 * @brief Raio orbital de Urano.
 *
 * A distância da órbita de Urano em relação ao Sol, representada como um float.
 */
const float URANUS_ORBIT_RADIUS = 35.0;

/**
 * @var NEPTUNE_ORBIT_RADIUS
 * @brief Raio orbital de Netuno.
 *
 * A distância da órbita de Netuno em relação ao Sol, representada como um float.
 */
const float NEPTUNE_ORBIT_RADIUS = 40.0;

#endif // ORBIT_RADII_H
