#include "main.h"
#include "stm32n6xx_hal.h"
#include <errno.h>
#include <stdint.h>
#include <sys/unistd.h>

extern UART_HandleTypeDef huart1;

int _write(int file, char *ptr, int len)
{
    if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
    {
        errno = EBADF;
        return -1;
    }

    if (huart1.Instance == NULL)
    {
        return 0;
    }

    HAL_StatusTypeDef status =
        HAL_UART_Transmit(&huart1, (uint8_t *)ptr, len, 100);

    return (status == HAL_OK) ? len : 0;
}