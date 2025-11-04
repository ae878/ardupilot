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

/* ConfigFuzz Test #505 */

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_LAND */
#ifdef FS_THR_ENABLED_ALWAYS_LAND
#undef FS_THR_ENABLED_ALWAYS_LAND
#endif
#define FS_THR_ENABLED_ALWAYS_LAND 1

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 1

/* ConfigFuzz: HAL_LOGGING_ENABLED */
#ifdef HAL_LOGGING_ENABLED
#undef HAL_LOGGING_ENABLED
#endif
#define HAL_LOGGING_ENABLED 0

/* ConfigFuzz: HAL_MOUNT_ENABLED */
#ifdef HAL_MOUNT_ENABLED
#undef HAL_MOUNT_ENABLED
#endif
#define HAL_MOUNT_ENABLED 0

/* ConfigFuzz: BENCH_DEFINE_MAP_PERMUTATION */
#ifdef BENCH_DEFINE_MAP_PERMUTATION
#undef BENCH_DEFINE_MAP_PERMUTATION
#endif
#define BENCH_DEFINE_MAP_PERMUTATION 1

/* ConfigFuzz: HAL_HAVE_DUAL_USB_CDC */
#ifdef HAL_HAVE_DUAL_USB_CDC
#undef HAL_HAVE_DUAL_USB_CDC
#endif
#define HAL_HAVE_DUAL_USB_CDC 1

/* ConfigFuzz: AP_MISSION_ENABLED */
#ifdef AP_MISSION_ENABLED
#undef AP_MISSION_ENABLED
#endif
#define AP_MISSION_ENABLED 1

#endif /* _AP_CONFIG_H_ */
