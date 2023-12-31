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

#ifndef LEDS_H
#define LEDS_H

/** @file
 ** @brief Declaraciones publicas de las funciones del controlador LED
 **/

/* === Headers files inclusions
 * ================================================================ */

#include <stdint.h>

/* === Cabecera C++
 * ============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions
 * =============================================================== */

/* === Public data type declarations
 * =========================================================== */

/* === Public variable declarations
 * ============================================================ */

/* === Public function declarations
 * ============================================================ */

/**
 * @brief Función para inicializar los leds
 *
 * @param puerto direccion de puerto de entrada/salida de los leds
 */
void LedsInit(uint16_t * puerto);

/**
 * @brief Función para encender un led
 *
 * @param led numero de led a prender (1 a 16)
 */
void LedTurnOn(unsigned int led);

/**
 * @brief Función para apagar un led
 *
 * @param led numero de led a apagar (1 a 16)
 */
void LedTurnOff(unsigned int led);

/**
 * @brief Función para consultar el estado de un led
 *
 * @param led numero de led a consultar (1 a 16)
 * @return 1 si esta encendido, 0 si esta apagado.
 */
unsigned int LedStatus(unsigned int led);

/**
 * @brief Función para encender todos los leds simultaneamente
 */
void LedTurnOnAll();

/**
 * @brief Función para apagar todos los leds simultaneamente
 */
void LedTurnOffAll();

/* === End of documentation
 * ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */
