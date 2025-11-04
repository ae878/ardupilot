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

/* ConfigFuzz Test #523 */

/* ConfigFuzz: MAVLINK_ENABLED_ICAROUS */
#ifdef MAVLINK_ENABLED_ICAROUS
#undef MAVLINK_ENABLED_ICAROUS
#endif
#define MAVLINK_ENABLED_ICAROUS 1

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 8

/* ConfigFuzz: HAL_COMPASS_AUTO_ROT_DEFAULT */
#ifdef HAL_COMPASS_AUTO_ROT_DEFAULT
#undef HAL_COMPASS_AUTO_ROT_DEFAULT
#endif
#define HAL_COMPASS_AUTO_ROT_DEFAULT 0

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_LAND */
#ifdef FS_GCS_ENABLED_ALWAYS_LAND
#undef FS_GCS_ENABLED_ALWAYS_LAND
#endif
#define FS_GCS_ENABLED_ALWAYS_LAND 1

/* ConfigFuzz: AP_STATS_ENABLED */
#ifdef AP_STATS_ENABLED
#undef AP_STATS_ENABLED
#endif
#define AP_STATS_ENABLED 1

#endif /* _AP_CONFIG_H_ */
