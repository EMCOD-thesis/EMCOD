cmake_minimum_required(VERSION 3.20)

project(EMCOD C ASM)

set(TARGET_NAME Project)
set(MODEL_DIR "${CMAKE_CURRENT_LIST_DIR}/../Model/NUCLEO-N657X0-Q")
set(BINARY_DIR Binary)

set(SCR_LIB_SCREEN_ITF "UVCL" CACHE STRING "Screen interface: LTDC, UVCL or SPI")
set(SCR_LIB_RTOS "NONE" CACHE STRING "RTOS for screen lib: NONE, THREADX or FREERTOS")

set(APP_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(ROOT_DIR "${APP_DIR}/..")
set(BUILD_TOP "${CMAKE_BINARY_DIR}")
set(BUILD_DIR "${CMAKE_BINARY_DIR}/Application")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIR}")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

file(GLOB APP_SRC CONFIGURE_DEPENDS "${APP_DIR}/Src/*.c")
file(GLOB THREADX_COMMON_SRC CONFIGURE_DEPENDS "${ROOT_DIR}/Middlewares/threadx/common/src/*.c")
file(GLOB AI_POSTPROCESSING_SRC CONFIGURE_DEPENDS "${ROOT_DIR}/Middlewares/ai-postprocessing-wrapper/*.c")
file(GLOB VISION_PP_SRC CONFIGURE_DEPENDS "${ROOT_DIR}/Middlewares/stm32-vision-models-postprocessing/lib_vision_models_pp/Src/*.c")
file(GLOB THREADX_PORT_C_SRC CONFIGURE_DEPENDS "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/*.c")

set(C_SOURCES
    ${APP_SRC}
    ${THREADX_COMMON_SRC}
    ${AI_POSTPROCESSING_SRC}
    ${VISION_PP_SRC}
    ${THREADX_PORT_C_SRC}

    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/Devices/STM32N6xx/mcu_cache.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/Devices/STM32N6xx/npu_cache.c"
    "${MODEL_DIR}/network.c"
    "${MODEL_DIR}/stai_network.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/CMSIS/Device/ST/STM32N6xx/Source/Templates/system_stm32n6xx_fsbl.c"

    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_cortex.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dcmipp.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_spi.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma_ex.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma2d.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_gpio.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_uart.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_i2c.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_i2c_ex.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_ltdc.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_ltdc_ex.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rif.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_ramcfg.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_cacheaxi.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr_ex.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc_ex.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_xspi.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_bsec.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pcd.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pcd_ex.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_ll_usb.c"

    "${ROOT_DIR}/Middlewares/stm32-mw-camera/cmw_camera.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/cmw_utils.c"

    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo_bus.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo_xspi.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/Components/mx25um51245g/mx25um51245g.c"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/Components/aps256xx/aps256xx.c"

    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/imx335/imx335.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/imx335/imx335_reg.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/vd6g/vd6g.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/vd55g1/vd55g1.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/vd1943/vd1943.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/ov5640/ov5640.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/ov5640/ov5640_reg.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/cmw_vd55g1.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/cmw_vd66gy.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/cmw_imx335.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/cmw_vd1943.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/cmw_ov5640.c"

    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Src/isp_algo.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Src/isp_awb_algo.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Src/isp_ae_algo.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Src/isp_cmd_parser.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Src/isp_core.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Src/isp_services.c"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Src/isp_tool_com.c"

    "${ROOT_DIR}/STM32Cube_FW_N6/Utilities/lcd/stm32_lcd.c"

    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton_rt_main.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton_runtime.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton_cipher.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton_stai_internal.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton_util.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_sw_float.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_sw_integer.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton_lib.c"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton/ll_aton_lib_sw_operators.c"
)

set(ASM_SOURCES_s
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/CMSIS/Device/ST/STM32N6xx/Source/Templates/gcc/startup_stm32n657xx_fsbl.s"
)

set(ASM_SOURCES_S
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_initialize_low_level.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_context_restore.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_context_save.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_interrupt_control.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_interrupt_disable.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_interrupt_restore.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_schedule.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_stack_build.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_system_return.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_timer_interrupt.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_secure_stack_initialize.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_secure_stack_allocate.S"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/src/tx_thread_secure_stack_free.S"
)

