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

/* ConfigFuzz Test #239 */

/* ConfigFuzz: MAVLINK_ENABLED_MINIMAL */
#ifdef MAVLINK_ENABLED_MINIMAL
#undef MAVLINK_ENABLED_MINIMAL
#endif
#define MAVLINK_ENABLED_MINIMAL 1

/* ConfigFuzz: BENCH_DEFINE_MAP_GEOMETRY */
#ifdef BENCH_DEFINE_MAP_GEOMETRY
#undef BENCH_DEFINE_MAP_GEOMETRY
#endif
#define BENCH_DEFINE_MAP_GEOMETRY 1

/* ConfigFuzz: NOOPLOOP_DIST_MAX_MM */
#ifdef NOOPLOOP_DIST_MAX_MM
#undef NOOPLOOP_DIST_MAX_MM
#endif
#define NOOPLOOP_DIST_MAX_MM 16

/* ConfigFuzz: HAL_SOARING_ENABLED */
#ifdef HAL_SOARING_ENABLED
#undef HAL_SOARING_ENABLED
#endif
#define HAL_SOARING_ENABLED 0

#endif /* _AP_CONFIG_H_ */
