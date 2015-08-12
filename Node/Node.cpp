/*
 * Node.cpp
 *
 *  Created on: Aug 10, 2015
 *      Author: cnull
 */

#include "Node.h"

Node::Node(uint8_t id, uint8_t network, uint8_t gateway, uint8_t freq,  const char* key)
: RFM69(), SPIFlash(8,0xEF30) {

	initFlash();
	initRadio(freq, id, network, key);
}

void Node::initRadio(uint8_t freq, uint8_t id, uint8_t network, const char* key){
	RFM69::initialize(freq, id, network);
	setHighPower();
	encrypt(key);
	char buff[50];
	sprintf(buff, "\nTransmitting at %d Mhz...", freq==RF69_433MHZ ? 433 : freq==RF69_868MHZ ? 868 : 915);
	Serial.println(buff);
}

void Node::initFlash(){
	if (SPIFlash::initialize())
	{
	  Serial.print("SPI Flash Init OK ... UniqueID (MAC): ");
	  readUniqueId();
	  for (byte i=0;i<8;i++)
	  {
		Serial.print(UNIQUEID[i], HEX);
		Serial.print(' ');
	  }
	  Serial.println();
	}else{
	  Serial.println("SPI Flash Init FAIL! (is chip present?)");
	}
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

