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

/* ConfigFuzz Test #489 */

/* ConfigFuzz: MODE_BRAKE_ENABLED */
#ifdef MODE_BRAKE_ENABLED
#undef MODE_BRAKE_ENABLED
#endif
#define MODE_BRAKE_ENABLED 0

/* ConfigFuzz: HAL_HAVE_HARDWARE_DOUBLE */
#ifdef HAL_HAVE_HARDWARE_DOUBLE
#undef HAL_HAVE_HARDWARE_DOUBLE
#endif
#define HAL_HAVE_HARDWARE_DOUBLE 1

/* ConfigFuzz: ESC_CHANNEL_MAP_RUNNING_DIRECTION */
#ifdef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#undef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#endif
#define ESC_CHANNEL_MAP_RUNNING_DIRECTION 0

/* ConfigFuzz: HAL_BATT_CURR_PIN */
#ifdef HAL_BATT_CURR_PIN
#undef HAL_BATT_CURR_PIN
#endif
#define HAL_BATT_CURR_PIN 0

#endif /* _AP_CONFIG_H_ */
