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

/* ConfigFuzz Test #55 */

/* ConfigFuzz: HAL_SUPPORT_RCOUT_SERIAL */
#ifdef HAL_SUPPORT_RCOUT_SERIAL
#undef HAL_SUPPORT_RCOUT_SERIAL
#endif
#define HAL_SUPPORT_RCOUT_SERIAL 1

/* ConfigFuzz: AP_FENCE_ENABLED */
#ifdef AP_FENCE_ENABLED
#undef AP_FENCE_ENABLED
#endif
#define AP_FENCE_ENABLED 1

/* ConfigFuzz: AP_COPTER_AHRS_AUTO_TRIM_ENABLED */
#ifdef AP_COPTER_AHRS_AUTO_TRIM_ENABLED
#undef AP_COPTER_AHRS_AUTO_TRIM_ENABLED
#endif
#define AP_COPTER_AHRS_AUTO_TRIM_ENABLED 1

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_AX */
#ifdef FSYNC_CONFIG_EXT_SYNC_AX
#undef FSYNC_CONFIG_EXT_SYNC_AX
#endif
#define FSYNC_CONFIG_EXT_SYNC_AX 1

/* ConfigFuzz: BENCH_DEFINE_MAP_COUNT */
#ifdef BENCH_DEFINE_MAP_COUNT
#undef BENCH_DEFINE_MAP_COUNT
#endif
#define BENCH_DEFINE_MAP_COUNT 0

/* ConfigFuzz: HAL_NO_FLASH_SUPPORT */
#ifdef HAL_NO_FLASH_SUPPORT
#undef HAL_NO_FLASH_SUPPORT
#endif
#define HAL_NO_FLASH_SUPPORT 1

#endif /* _AP_CONFIG_H_ */
