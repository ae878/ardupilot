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

/* ConfigFuzz Test #766 */

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 1

/* ConfigFuzz: HAL_GPIO_INPUT */
#ifdef HAL_GPIO_INPUT
#undef HAL_GPIO_INPUT
#endif
#define HAL_GPIO_INPUT 0

/* ConfigFuzz: AP_RANGEFINDER_MSP_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_MSP_TIMEOUT_MS
#undef AP_RANGEFINDER_MSP_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_MSP_TIMEOUT_MS 0

/* ConfigFuzz: HAL_PWM_COUNT */
#ifdef HAL_PWM_COUNT
#undef HAL_PWM_COUNT
#endif
#define HAL_PWM_COUNT 0

/* ConfigFuzz: HAL_RCOUT_RGBLED_RED */
#ifdef HAL_RCOUT_RGBLED_RED
#undef HAL_RCOUT_RGBLED_RED
#endif
#define HAL_RCOUT_RGBLED_RED 0

#endif /* _AP_CONFIG_H_ */
