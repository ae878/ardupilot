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

/* ConfigFuzz Test #33 */

/* ConfigFuzz: AP_TEMPCALIBRATION_ENABLED */
#ifdef AP_TEMPCALIBRATION_ENABLED
#undef AP_TEMPCALIBRATION_ENABLED
#endif
#define AP_TEMPCALIBRATION_ENABLED 1

/* ConfigFuzz: HAL_HAVE_DUAL_USB_CDC */
#ifdef HAL_HAVE_DUAL_USB_CDC
#undef HAL_HAVE_DUAL_USB_CDC
#endif
#define HAL_HAVE_DUAL_USB_CDC 0

/* ConfigFuzz: RC_INPUT_MAX_PULSEWIDTH */
#ifdef RC_INPUT_MAX_PULSEWIDTH
#undef RC_INPUT_MAX_PULSEWIDTH
#endif
#define RC_INPUT_MAX_PULSEWIDTH 4

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 0

/* ConfigFuzz: AP_FOLLOW_ENABLED */
#ifdef AP_FOLLOW_ENABLED
#undef AP_FOLLOW_ENABLED
#endif
#define AP_FOLLOW_ENABLED 0

/* ConfigFuzz: AP_TUNING_ENABLED */
#ifdef AP_TUNING_ENABLED
#undef AP_TUNING_ENABLED
#endif
#define AP_TUNING_ENABLED 0

/* ConfigFuzz: INS_MAX_GYRO_WINDOW_SAMPLES */
#ifdef INS_MAX_GYRO_WINDOW_SAMPLES
#undef INS_MAX_GYRO_WINDOW_SAMPLES
#endif
#define INS_MAX_GYRO_WINDOW_SAMPLES 8

#endif /* _AP_CONFIG_H_ */
