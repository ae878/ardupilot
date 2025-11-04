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

/* ConfigFuzz Test #884 */

/* ConfigFuzz: MODE_ACRO_ENABLED */
#ifdef MODE_ACRO_ENABLED
#undef MODE_ACRO_ENABLED
#endif
#define MODE_ACRO_ENABLED 0

/* ConfigFuzz: FS_GCS_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#undef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_GCS_ENABLED_AUTO_RTL_OR_RTL 1

/* ConfigFuzz: AP_RANGEFINDER_MSP_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_MSP_TIMEOUT_MS
#undef AP_RANGEFINDER_MSP_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_MSP_TIMEOUT_MS 0

/* ConfigFuzz: MODE_DRIFT_ENABLED */
#ifdef MODE_DRIFT_ENABLED
#undef MODE_DRIFT_ENABLED
#endif
#define MODE_DRIFT_ENABLED 1

#endif /* _AP_CONFIG_H_ */
