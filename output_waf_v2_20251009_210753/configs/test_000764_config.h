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

/* ConfigFuzz Test #764 */

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 0

/* ConfigFuzz: AP_SOCKET_NATIVE_ENABLED */
#ifdef AP_SOCKET_NATIVE_ENABLED
#undef AP_SOCKET_NATIVE_ENABLED
#endif
#define AP_SOCKET_NATIVE_ENABLED 0

/* ConfigFuzz: AP_STATS_ENABLED */
#ifdef AP_STATS_ENABLED
#undef AP_STATS_ENABLED
#endif
#define AP_STATS_ENABLED 1

/* ConfigFuzz: HAL_HNF_MAX_FILTERS */
#ifdef HAL_HNF_MAX_FILTERS
#undef HAL_HNF_MAX_FILTERS
#endif
#define HAL_HNF_MAX_FILTERS 16

/* ConfigFuzz: BENCH_DEFINE_MAP_EXPLICIT */
#ifdef BENCH_DEFINE_MAP_EXPLICIT
#undef BENCH_DEFINE_MAP_EXPLICIT
#endif
#define BENCH_DEFINE_MAP_EXPLICIT 0

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN 1

#endif /* _AP_CONFIG_H_ */
