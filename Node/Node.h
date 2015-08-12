/*
 * Node.h
 *
 *  Created on: Aug 10, 2015
 *      Author: cnull
 */

#ifndef NODE_H_
#define NODE_H_

#include <RFM69.h>
#include <SPI.h>
#include <SPIFlash.h>
#include <WirelessHEX69.h>

class Node: public RFM69, public SPIFlash, public SPIClass {
public:
	Node(uint8_t id, uint8_t network, uint8_t gateway, uint8_t freq, const char* key);
	virtual ~Node();
private:
	// functions
	void initFlash();
	void initRadio(uint8_t freq, uint8_t id, uint8_t network, const char* key);
	// variables
	uint8_t _GATEWAYID;
};

#endif /* NODE_H_ */
