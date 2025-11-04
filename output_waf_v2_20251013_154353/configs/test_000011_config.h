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

/* ConfigFuzz Test #11 */

/* ConfigFuzz: HAL_PERIPH_ENABLE_RC_OUT */
#ifdef HAL_PERIPH_ENABLE_RC_OUT
#undef HAL_PERIPH_ENABLE_RC_OUT
#endif
#define HAL_PERIPH_ENABLE_RC_OUT 1

/* ConfigFuzz: HAL_RALLY_ENABLED */
#ifdef HAL_RALLY_ENABLED
#undef HAL_RALLY_ENABLED
#endif
#define HAL_RALLY_ENABLED 0

/* ConfigFuzz: HAL_PARACHUTE_ENABLED */
#ifdef HAL_PARACHUTE_ENABLED
#undef HAL_PARACHUTE_ENABLED
#endif
#define HAL_PARACHUTE_ENABLED 1

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 0

/* ConfigFuzz: HAL_PERIPH_ENABLE_NOTIFY */
#ifdef HAL_PERIPH_ENABLE_NOTIFY
#undef HAL_PERIPH_ENABLE_NOTIFY
#endif
#define HAL_PERIPH_ENABLE_NOTIFY 0

/* ConfigFuzz: AP_PERIPH_MAG_ENABLED */
#ifdef AP_PERIPH_MAG_ENABLED
#undef AP_PERIPH_MAG_ENABLED
#endif
#define AP_PERIPH_MAG_ENABLED 1

/* ConfigFuzz: HAL_LOGGING_ENABLED */
#ifdef HAL_LOGGING_ENABLED
#undef HAL_LOGGING_ENABLED
#endif
#define HAL_LOGGING_ENABLED 0

/* ConfigFuzz: HAL_PWM_COUNT */
#ifdef HAL_PWM_COUNT
#undef HAL_PWM_COUNT
#endif
#define HAL_PWM_COUNT 1

#endif /* _AP_CONFIG_H_ */
