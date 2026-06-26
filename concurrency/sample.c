//Two tasks share an SPI bus. 
//Write the skeleton showing how a binary semaphore protects the bus. 
//Identify what happens if the high-priority task blocks on the semaphore
// held by a lower-priority task.

//#include "FreeRTOS.h"
#include "semphr.h"

SemaphoreHandle_t spi_mutex;

void high_prio_task(void *p) {
    for(;;) {
        /* acquire mutex, do SPI, release */
    }
}

void low_prio_task(void *p) {
    for(;;) {
        /* acquire mutex, do SPI, release */
    }
}