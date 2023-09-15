
/************************************************************************************************
Copyright (c) 2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file
 ** @brief Funciones del controlador de leds
 **/

/* === Headers files inclusions
 * =============================================================== */

#include "leds.h"

/* === Macros definitions
 * ====================================================================== */

// Constante con el 1 necesario para encender un led
#define LED_ON_STATE 1

// Constante para apagar todos los leds
#define LED_ALL_OFF 0

// Offset que relaciona un numero de led con el bit correspondiente
#define LED_OFFSET 1

/* === Private data type declarations
 * ========================================================== */

/* === Private variable declarations
 * =========================================================== */

/* === Private function declarations
 * =========================================================== */

/* === Public variable definitions
 * ============================================================= */

/* === Private variable definitions
 * ============================================================ */

static uint16_t * direccion_puerto;

/* === Private function implementation
 * ========================================================= */

/**
 * @brief Función para obtener una mascara correspondiente al led indicado
 *
 * @param led numero de led para obtener la mascara
 */
static uint16_t LedToMask(unsigned int led) {
    return LED_ON_STATE << (led - LED_OFFSET);
}

/* === Public function implementation
 * ========================================================== */

void LedsInit(uint16_t * puerto) {
    direccion_puerto = puerto;
    *direccion_puerto = LED_ALL_OFF;
}

void LedTurnOn(unsigned int led) {
    *direccion_puerto |= LedToMask(led);
}

void LedTurnOff(unsigned int led) {
    *direccion_puerto &= ~LedToMask(led);
}

/* === End of documentation
 * ==================================================================== */
