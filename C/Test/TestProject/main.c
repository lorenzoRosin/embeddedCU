#include "eCUCrcTest.h"
#include "eCUCircularQueueTest.h"
#include "eCUDataPackTest.h"
#include "eCUDataUnPackTest.h"
#include "eCUDataPackUnPackTest.h"

int main(void);


int main(void)
{
    crc32Test();
    circularQueueTest();
    dataPackTest();
    dataUnPackTest();
	dataPackUnPackTest();
	
    return 0;
}
