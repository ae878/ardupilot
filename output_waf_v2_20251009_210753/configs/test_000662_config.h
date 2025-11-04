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

/* ConfigFuzz Test #662 */

/* ConfigFuzz: BENCH_DEFINE_MAP_IMPLICIT */
#ifdef BENCH_DEFINE_MAP_IMPLICIT
#undef BENCH_DEFINE_MAP_IMPLICIT
#endif
#define BENCH_DEFINE_MAP_IMPLICIT 0

/* ConfigFuzz: SUMD_MAX_CHANNELS */
#ifdef SUMD_MAX_CHANNELS
#undef SUMD_MAX_CHANNELS
#endif
#define SUMD_MAX_CHANNELS 8

/* ConfigFuzz: AP_RELAY_ENABLED */
#ifdef AP_RELAY_ENABLED
#undef AP_RELAY_ENABLED
#endif
#define AP_RELAY_ENABLED 0

/* ConfigFuzz: FLOW_CONTROL_ENABLED */
#ifdef FLOW_CONTROL_ENABLED
#undef FLOW_CONTROL_ENABLED
#endif
#define FLOW_CONTROL_ENABLED 0

#endif /* _AP_CONFIG_H_ */
