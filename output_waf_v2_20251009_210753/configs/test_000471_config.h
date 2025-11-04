#pragma once
/* ConfigFuzz generated configuration */

#ifndef _AP_CONFIG_H_
#define _AP_CONFIG_H_

/* Essential defines */
#define _GNU_SOURCE 1
#define WAF_BUILD 1
#define PYTHONDIR "/usr/lib/python3/dist-packages"
#define PYTHONARCHDIR "/usr/lib/python3/dist-packages"
#define __STDC_FORMAT_MACROS 1
#define AP_SIGNED_FIRMWARE 0
#define HAVE_CMATH_ISFINITE 1
#define HAVE_CMATH_ISINF 1
#define HAVE_CMATH_ISNAN 1
#define NEED_CMATH_ISFINITE_STD_NAMESPACE 1
#define NEED_CMATH_ISINF_STD_NAMESPACE 1
#define NEED_CMATH_ISNAN_STD_NAMESPACE 1

/* ConfigFuzz Test #471 */

/* ConfigFuzz: HAL_WITH_IO_MCU_BIDIR_DSHOT */
#ifdef HAL_WITH_IO_MCU_BIDIR_DSHOT
#undef HAL_WITH_IO_MCU_BIDIR_DSHOT
#endif
#define HAL_WITH_IO_MCU_BIDIR_DSHOT 0

/* ConfigFuzz: MODE_SMARTRTL_ENABLED */
#ifdef MODE_SMARTRTL_ENABLED
#undef MODE_SMARTRTL_ENABLED
#endif
#define MODE_SMARTRTL_ENABLED 1

/* ConfigFuzz: HAL_SOARING_ENABLED */
#ifdef HAL_SOARING_ENABLED
#undef HAL_SOARING_ENABLED
#endif
#define HAL_SOARING_ENABLED 1

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 1

/* ConfigFuzz: AP_HAL_UARTDRIVER_ENABLED */
#ifdef AP_HAL_UARTDRIVER_ENABLED
#undef AP_HAL_UARTDRIVER_ENABLED
#endif
#define AP_HAL_UARTDRIVER_ENABLED 0

/* ConfigFuzz: HAL_GPIO_INPUT */
#ifdef HAL_GPIO_INPUT
#undef HAL_GPIO_INPUT
#endif
#define HAL_GPIO_INPUT 1

/* ConfigFuzz: HAL_GENERATOR_ENABLED */
#ifdef HAL_GENERATOR_ENABLED
#undef HAL_GENERATOR_ENABLED
#endif
#define HAL_GENERATOR_ENABLED 1

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 1

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 0

#endif /* _AP_CONFIG_H_ */
