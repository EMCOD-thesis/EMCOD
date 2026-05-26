#ifndef CMW_CAMERA_CONF_H
#define CMW_CAMERA_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32n6xx_hal.h"
#include "stm32n6xx_nucleo_bus.h"


/* ########################## Module Selection ############################## */
/**
  * @brief This is the list of modules to be used in the HAL driver
  */
#define USE_IMX335_SENSOR
#define USE_VD66GY_SENSOR
#define USE_VD55G1_SENSOR
#define USE_VD1943_SENSOR
#define USE_OV5640_SENSOR

#ifdef __cplusplus
}
#endif

#endif /* CMW_CAMERA_CONF_H */
