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

/* ConfigFuzz Test #963 */

/* ConfigFuzz: BENCH_DEFINE_MAP_IMPLICIT */
#ifdef BENCH_DEFINE_MAP_IMPLICIT
#undef BENCH_DEFINE_MAP_IMPLICIT
#endif
#define BENCH_DEFINE_MAP_IMPLICIT 0

/* ConfigFuzz: AP_SERIALMANAGER_ENABLED */
#ifdef AP_SERIALMANAGER_ENABLED
#undef AP_SERIALMANAGER_ENABLED
#endif
#define AP_SERIALMANAGER_ENABLED 0

/* ConfigFuzz: MAVLINK_ENABLED_CSAIRLINK */
#ifdef MAVLINK_ENABLED_CSAIRLINK
#undef MAVLINK_ENABLED_CSAIRLINK
#endif
#define MAVLINK_ENABLED_CSAIRLINK 0

/* ConfigFuzz: AP_STATS_ENABLED */
#ifdef AP_STATS_ENABLED
#undef AP_STATS_ENABLED
#endif
#define AP_STATS_ENABLED 1

/* ConfigFuzz: USER_PARAMS_ENABLED */
#ifdef USER_PARAMS_ENABLED
#undef USER_PARAMS_ENABLED
#endif
#define USER_PARAMS_ENABLED 1

#endif /* _AP_CONFIG_H_ */
