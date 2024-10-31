#pragma once

#ifndef RGB_MATRIX_ENABLE
#define HAL_USE_GPT true
#define SN32_GPT_USE_CT16B1 true
#define SN32_GPT_CT16B1_IRQ_PRIORITY 1
#include_next <halconf.h>
#undef HAL_USE_PWM
#define HAL_USE_PWM false
/*#define SN32_PWM_CT16B1_IRQ_PRIORITY 1*/
#undef HAL_USE_PAL
#define HAL_USE_PAL true
#define SN32_GPIOA_IRQ_PRIORITY 1
#define SN32_GPIOB_IRQ_PRIORITY 1
#define SN32_GPIOC_IRQ_PRIORITY 1
#define SN32_GPIOD_IRQ_PRIORITY 1
#define SN32_USB_IRQ_PRIORITY 0
#else
#include_next <halconf.h>

#endif
