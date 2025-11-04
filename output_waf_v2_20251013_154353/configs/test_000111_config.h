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

/* ConfigFuzz Test #111 */

/* ConfigFuzz: AP_PERIPH_RPM_ENABLED */
#ifdef AP_PERIPH_RPM_ENABLED
#undef AP_PERIPH_RPM_ENABLED
#endif
#define AP_PERIPH_RPM_ENABLED 1

/* ConfigFuzz: CONFIG_LWIP_STATS */
#ifdef CONFIG_LWIP_STATS
#undef CONFIG_LWIP_STATS
#endif
#define CONFIG_LWIP_STATS 1

/* ConfigFuzz: HAL_GCS_ENABLED */
#ifdef HAL_GCS_ENABLED
#undef HAL_GCS_ENABLED
#endif
#define HAL_GCS_ENABLED 0

/* ConfigFuzz: AP_RADIO_ENABLED */
#ifdef AP_RADIO_ENABLED
#undef AP_RADIO_ENABLED
#endif
#define AP_RADIO_ENABLED 1

/* ConfigFuzz: HAL_GENERATOR_ENABLED */
#ifdef HAL_GENERATOR_ENABLED
#undef HAL_GENERATOR_ENABLED
#endif
#define HAL_GENERATOR_ENABLED 1

/* ConfigFuzz: HAL_RALLY_ENABLED */
#ifdef HAL_RALLY_ENABLED
#undef HAL_RALLY_ENABLED
#endif
#define HAL_RALLY_ENABLED 1

/* ConfigFuzz: BENCH_DEFINE_MAP_EXPLICIT */
#ifdef BENCH_DEFINE_MAP_EXPLICIT
#undef BENCH_DEFINE_MAP_EXPLICIT
#endif
#define BENCH_DEFINE_MAP_EXPLICIT 1

#endif /* _AP_CONFIG_H_ */
