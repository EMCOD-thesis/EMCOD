#include "stm32n6xx_hal.h"
#include "cmw_camera.h"

void CSI_IRQHandler(void)
{
    DCMIPP_HandleTypeDef *hcamera_dcmipp = CMW_CAMERA_GetDCMIPPHandle();
    HAL_DCMIPP_CSI_IRQHandler(hcamera_dcmipp);
}

void DCMIPP_IRQHandler(void)
{
    DCMIPP_HandleTypeDef *hcamera_dcmipp = CMW_CAMERA_GetDCMIPPHandle();
    HAL_DCMIPP_IRQHandler(hcamera_dcmipp);
}