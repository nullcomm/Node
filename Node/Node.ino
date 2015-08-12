#include "Node.h"

#define NODEID		12
#define NETWORKID	100
#define GATEWAYID	1
////////////SET FREQUENCY//////////////
//#define FREQUENCY   RF69_433MHZ	///
//#define FREQUENCY   RF69_868MHZ	///
#define FREQUENCY   RF69_915MHZ   ///
///////////////////////////////////////
#define ENCRYPTKEY	"sampleEncryptKey" // Must be same on all nodes







//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
Node node(NODEID, NETWORKID, GATEWAYID, FREQUENCY, ENCRYPTKEY);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
