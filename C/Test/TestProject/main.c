#include "eCUCrcTest.h"
#include "eCUCrcDigestTest.h"
#include "eCUCircularQueueTest.h"
//#include "eCUDataPackTest.h"
//#include "eCUDataUnPackTest.h"
//#include "eCUDataPackUnPackTest.h"
//#include "eCUByteStufferTest.h"

int main(void);


int main(void)
{
    crc32Test();
    cUCrcDigestTest();
    circularQueueTest();
    //dataPackTest();
    //dataUnPackTest();
	//dataPackUnPackTest();
    //eCUByteStufferTest();

    return 0;
}
