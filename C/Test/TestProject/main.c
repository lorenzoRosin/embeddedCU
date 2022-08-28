#include "eCUCrcTest.h"
#include "eCUCircularQueueTest.h"
#include "eCUDataPackTest.h"
#include "eCUDataUnPackTest.h"

int main(void);


int main(void)
{
    crc32Test();
    circularQueueTest();
    dataPackTest();
    dataUnPackTest();
    return 0;
}
