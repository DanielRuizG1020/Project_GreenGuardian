/**
 * @file dht22-pico.c
 * @brief This is a brief description of the dht22-pico.c file.
 *
 * Detailed description of the dht22-pico.c file.
 */
#include "dht22-pico.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <math.h>

dht_reading dht_init(uint8_t pin) {
    gpio_init(pin);
    dht_reading dht;
    dht.pin = pin;
    return dht;
}

static uint32_t wait_for(uint8_t pin, uint8_t expect) {
    uint32_t then = time_us_32();
    while (expect != gpio_get(pin)) {
        sleep_us(10);
    }
    return time_us_32() - then;
}

inline static float word(uint8_t first, uint8_t second) {
    return (float) ((first << 8) + second);
}


uint8_t dht_read(dht_reading *dht) {
    uint8_t data[5] = {0, 0, 0, 0, 0};

    gpio_set_dir(dht->pin, GPIO_OUT);
    gpio_put(dht->pin, 0);
    sleep_ms(10);
    gpio_put(dht->pin, 1);
    sleep_us(40);
    
    gpio_set_dir(dht->pin, GPIO_IN);
    wait_for(dht->pin, 0);
    wait_for(dht->pin, 1);
    wait_for(dht->pin, 0);

    for (uint8_t bit = 0; bit < 40; ++bit) {
        wait_for(dht->pin, 1);
        uint8_t count = wait_for(dht->pin, 0);
        data[bit / 8] <<= 1;
        if (count > 50) {
            data[bit / 8] |= 1;
        }
    }

    gpio_set_dir(dht->pin, GPIO_OUT);
    gpio_put(dht->pin, 1);

    if (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
        float humidity = word(data[0], data[1]) / 10;
        float temp = word(data[2] & 0x7F, data[3]) / 10;

        if (data[2] & 0x80) {
            temp = -temp;
        }

        if (isnan(temp) || isnan(humidity) ||temp == 0) {
            return DHT_ERR_NAN;
        } else {
            dht->humidity = humidity;
            dht->temp_celsius = temp;
            return DHT_OK;
        }
    } else {
        return DHT_ERR_CHECKSUM;
    }
}