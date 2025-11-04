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

/* ConfigFuzz Test #80 */

/* ConfigFuzz: HAL_QUADPLANE_ENABLED */
#ifdef HAL_QUADPLANE_ENABLED
#undef HAL_QUADPLANE_ENABLED
#endif
#define HAL_QUADPLANE_ENABLED 0

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 0

/* ConfigFuzz: HAL_RCOUT_RGBLED_RED */
#ifdef HAL_RCOUT_RGBLED_RED
#undef HAL_RCOUT_RGBLED_RED
#endif
#define HAL_RCOUT_RGBLED_RED 1

/* ConfigFuzz: AP_AIS_ENABLED */
#ifdef AP_AIS_ENABLED
#undef AP_AIS_ENABLED
#endif
#define AP_AIS_ENABLED 0

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_RTL */
#ifdef FS_THR_ENABLED_ALWAYS_RTL
#undef FS_THR_ENABLED_ALWAYS_RTL
#endif
#define FS_THR_ENABLED_ALWAYS_RTL 1

/* ConfigFuzz: MAVLINK_ENABLED_ASLUAV */
#ifdef MAVLINK_ENABLED_ASLUAV
#undef MAVLINK_ENABLED_ASLUAV
#endif
#define MAVLINK_ENABLED_ASLUAV 0

/* ConfigFuzz: BENCH_DEFINE_MAP_GEOMETRY */
#ifdef BENCH_DEFINE_MAP_GEOMETRY
#undef BENCH_DEFINE_MAP_GEOMETRY
#endif
#define BENCH_DEFINE_MAP_GEOMETRY 1

/* ConfigFuzz: NOOPLOOP_DIST_MAX_MM */
#ifdef NOOPLOOP_DIST_MAX_MM
#undef NOOPLOOP_DIST_MAX_MM
#endif
#define NOOPLOOP_DIST_MAX_MM 8

#endif /* _AP_CONFIG_H_ */