set_source_files_properties(${ASM_SOURCES_s} ${ASM_SOURCES_S} PROPERTIES LANGUAGE ASM)

set(SCREENL_DIR "${ROOT_DIR}/Middlewares/screenl")
set(UVCL_DIR "${SCREENL_DIR}/uvcl")
set(USBX_DIR "${ROOT_DIR}/STM32Cube_FW_N6/Middlewares/ST/usbx")

set(SCREENL_SOURCES)
set(SCREENL_INCLUDES "${SCREENL_DIR}/Inc")
set(SCREENL_DEFINES "SCR_LIB_USE_${SCR_LIB_SCREEN_ITF}")

if(SCR_LIB_SCREEN_ITF STREQUAL "UVCL")
    list(APPEND SCREENL_SOURCES
        "${SCREENL_DIR}/Src/scrl_usb.c"
        "${SCREENL_DIR}/Src/scrl_common.c"
        "${UVCL_DIR}/Src/uvcl.c"
        "${UVCL_DIR}/Src/uvcl_desc.c"
        "${UVCL_DIR}/Src/usbx/uvcl_usbx.c"
    )

    file(GLOB USBX_SOURCES CONFIGURE_DEPENDS
        "${USBX_DIR}/common/core/src/ux_system_*.c"
        "${USBX_DIR}/common/core/src/ux_utility_*.c"
        "${USBX_DIR}/common/core/src/ux_device_*.c"
        "${USBX_DIR}/common/usbx_stm32_device_controllers/ux_dcd_stm32_*.c"
        "${USBX_DIR}/common/usbx_device_classes/src/ux_device_class_video_*.c"
    )
    list(APPEND SCREENL_SOURCES ${USBX_SOURCES})

    list(APPEND SCREENL_INCLUDES
        "${UVCL_DIR}/Inc"
        "${UVCL_DIR}/Src"
        "${UVCL_DIR}/Inc/usbx"
        "${UVCL_DIR}/Src/usbx"
        "${USBX_DIR}/common/core/inc"
        "${USBX_DIR}/ports/generic/inc"
        "${USBX_DIR}/common/usbx_device_classes/inc"
        "${USBX_DIR}/common/usbx_stm32_device_controllers"
    )

    list(APPEND SCREENL_DEFINES
        "SCR_LIB_USE_${SCR_LIB_RTOS}"
        UVC_LIB_USE_USBX
        UX_INCLUDE_USER_DEFINE_FILE
        USBL_PACKET_PER_MICRO_FRAME=3
    )

    if(SCR_LIB_RTOS STREQUAL "NONE")
        list(APPEND SCREENL_DEFINES UX_STANDALONE)
    elseif(SCR_LIB_RTOS STREQUAL "FREERTOS")
        list(APPEND SCREENL_DEFINES UX_STANDALONE UVCL_USBX_USE_FREERTOS)
    elseif(SCR_LIB_RTOS STREQUAL "THREADX")
        # Makefile screen library adds no extra define here.
    else()
        message(FATAL_ERROR "Unsupported SCR_LIB_RTOS=${SCR_LIB_RTOS}")
    endif()
elseif(SCR_LIB_SCREEN_ITF STREQUAL "LTDC")
    list(APPEND SCREENL_SOURCES "${SCREENL_DIR}/Src/scrl_lcd.c")
elseif(SCR_LIB_SCREEN_ITF STREQUAL "SPI")
    list(APPEND SCREENL_SOURCES
        "${SCREENL_DIR}/Src/scrl_spi.c"
        "${SCREENL_DIR}/Src/scrl_common.c"
        "${SCREENL_DIR}/ili9341/ili9341_reg.c"
        "${SCREENL_DIR}/ili9341/ili9341.c"
    )
    list(APPEND SCREENL_INCLUDES "${SCREENL_DIR}/ili9341")
    list(APPEND SCREENL_DEFINES "SCR_LIB_USE_${SCR_LIB_RTOS}" SCR_LIB_USE_SPI)
else()
    message(FATAL_ERROR "Unsupported SCR_LIB_SCREEN_ITF=${SCR_LIB_SCREEN_ITF}")
endif()

list(APPEND C_SOURCES ${SCREENL_SOURCES})

