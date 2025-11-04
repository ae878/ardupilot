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

/* ConfigFuzz Test #407 */

/* ConfigFuzz: HAL_PWM_COUNT */
#ifdef HAL_PWM_COUNT
#undef HAL_PWM_COUNT
#endif
#define HAL_PWM_COUNT 0

/* ConfigFuzz: HAL_RCOUT_RGBLED_GREEN */
#ifdef HAL_RCOUT_RGBLED_GREEN
#undef HAL_RCOUT_RGBLED_GREEN
#endif
#define HAL_RCOUT_RGBLED_GREEN 0

/* ConfigFuzz: BENCH_DEFINE_MAP_PERMUTATION */
#ifdef BENCH_DEFINE_MAP_PERMUTATION
#undef BENCH_DEFINE_MAP_PERMUTATION
#endif
#define BENCH_DEFINE_MAP_PERMUTATION 0

/* ConfigFuzz: AUTOTUNE_ENABLED */
#ifdef AUTOTUNE_ENABLED
#undef AUTOTUNE_ENABLED
#endif
#define AUTOTUNE_ENABLED 0

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 1

#endif /* _AP_CONFIG_H_ */
