/**
 * @file dht22-pico.h
 * @brief This is a brief description of the dht22-pico.h file.
 *
 * Detailed description of the dht22-pico.h file.
 */
 
#ifndef DHT22_PICO_H
#define DHT22_PICO_H

#include "pico/stdlib.h"

/// Código de estado indicando una lectura exitosa del DHT22.
#define DHT_OK              0

/// Código de estado indicando un error de checksum durante la lectura del DHT22.
#define DHT_ERR_CHECKSUM    1

/// Código de estado indicando un error NaN (No es un número) durante la lectura del DHT22.
#define DHT_ERR_NAN         2

/**
 * @brief Estructura para almacenar las lecturas del sensor DHT22.
 */
typedef struct {
    uint pin;  /**< Número del pin GPIO conectado al sensor DHT22. */
    float humidity;  /**< Lectura de humedad del sensor DHT22. */
    float temp_celsius; /**< Lectura de temperatura en grados Celsius del sensor DHT22. */
} dht_reading;


/**
 * @brief Inicializa el sensor DHT22.
 *
 * Esta función configura el pin GPIO especificado para la comunicación con
 * el sensor DHT22.
 *
 * @param pin El número del pin GPIO conectado al sensor DHT22.
 * @return Una estructura dht_reading con el pin inicializado.
 */
dht_reading dht_init(uint8_t pin);




/**
 * @brief Lee los datos del sensor DHT22.
 *
 * Esta función lee los datos del sensor DHT22 y los almacena en la estructura
 * dht_reading proporcionada.
 *
 * @param dht Un puntero a la estructura dht_reading donde se almacenarán los datos leídos.
 * @return Un código de estado que indica si la lectura fue exitosa o si se produjo un error.
 */
uint8_t dht_read(dht_reading *dht);

#endif