foreach(src IN LISTS C_SOURCES)
    get_filename_component(src_ext "${src}" EXT)
    if(src_ext STREQUAL ".c")
        get_filename_component(src_stem "${src}" NAME_WE)
        set_source_files_properties("${src}" PROPERTIES
            COMPILE_OPTIONS "-Wa,-a,-ad,-alms=${BUILD_DIR}/${src_stem}.lst"
        )
    endif()
endforeach()

add_library(${TARGET_NAME}_objects OBJECT
    ${C_SOURCES}
    ${ASM_SOURCES_s}
    ${ASM_SOURCES_S}
)

file(GENERATE
    OUTPUT "${BUILD_DIR}/${TARGET_NAME}.list"
    CONTENT "$<JOIN:$<TARGET_OBJECTS:${TARGET_NAME}_objects>,\n>\n"
)

add_executable(${TARGET_NAME} $<TARGET_OBJECTS:${TARGET_NAME}_objects>)
set_target_properties(${TARGET_NAME} PROPERTIES
    OUTPUT_NAME "${TARGET_NAME}"
    SUFFIX ".elf"
    RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}"
)

set(MCU_FLAGS
    -mcpu=cortex-m55
    -mcmse
    -mthumb
    -mfpu=fpv5-d16
    -mfloat-abi=hard
)

set(PROJECT_DEFINES
    STM32N657xx
    STM32N6570_NUCLEO_REV
    USE_FULL_ASSERT
    USE_FULL_LL_DRIVER
    VECT_TAB_SRAM
    LL_ATON_DUMP_DEBUG_API
    LL_ATON_PLATFORM=LL_ATON_PLAT_STM32N6
    LL_ATON_OSAL=LL_ATON_OSAL_THREADX
    APP_HAS_PARALLEL_NETWORKS=0
    LL_ATON_RT_MODE=LL_ATON_RT_POLLING
    LL_ATON_SW_FALLBACK
    LL_ATON_DBG_BUFFER_INFO_EXCLUDED=1
    TX_ENABLE_STACK_CHECKING
    TX_ENABLE_EVENT_TRACE
    USE_BSP_COM_FEATURE=1
    USE_COM_LOG=1
    TX_SINGLE_MODE_SECURE
    ${SCREENL_DEFINES}
)

if(DEFINED APP_GIT_SHA1_STRING)
    list(APPEND PROJECT_DEFINES "APP_GIT_SHA1_STRING=\"${APP_GIT_SHA1_STRING}\"")
elseif(DEFINED ENV{APP_GIT_SHA1_STRING})
    list(APPEND PROJECT_DEFINES "APP_GIT_SHA1_STRING=\"$ENV{APP_GIT_SHA1_STRING}\"")
endif()

if(DEFINED APP_VERSION_STRING)
    list(APPEND PROJECT_DEFINES "APP_VERSION_STRING=\"${APP_VERSION_STRING}\"")
elseif(DEFINED ENV{APP_VERSION_STRING})
    list(APPEND PROJECT_DEFINES "APP_VERSION_STRING=\"$ENV{APP_VERSION_STRING}\"")
endif()

target_compile_definitions(${TARGET_NAME}_objects PRIVATE ${PROJECT_DEFINES})

target_include_directories(${TARGET_NAME}_objects PRIVATE
    "${ROOT_DIR}/Middlewares/stm32-mw-camera"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/imx335"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/vd55g1"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/vd6g"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/vd1943"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/sensors/ov5640"

    "${APP_DIR}/Inc"
    "${MODEL_DIR}"
    "${ROOT_DIR}/Middlewares/threadx/common/inc"
    "${ROOT_DIR}/Middlewares/threadx/ports/cortex_m55/gnu/inc"
    "${ROOT_DIR}/Middlewares/ai-postprocessing-wrapper"
    "${ROOT_DIR}/Middlewares/stm32-vision-models-postprocessing/lib_vision_models_pp/Inc"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/ll_aton"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Inc"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/STM32N6xx_HAL_Driver/Inc/Legacy"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/CMSIS/Device/ST/STM32N6xx/Include"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/CMSIS/Include"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/CMSIS/DSP/Include"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/Components/Common"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/STM32N6xx_Nucleo"
    "${ROOT_DIR}/Middlewares/stm32-mw-camera/ISP_Library/isp/Inc"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Inc"
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Npu/Devices/STM32N6xx"
    "${ROOT_DIR}/STM32Cube_FW_N6/Utilities/lcd"
    "${ROOT_DIR}/STM32Cube_FW_N6/Drivers/BSP/Components/aps256xx"
    ${SCREENL_INCLUDES}
)

