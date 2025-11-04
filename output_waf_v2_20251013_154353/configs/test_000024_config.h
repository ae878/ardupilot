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

/* ConfigFuzz Test #24 */

/* ConfigFuzz: BENCH_DEFINE_MAP_PERMUTATION */
#ifdef BENCH_DEFINE_MAP_PERMUTATION
#undef BENCH_DEFINE_MAP_PERMUTATION
#endif
#define BENCH_DEFINE_MAP_PERMUTATION 1

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_SMARTRTL_OR_RTL */
#ifdef FS_THR_ENABLED_ALWAYS_SMARTRTL_OR_RTL
#undef FS_THR_ENABLED_ALWAYS_SMARTRTL_OR_RTL
#endif
#define FS_THR_ENABLED_ALWAYS_SMARTRTL_OR_RTL 1

/* ConfigFuzz: HAL_LOGGING_ENABLED */
#ifdef HAL_LOGGING_ENABLED
#undef HAL_LOGGING_ENABLED
#endif
#define HAL_LOGGING_ENABLED 1

#endif /* _AP_CONFIG_H_ */
