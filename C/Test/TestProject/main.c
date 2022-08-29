#include "eCUCrcTest.h"
#include "eCUCircularQueueTest.h"
#include "eCUDataPackTest.h"
#include "eCUDataUnPackTest.h"
#include "eCUDataPackUnPackTest.h"
#include "eCUByteStufferTest.h"

int main(void);


int main(void)
{
    crc32Test();
    circularQueueTest();
    dataPackTest();
    dataUnPackTest();
	dataPackUnPackTest();
    eCUByteStufferTest();

    return 0;
}
