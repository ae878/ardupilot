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

/* ConfigFuzz Test #778 */

/* ConfigFuzz: RC_OUTPUT_MAX_PULSEWIDTH */
#ifdef RC_OUTPUT_MAX_PULSEWIDTH
#undef RC_OUTPUT_MAX_PULSEWIDTH
#endif
#define RC_OUTPUT_MAX_PULSEWIDTH 1

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_LAND */
#ifdef FS_GCS_ENABLED_ALWAYS_LAND
#undef FS_GCS_ENABLED_ALWAYS_LAND
#endif
#define FS_GCS_ENABLED_ALWAYS_LAND 1

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 0

#endif /* _AP_CONFIG_H_ */
