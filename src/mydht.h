/*
 * mydht.h
 *
 *  Created on: Mar 7, 2023
 *      Author: mannk
 */

#ifndef SRC_MYDHT_H_
#define SRC_MYDHT_H_

#include <stdint.h>
#include <math.h>

typedef enum {
	AUTO_DETECT,
	DHT11,
	DHT22,
	AM2302,  // Packaged DHT22
	RHT03    // Equivalent to DHT22
}
DHT_MODEL_t;

typedef enum {
	ERROR_NONE = 0,
	ERROR_TIMEOUT,
	ERROR_CHECKSUM
}
DHT_ERROR_t;

typedef struct DHTsensor {
	// private
	uint8_t pin;
	DHT_MODEL_t model;
	DHT_ERROR_t error;
	float temperature;
	float humidity;
	void (*readSensor)();

	// public call functions
	float (*getTemperature)();
	float (*getHumidity)();
	DHT_MODEL_t (*getModel)();
	DHT_ERROR_t (*getStatus)();
};

typedef struct DHTsensor *mydht;

// init
mydht dhtInit(uint8_t pin, DHT_MODEL_t model);
// get temp
float getTemperature();
// get hump
float getHumidity();
// get model
DHT_MODEL_t getModel (mydht self);
// get err
DHT_ERROR_t getStatus(mydht self);
// main function
void readsensor(mydht self);


#endif /* SRC_MYDHT_H_ */
