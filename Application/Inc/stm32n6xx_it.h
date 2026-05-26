#ifndef STM32N6xx_IT_H
#define STM32N6xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void SVC_Handler(void);
void SysTick_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* STM32N6xx_IT_H */

