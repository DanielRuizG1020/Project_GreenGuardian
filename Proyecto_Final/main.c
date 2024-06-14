/**
 * @file main.c
 * @brief This is a brief description of the main C file.
 *
 * Detailed description of the main C file.
 * Este archivo contiene la función principal y la inicialización de los pines para la Raspberry Pi Pico,
 * así como la lógica para leer y procesar datos de varios sensores.
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "oled.h"
#include "main.h"
#include "dht22-pico.h"
#include "hardware/adc.h"

#define trigger_pin1 2
#define echo_pin1 3
#define buzzer 0
#define trigger_pin2 4
#define echo_pin2 5
#define led_pin 6
#define LDR_pin 7
#define bomba_pin 13
#define ventilador_pin 14
#define neon_pin 15

const uint8_t sensorPin = 26;
const uint8_t DHT22_pin = 8;


long pulseIn(uint gpio, uint state) {
    uint32_t start_time = time_us_32();
    while (gpio_get(gpio) != state) {
        if (time_us_32() - start_time > 1000000) { // Timeout después de 1 segundo
            return 0;
        }
    }
    uint32_t pulse_start = time_us_32();
    while (gpio_get(gpio) == state) {
        if (time_us_32() - start_time > 1000000) { // Timeout después de 1 segundo
            return 0;
        }
    }
    return time_us_32() - pulse_start;
}

int mapeo(int x, int in_min, int in_max, int out_min, int out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void Pin_Inicialization() {
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
    gpio_init(trigger_pin1);
    gpio_set_dir(trigger_pin1, GPIO_OUT);
    gpio_init(echo_pin1);
    gpio_set_dir(echo_pin1, GPIO_IN);
    gpio_init(buzzer);
    gpio_set_dir(buzzer, GPIO_OUT);
    gpio_init(trigger_pin2);
    gpio_set_dir(trigger_pin2, GPIO_OUT);
    gpio_init(echo_pin2);
    gpio_set_dir(echo_pin2, GPIO_IN);
    gpio_init(LDR_pin);
    gpio_set_dir(LDR_pin, GPIO_IN);
    gpio_init(DHT22_pin);
    gpio_set_dir(DHT22_pin, GPIO_OUT);
    gpio_init(bomba_pin);
    gpio_set_dir(bomba_pin, GPIO_OUT);
    gpio_init(ventilador_pin);
    gpio_set_dir(ventilador_pin, GPIO_OUT);
    gpio_init(neon_pin);
    gpio_set_dir(neon_pin, GPIO_OUT);
  
    }


// Main function
int main() {
    // Initialize standard I/O
    stdio_init_all();
    sleep_ms(7000);
    Pin_Inicialization();
    adc_init();
    adc_gpio_init(sensorPin);
    dht_reading dht = dht_init(DHT22_pin);
    uint8_t hum=0;
    uint8_t temp=0;

    


    /**
     * @brief Función principal que inicializa el sistema y realiza lecturas de sensores.
     *
     * Esta función inicializa el sistema, configura los pines GPIO y entra en un bucle
     * donde continuamente lee los valores de varios sensores y toma acciones basadas
     * en esos valores.
     *
     * @return Devuelve 0 al finalizar.
     */
    while (1) {
        /// Lectura de los sensores de ultrasonido
        gpio_put(trigger_pin1, 0);
        busy_wait_us_32(2);
        gpio_put(trigger_pin1, 1);
        busy_wait_us_32(10);
        gpio_put(trigger_pin1, 0);
        uint64_t duration1 = pulseIn(echo_pin1, 1);
        uint32_t distance1 = duration1 / 58;
        gpio_put(trigger_pin2, 0);
        busy_wait_us_32(2);
        gpio_put(trigger_pin2, 1);
        busy_wait_us_32(10);
        gpio_put(trigger_pin2, 0);
        uint64_t duration2 = pulseIn(echo_pin2, 1);
        uint32_t distance2 = duration2 / 58;
        
        /// Control del buzzer en función de la distancia
        if (distance1 <= 6) {
            gpio_put(buzzer, 1);
        } else {
            gpio_put(buzzer, 0);
        }

        /// Control del LED en función de la distancia
        if(distance2 >= 6){
            gpio_put(led_pin,1);
        } else {
            gpio_put(led_pin,0);
        }

        /// Lectura del sensor de humedad del suelo
        adc_select_input(0);
        uint16_t raw = adc_read();
        int humedad = mapeo(raw, 0, 4095, 100, 0);
        //printf("Humedad: %d\n", humedad);
        if (humedad < 30) {
            gpio_put(bomba_pin, 1);
        } else {
            gpio_put(bomba_pin, 0);
        }

        /// Lectura del sensor LDR
        uint8_t LDR_value = gpio_get(LDR_pin);
        if (LDR_value == 1) {
            //printf("LDR: %d\n", LDR_value);
            gpio_put(neon_pin, 0);
        } else {
            //printf("LDR: %d\n", LDR_value);
            gpio_put(neon_pin, 1);
        }

        /// Lectura del sensor DHT22
        uint8_t status = dht_read(&dht);
        if (status == DHT_OK) {
            temp = dht.temp_celsius;
            hum = dht.humidity;
            if (temp > 26) {
                gpio_put(ventilador_pin, 1);
            } else {
                gpio_put(ventilador_pin, 0);
            }
            //printf("RH: %.1f%%\tTemp: %.1fC\n", dht.humidity, dht.temp_celsius);
        } else if (status == DHT_ERR_CHECKSUM) {
            printf("Bad data (checksum)\n");
        } else {
            printf("Bad data (NaN)\n");
        }
        
        show_current_data(temp, hum, humedad);
        

        sleep_ms(100); 
    }

    return 0;
}