target_compile_options(${TARGET_NAME}_objects PRIVATE
    ${MCU_FLAGS}
    -Os
    -g3
    -Wall
    -fstack-usage
    -fdata-sections
    -ffunction-sections
    -fcyclomatic-complexity
    $<$<COMPILE_LANGUAGE:ASM>:-x>
    $<$<COMPILE_LANGUAGE:ASM>:assembler-with-cpp>
)

set(LDSCRIPT "${APP_DIR}/STM32N657xx.ld")
set(MAP_FILE "${BUILD_DIR}/${TARGET_NAME}.map")

set(FLASHER STM32_Programmer_CLI)
set(SIGNER STM32_SigningTool_CLI)

find_program(FLASHER_PATH ${FLASHER})
if(FLASHER_PATH)
    get_filename_component(FLASHER_DIR "${FLASHER_PATH}" DIRECTORY)
    set(EXTERNAL_LOADER "${FLASHER_DIR}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr")
else()
    set(EXTERNAL_LOADER "ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr")
endif()

target_link_directories(${TARGET_NAME} PRIVATE
    "${ROOT_DIR}/Middlewares/stedgeai-lib/Lib/GCC/ARMCortexM55"
)

target_link_options(${TARGET_NAME} PRIVATE
    ${MCU_FLAGS}
    -specs=nano.specs
    "-T${LDSCRIPT}"
    "-Wl,-Map=${MAP_FILE},--cref"
    "-Wl,--gc-sections"
    -u
    _printf_float
    "-Wl,--print-memory-usage"
    "-Wl,--no-warn-rwx-segments"
)

target_link_libraries(${TARGET_NAME} PRIVATE
    c
    m
    nosys
    ":NetworkRuntime1200_CM55_GCC.a"
)

set(ELF_FILE "${BUILD_DIR}/${TARGET_NAME}.elf")
set(BIN_FILE "${BUILD_DIR}/${TARGET_NAME}.bin")
set(SIGN_BIN_FILE "${BUILD_DIR}/${TARGET_NAME}_sign.bin")
set(SIGN_HEX_FILE "${BUILD_DIR}/${TARGET_NAME}_sign.hex")

add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary "$<TARGET_FILE:${TARGET_NAME}>" "${BIN_FILE}"
    COMMAND ${CMAKE_SIZE} "$<TARGET_FILE:${TARGET_NAME}>"
    BYPRODUCTS "${BIN_FILE}"
    COMMENT "BIN ${BIN_FILE}"
)

add_custom_command(
    OUTPUT "${SIGN_BIN_FILE}"
    COMMAND ${SIGNER} -s -bin "${BIN_FILE}" -nk -t ssbl -hv 2.3 -o "${SIGN_BIN_FILE}"
    DEPENDS ${TARGET_NAME}
    COMMENT "SIGN ${SIGN_BIN_FILE}"
    VERBATIM
)

add_custom_command(
    OUTPUT "${SIGN_HEX_FILE}"
    COMMAND ${CMAKE_OBJCOPY} -I binary "${SIGN_BIN_FILE}" --change-addresses 0x70100000 -O ihex "${SIGN_HEX_FILE}"
    DEPENDS "${SIGN_BIN_FILE}"
    COMMENT "HEX ${SIGN_HEX_FILE}"
    VERBATIM
)

add_custom_target(sign DEPENDS "${SIGN_HEX_FILE}")

add_custom_target(flash
    COMMAND ${FLASHER} -c port=SWD mode=HOTPLUG -el "${EXTERNAL_LOADER}" -hardRst -w "${SIGN_BIN_FILE}" 0x70100000
    COMMAND ${CMAKE_COMMAND} -E echo "FLASH ${SIGN_BIN_FILE}"
    DEPENDS "${SIGN_BIN_FILE}"
    VERBATIM
)

add_custom_target(flash_weights
    COMMAND ${FLASHER} -c port=SWD mode=HOTPLUG -el "${EXTERNAL_LOADER}" -hardRst -w "${MODEL_DIR}/network_data.hex"
    DEPENDS "${MODEL_DIR}/network_data.hex"
    VERBATIM
)
