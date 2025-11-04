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

/* ConfigFuzz Test #661 */

/* ConfigFuzz: BENCH_DEFINE_MAP_OVERRIDE */
#ifdef BENCH_DEFINE_MAP_OVERRIDE
#undef BENCH_DEFINE_MAP_OVERRIDE
#endif
#define BENCH_DEFINE_MAP_OVERRIDE 1

/* ConfigFuzz: AP_CRASHDUMP_ENABLED */
#ifdef AP_CRASHDUMP_ENABLED
#undef AP_CRASHDUMP_ENABLED
#endif
#define AP_CRASHDUMP_ENABLED 1

/* ConfigFuzz: FS_THR_ENABLED_BRAKE_OR_LAND */
#ifdef FS_THR_ENABLED_BRAKE_OR_LAND
#undef FS_THR_ENABLED_BRAKE_OR_LAND
#endif
#define FS_THR_ENABLED_BRAKE_OR_LAND 1

/* ConfigFuzz: BENCH_DEFINE_MAP_EXPLICIT */
#ifdef BENCH_DEFINE_MAP_EXPLICIT
#undef BENCH_DEFINE_MAP_EXPLICIT
#endif
#define BENCH_DEFINE_MAP_EXPLICIT 1

#endif /* _AP_CONFIG_H_ */
