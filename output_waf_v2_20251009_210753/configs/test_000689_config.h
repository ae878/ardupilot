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

/* ConfigFuzz Test #689 */

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_RTL */
#ifdef FS_GCS_ENABLED_ALWAYS_RTL
#undef FS_GCS_ENABLED_ALWAYS_RTL
#endif
#define FS_GCS_ENABLED_ALWAYS_RTL 0

/* ConfigFuzz: BENCH_DEFINE_MAP_OVERRIDE */
#ifdef BENCH_DEFINE_MAP_OVERRIDE
#undef BENCH_DEFINE_MAP_OVERRIDE
#endif
#define BENCH_DEFINE_MAP_OVERRIDE 1

/* ConfigFuzz: HAL_WITH_DRONECAN */
#ifdef HAL_WITH_DRONECAN
#undef HAL_WITH_DRONECAN
#endif
#define HAL_WITH_DRONECAN 1

#endif /* _AP_CONFIG_H_ */
