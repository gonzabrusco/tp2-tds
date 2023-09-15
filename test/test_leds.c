
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
 ** @brief Funciones de TEST del controlador de leds
 **/

/**
 * @todo Prendo y apago un led con algunos prendidos y otros apagados
 * @todo Consulto el estado de un led prendido
 * @todo Consulto el estado de un led apagado
 * @todo Con todos los leds apagados los prendo todos juntos
 * @todo Con todos los leds prendidos los apago todos juntos
 * @todo Probaria el led 1 y el 16
 * @todo Probaria fuera de los limtes de los argumentos
 * @todo Probar que ocurre cuando el puerto es NULL
 * @todo Probar que ocurre si intentan usar un led sin antes inicializar el controlador
 */

/* === Headers files inclusions
 * =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions
 * ====================================================================== */

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
static uint16_t puerto_virtual;

/* === Private function implementation
 * ========================================================= */

/* === Public function implementation
 * ========================================================== */

void setUp(void) {
    LedsInit(&puerto_virtual);
}

void test_todos_los_tests_arrancan_apagados(void) {
    // Se define una variable que representa al puerto con todos los leds encendidos
    uint16_t puerto_virtual = 0xFF;

    // Inicializo el puerto
    LedsInit(&puerto_virtual);

    // Se revisa que los leds queden apagados
    TEST_ASSERT_EQUAL(0, puerto_virtual);
}

void test_encender_un_led_apagado(void) {
    // Enciendo un led
    LedTurnOn(5);

    // Se revisa que el led 5 este encendido y e resto apagado
    TEST_ASSERT_BIT_HIGH(4, puerto_virtual);
    TEST_ASSERT_BITS_LOW(~(1 << 4), puerto_virtual);
}

void test_apagar_un_led_prendido(void) {
    // Enciendo un led
    LedTurnOn(5);
    // Apago el mismo led
    LedTurnOff(5);

    // Se revisa que los leds queden apagados
    TEST_ASSERT_EQUAL(0, puerto_virtual);
}

/* === End of documentation
 * ==================================================================== */
