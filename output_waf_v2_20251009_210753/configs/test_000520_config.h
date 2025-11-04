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

/* ConfigFuzz Test #520 */

/* ConfigFuzz: AP_RANGEFINDER_MAVLINK_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_MAVLINK_TIMEOUT_MS
#undef AP_RANGEFINDER_MAVLINK_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_MAVLINK_TIMEOUT_MS 1

/* ConfigFuzz: HAL_HAVE_SAFETY_SWITCH */
#ifdef HAL_HAVE_SAFETY_SWITCH
#undef HAL_HAVE_SAFETY_SWITCH
#endif
#define HAL_HAVE_SAFETY_SWITCH 0

/* ConfigFuzz: HAL_BATT_VOLT_PIN */
#ifdef HAL_BATT_VOLT_PIN
#undef HAL_BATT_VOLT_PIN
#endif
#define HAL_BATT_VOLT_PIN 0

/* ConfigFuzz: MODE_CIRCLE_ENABLED */
#ifdef MODE_CIRCLE_ENABLED
#undef MODE_CIRCLE_ENABLED
#endif
#define MODE_CIRCLE_ENABLED 1

/* ConfigFuzz: USER_PARAMS_ENABLED */
#ifdef USER_PARAMS_ENABLED
#undef USER_PARAMS_ENABLED
#endif
#define USER_PARAMS_ENABLED 1

/* ConfigFuzz: AP_ICENGINE_ENABLED */
#ifdef AP_ICENGINE_ENABLED
#undef AP_ICENGINE_ENABLED
#endif
#define AP_ICENGINE_ENABLED 1

#endif /* _AP_CONFIG_H_ */
