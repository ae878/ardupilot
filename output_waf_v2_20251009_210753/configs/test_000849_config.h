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

/* ConfigFuzz Test #849 */

/* ConfigFuzz: AP_HAL_UARTDRIVER_ENABLED */
#ifdef AP_HAL_UARTDRIVER_ENABLED
#undef AP_HAL_UARTDRIVER_ENABLED
#endif
#define AP_HAL_UARTDRIVER_ENABLED 0

/* ConfigFuzz: HAL_RALLY_ENABLED */
#ifdef HAL_RALLY_ENABLED
#undef HAL_RALLY_ENABLED
#endif
#define HAL_RALLY_ENABLED 1

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 1

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 1

/* ConfigFuzz: BENCH_DEFINE_MAP_OVERRIDE */
#ifdef BENCH_DEFINE_MAP_OVERRIDE
#undef BENCH_DEFINE_MAP_OVERRIDE
#endif
#define BENCH_DEFINE_MAP_OVERRIDE 0

#endif /* _AP_CONFIG_H_ */
