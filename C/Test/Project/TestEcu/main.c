#include "eCUCrcTest.h"
#include "eCUCrcDigestTest.h"
#include "eCUCircularQueueTest.h"
#include "eCUDataPackTest.h"
#include "eCUDataUnPackTest.h"
#include "eCUDataPackUnPackTest.h"
#include "eCUByteStufferTest.h"
#include "eCUByteUnStufferTest.h"
#include "eCUDataStuffUnStuffTest.h"
int main(void);


int main(void)
{
    /* Start testing */
    eCU_TEST_crc32();
    eCU_TEST_cUCrcDigest();
    eCU_TEST_circularQueue();
    eCU_TEST_dataPack();
    eCU_TEST_dataUnPack();
	eCU_TEST_dataPackUnPack();
    eCU_TEST_byteStuffer();
    eCU_TEST_byteUnStuffer();
    eCU_TEST_dataStuffUnStuff();

    return 0;
}
