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

/* ConfigFuzz Test #40 */

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_GZ */
#ifdef FSYNC_CONFIG_EXT_SYNC_GZ
#undef FSYNC_CONFIG_EXT_SYNC_GZ
#endif
#define FSYNC_CONFIG_EXT_SYNC_GZ 1

/* ConfigFuzz: AP_PERIPH_BATTERY_BALANCE_ENABLED */
#ifdef AP_PERIPH_BATTERY_BALANCE_ENABLED
#undef AP_PERIPH_BATTERY_BALANCE_ENABLED
#endif
#define AP_PERIPH_BATTERY_BALANCE_ENABLED 0

/* ConfigFuzz: AP_CAMERA_ENABLED */
#ifdef AP_CAMERA_ENABLED
#undef AP_CAMERA_ENABLED
#endif
#define AP_CAMERA_ENABLED 0

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_AX */
#ifdef FSYNC_CONFIG_EXT_SYNC_AX
#undef FSYNC_CONFIG_EXT_SYNC_AX
#endif
#define FSYNC_CONFIG_EXT_SYNC_AX 1

/* ConfigFuzz: BENCH_DEFINE_MAP_COUNT */
#ifdef BENCH_DEFINE_MAP_COUNT
#undef BENCH_DEFINE_MAP_COUNT
#endif
#define BENCH_DEFINE_MAP_COUNT 1

#endif /* _AP_CONFIG_H_ */
