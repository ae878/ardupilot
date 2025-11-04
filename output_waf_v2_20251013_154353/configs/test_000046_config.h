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

/* ConfigFuzz Test #46 */

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 0

/* ConfigFuzz: HAL_PARACHUTE_ENABLED */
#ifdef HAL_PARACHUTE_ENABLED
#undef HAL_PARACHUTE_ENABLED
#endif
#define HAL_PARACHUTE_ENABLED 0

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 1

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 1

/* ConfigFuzz: HAL_QUADPLANE_ENABLED */
#ifdef HAL_QUADPLANE_ENABLED
#undef HAL_QUADPLANE_ENABLED
#endif
#define HAL_QUADPLANE_ENABLED 1

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 1

/* ConfigFuzz: AP_DEVO_TELEM_ENABLED */
#ifdef AP_DEVO_TELEM_ENABLED
#undef AP_DEVO_TELEM_ENABLED
#endif
#define AP_DEVO_TELEM_ENABLED 0

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 1

/* ConfigFuzz: MODE_THROW_ENABLED */
#ifdef MODE_THROW_ENABLED
#undef MODE_THROW_ENABLED
#endif
#define MODE_THROW_ENABLED 1

#endif /* _AP_CONFIG_H_ */
