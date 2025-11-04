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

/* ConfigFuzz Test #197 */

/* ConfigFuzz: HAL_QUADPLANE_ENABLED */
#ifdef HAL_QUADPLANE_ENABLED
#undef HAL_QUADPLANE_ENABLED
#endif
#define HAL_QUADPLANE_ENABLED 0

/* ConfigFuzz: HAL_RCOUT_RGBLED_RED */
#ifdef HAL_RCOUT_RGBLED_RED
#undef HAL_RCOUT_RGBLED_RED
#endif
#define HAL_RCOUT_RGBLED_RED 0

/* ConfigFuzz: BENCH_DEFINE_MAP_OVERRIDE */
#ifdef BENCH_DEFINE_MAP_OVERRIDE
#undef BENCH_DEFINE_MAP_OVERRIDE
#endif
#define BENCH_DEFINE_MAP_OVERRIDE 1

#endif /* _AP_CONFIG_H_ */
