/*
 * mydht.c
 *
 *  Created on: Mar 7, 2023
 *      Author: mannk
 */

#include "mydht.h"

mydht dhtInit (uint8_t pin, DHT_MODEL_t model){
	mydht self = (mydht) malloc(sizeof(struct DHTsensor)); // return address of created struct
	self->pin= pin;
	self->model= model;

	if (model == AUTO_DETECT)
	{
		self->model = DHT22;
		readSensor();
		if (self->error == ERROR_TIMEOUT)
		{
			self->model = DHT11;
			// Warning: in case we auto detect a DHT11, you should wait at least 1000 msec
			// before your first read request. Otherwise you will get a time out error.
		}
	}

	return self;
}

void readsensor(mydht self){
	self->temperature = NAN;
	self->humidity= NAN;

	uint16_t rawHumidity = 0;
	uint16_t rawTemperature = 0;
	uint16_t data = 0;
}
