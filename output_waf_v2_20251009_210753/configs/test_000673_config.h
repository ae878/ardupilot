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

/* ConfigFuzz Test #673 */

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 0

/* ConfigFuzz: AP_STATS_ENABLED */
#ifdef AP_STATS_ENABLED
#undef AP_STATS_ENABLED
#endif
#define AP_STATS_ENABLED 0

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 1

/* ConfigFuzz: HAL_SPRAYER_ENABLED */
#ifdef HAL_SPRAYER_ENABLED
#undef HAL_SPRAYER_ENABLED
#endif
#define HAL_SPRAYER_ENABLED 1

/* ConfigFuzz: RANGEFINDER_MAX_INSTANCES */
#ifdef RANGEFINDER_MAX_INSTANCES
#undef RANGEFINDER_MAX_INSTANCES
#endif
#define RANGEFINDER_MAX_INSTANCES 16

#endif /* _AP_CONFIG_H_ */
