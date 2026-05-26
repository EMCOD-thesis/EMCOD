#include <sys/stat.h>
#include <errno.h>
#include <sys/times.h>
#include "stm32n6xx_hal.h"
#include <sys/unistd.h>
#include <stdint.h>

extern int __io_putchar(int ch) __attribute__((weak));
extern int __io_getchar(void) __attribute__((weak));

char *__env[1] = { 0 };
char **environ = __env;

extern UART_HandleTypeDef huart1;

int _write(int file, char *ptr, int len) {
    if ((file != STDOUT_FILENO) && (file != STDERR_FILENO)) {
        errno = EBADF;
        return -1;
    }
    if (huart1.Instance == NULL) 
        return 0;
    HAL_StatusTypeDef status = HAL_UART_Transmit(&huart1, (uint8_t *)ptr, len, 100);
    return (status == HAL_OK) ? len : 0;
}

int _kill(int pid, int sig) {
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

void _exit(int status) {
    _kill(status, -1);
    while (1) {}
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
    (void)file;
    (void)line;
    while (1) ;
}
#endif