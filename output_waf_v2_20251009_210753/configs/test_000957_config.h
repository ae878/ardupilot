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

/* ConfigFuzz Test #957 */

/* ConfigFuzz: MODE_FLIP_ENABLED */
#ifdef MODE_FLIP_ENABLED
#undef MODE_FLIP_ENABLED
#endif
#define MODE_FLIP_ENABLED 0

/* ConfigFuzz: AP_SIGNED_FIRMWARE */
#ifdef AP_SIGNED_FIRMWARE
#undef AP_SIGNED_FIRMWARE
#endif
#define AP_SIGNED_FIRMWARE 1

/* ConfigFuzz: AP_SERVORELAYEVENTS_ENABLED */
#ifdef AP_SERVORELAYEVENTS_ENABLED
#undef AP_SERVORELAYEVENTS_ENABLED
#endif
#define AP_SERVORELAYEVENTS_ENABLED 1

/* ConfigFuzz: HAL_HAVE_IMU_HEATER */
#ifdef HAL_HAVE_IMU_HEATER
#undef HAL_HAVE_IMU_HEATER
#endif
#define HAL_HAVE_IMU_HEATER 0

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 1

/* ConfigFuzz: HAL_BATT_CURR_PIN */
#ifdef HAL_BATT_CURR_PIN
#undef HAL_BATT_CURR_PIN
#endif
#define HAL_BATT_CURR_PIN 1

#endif /* _AP_CONFIG_H_ */
