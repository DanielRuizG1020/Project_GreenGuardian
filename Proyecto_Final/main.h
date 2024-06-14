/**
 * @file main.h
 * @brief This is a brief description of the main H file.
 *
 * Detailed description of the main C file.
 */
 
// Avoid duplication in code
#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/sync.h"
#include "oled.h"

/**
 * @brief Inicializa todos los pines GPIO utilizados en el proyecto.
 *
 * Esta función configura los pines GPIO necesarios como entrada o salida
 * dependiendo de su uso previsto.
 */
void Pin_Inicialization();

/**
 * @brief Mide la duración de un pulso en el pin GPIO especificado.
 *
 * Esta función mide la duración de un pulso en el pin GPIO especificado 
 * y en el estado especificado (alto o bajo).
 *
 * @param gpio El número del pin GPIO a medir.
 * @param state El estado del pin GPIO (alto o bajo) durante el pulso.
 * @return La duración del pulso en microsegundos.
 */
long pulseIn(uint gpio, uint state);


/**
 * @brief Mapea un valor de un rango a otro.
 *
 * Esta función toma un valor en un rango de entrada y lo mapea a un rango de salida.
 *
 * @param x El valor a mapear.
 * @param in_min El valor mínimo del rango de entrada.
 * @param in_max El valor máximo del rango de entrada.
 * @param out_min El valor mínimo del rango de salida.
 * @param out_max El valor máximo del rango de salida.
 * @return El valor mapeado al rango de salida.
 */
int mapeo(int x, int in_min, int in_max, int out_min, int out_max);



/**
 * @brief Inicializa los pines GPIO utilizados en el proyecto.
 *
 * Esta función inicializa los pines GPIO utilizados en el proyecto, 
 * configurándolos como entrada o salida según sea necesario.
 */
void delay(uint32_t milliseconds) {
    uint64_t start_time = time_us_64();

    // Convertir el tiempo de espera de milisegundos a microsegundos
    uint64_t delay_us = (uint64_t) milliseconds * 1000;

    while ((time_us_64() - start_time) < delay_us) {
        // Esperar hasta que haya pasado el tiempo especificado
    }
}


#endif