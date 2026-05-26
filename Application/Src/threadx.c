#include "tx_api.h"
#include "stm32n6xx_nucleo.h"
#include <stdio.h>

#define BLINK_THREAD_STACK_SIZE 1024

static TX_THREAD blink_thread;
static ULONG blink_stack[BLINK_THREAD_STACK_SIZE / sizeof(ULONG)];

static void blink(ULONG thread_input) {
    printf("printf works\r\n");
    BSP_LED_Init(LED_GREEN);
    BSP_LED_Init(LED_RED);
    while (1) {
        BSP_LED_Toggle(LED_GREEN);
        BSP_LED_Toggle(LED_RED);
        tx_thread_sleep(TX_TIMER_TICKS_PER_SECOND * 3);
    }
}

void tx_application_define(void *first_unused_memory) {
    tx_thread_create(&blink_thread, "blink", blink, 0, blink_stack, sizeof(blink_stack), 3, 3, TX_NO_TIME_SLICE, TX_AUTO_START);
}