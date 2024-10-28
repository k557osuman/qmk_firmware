#pragma once

#define SN32_PWM_CT16B1_IRQ_PRIORITY 1
#define HAL_USE_I2C true
#define HAL_USE_PAL true
#define SN32_GPIOA_IRQ_PRIORITY 1
#define SN32_GPIOB_IRQ_PRIORITY 1
#define SN32_GPIOC_IRQ_PRIORITY 1
#define SN32_GPIOD_IRQ_PRIORITY 1
#define SN32_USB_IRQ_PRIORITY 0

#include_next <halconf.h>
