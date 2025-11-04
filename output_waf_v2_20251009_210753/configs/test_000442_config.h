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

/* ConfigFuzz Test #442 */

/* ConfigFuzz: AP_COPTER_ADVANCED_FAILSAFE_ENABLED */
#ifdef AP_COPTER_ADVANCED_FAILSAFE_ENABLED
#undef AP_COPTER_ADVANCED_FAILSAFE_ENABLED
#endif
#define AP_COPTER_ADVANCED_FAILSAFE_ENABLED 0

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 16

/* ConfigFuzz: AP_HAL_UARTDRIVER_ENABLED */
#ifdef AP_HAL_UARTDRIVER_ENABLED
#undef AP_HAL_UARTDRIVER_ENABLED
#endif
#define AP_HAL_UARTDRIVER_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC_CRC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC_CRC 0

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 8

/* ConfigFuzz: HAL_INS_NONE */
#ifdef HAL_INS_NONE
#undef HAL_INS_NONE
#endif
#define HAL_INS_NONE 1

/* ConfigFuzz: RC_OUTPUT_MAX_PULSEWIDTH */
#ifdef RC_OUTPUT_MAX_PULSEWIDTH
#undef RC_OUTPUT_MAX_PULSEWIDTH
#endif
#define RC_OUTPUT_MAX_PULSEWIDTH 32

#endif /* _AP_CONFIG_H_ */
