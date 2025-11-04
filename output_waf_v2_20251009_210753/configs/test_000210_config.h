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

/* ConfigFuzz Test #210 */

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 0

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN 0

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 1

/* ConfigFuzz: MODE_RTL_ENABLED */
#ifdef MODE_RTL_ENABLED
#undef MODE_RTL_ENABLED
#endif
#define MODE_RTL_ENABLED 1

/* ConfigFuzz: RC_INPUT_MAX_PULSEWIDTH */
#ifdef RC_INPUT_MAX_PULSEWIDTH
#undef RC_INPUT_MAX_PULSEWIDTH
#endif
#define RC_INPUT_MAX_PULSEWIDTH 2

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 0

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 0

/* ConfigFuzz: MAVLINK_ENABLED_CSAIRLINK */
#ifdef MAVLINK_ENABLED_CSAIRLINK
#undef MAVLINK_ENABLED_CSAIRLINK
#endif
#define MAVLINK_ENABLED_CSAIRLINK 0

#endif /* _AP_CONFIG_H_ */
