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

/* ConfigFuzz Test #49 */

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 0

/* ConfigFuzz: AP_PERIPH_GPS_ENABLED */
#ifdef AP_PERIPH_GPS_ENABLED
#undef AP_PERIPH_GPS_ENABLED
#endif
#define AP_PERIPH_GPS_ENABLED 1

/* ConfigFuzz: HAL_BATT_CURR_PIN */
#ifdef HAL_BATT_CURR_PIN
#undef HAL_BATT_CURR_PIN
#endif
#define HAL_BATT_CURR_PIN 0

/* ConfigFuzz: HAL_BATT_VOLT_PIN */
#ifdef HAL_BATT_VOLT_PIN
#undef HAL_BATT_VOLT_PIN
#endif
#define HAL_BATT_VOLT_PIN 1

/* ConfigFuzz: AP_PERIPH_BATTERY_BALANCE_ENABLED */
#ifdef AP_PERIPH_BATTERY_BALANCE_ENABLED
#undef AP_PERIPH_BATTERY_BALANCE_ENABLED
#endif
#define AP_PERIPH_BATTERY_BALANCE_ENABLED 1

#endif /* _AP_CONFIG_H_ */
