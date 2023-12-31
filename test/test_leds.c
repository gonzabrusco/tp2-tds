
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

void test_prender_varios_leds() {
    // Enciendo y apago algunos leds
    LedTurnOn(5);
    LedTurnOn(3);

    TEST_ASSERT_BIT_HIGH(4, puerto_virtual);
    TEST_ASSERT_BIT_HIGH(2, puerto_virtual);
}

void test_prender_y_apagar_varios_leds() {
    // Enciendo y apago algunos leds
    LedTurnOn(5);
    LedTurnOn(3);
    LedTurnOn(3);
    LedTurnOff(5);
    LedTurnOff(2);

    TEST_ASSERT_BIT_LOW(4, puerto_virtual);
    TEST_ASSERT_BIT_HIGH(2, puerto_virtual);
    TEST_ASSERT_BIT_LOW(1, puerto_virtual);
    TEST_ASSERT_BITS_LOW(~(1 << 2), puerto_virtual);
}

void test_consultar_estado_led_prendido() {
    // Enciendo dos leds (la funcion setup los inicializa apagados)
    LedTurnOn(9);
    LedTurnOn(3);

    // Consulto el estado de los leds
    unsigned int led1 = LedStatus(9);
    unsigned int led2 = LedStatus(3);

    TEST_ASSERT_EQUAL(1, led1);
    TEST_ASSERT_EQUAL(1, led2);
}

void test_consultar_estado_led_apagado() {
    // Enciendo dos leds (la funcion setup los inicializa apagados)
    LedTurnOn(10);
    LedTurnOn(4);

    // Los apago
    LedTurnOff(10);
    LedTurnOff(4);

    // Consulto el estado de los leds
    unsigned int led1 = LedStatus(10);
    unsigned int led2 = LedStatus(4);

    TEST_ASSERT_EQUAL(0, led1);
    TEST_ASSERT_EQUAL(0, led2);
}

void test_encender_todos_los_leds_juntos() {
    // Los leds comienzan apagados

    LedTurnOnAll();

    TEST_ASSERT_EQUAL(0xFFFF, puerto_virtual);
}

void test_apagar_todos_los_leds_juntos() {
    // Los leds comienzan apagados. Los enciendo.
    LedTurnOnAll();
    // Los apago todos
    LedTurnOffAll();

    TEST_ASSERT_EQUAL(0, puerto_virtual);
}

/* === End of documentation
 * ==================================================================== */
