#ifndef MX25UM51245G_CONF_H
#define MX25UM51245G_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32n6xx_hal.h"

/** @addtogroup BSP
  * @{
  */
#define CONF_OSPI_ODS                MX25UM51245G_CR_ODS_24   /* MX25UM51245G Output Driver Strength */

#define DUMMY_CYCLES_READ            8U
#define DUMMY_CYCLES_READ_OCTAL      6U
#define DUMMY_CYCLES_READ_OCTAL_DTR  6U
#define DUMMY_CYCLES_REG_OCTAL       4U
#define DUMMY_CYCLES_REG_OCTAL_DTR   5U

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* MX25UM51245G_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
