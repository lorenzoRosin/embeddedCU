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
    eCU_CRCTST_ExeTest();
    eCU_CRCDTST_ExeTest();
    eCU_CIRQTST_ExeTest();
    eCU_DPKTST_ExeTest();
    eCU_DUNPKTST_ExeTest();
	eCU_DPKDUNPKTST_ExeTest();
    eCU_BSTFTST_ExeTest();
    eCU_BUSTFTST_ExeTest();
    eCU_BSTFBUNSTFTST_ExeTest();

    return 0;
}
