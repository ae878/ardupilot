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

/* ConfigFuzz Test #642 */

/* ConfigFuzz: FS_GCS_ENABLED_BRAKE_OR_LAND */
#ifdef FS_GCS_ENABLED_BRAKE_OR_LAND
#undef FS_GCS_ENABLED_BRAKE_OR_LAND
#endif
#define FS_GCS_ENABLED_BRAKE_OR_LAND 1

/* ConfigFuzz: LEDDARONE_DETECTIONS_MAX */
#ifdef LEDDARONE_DETECTIONS_MAX
#undef LEDDARONE_DETECTIONS_MAX
#endif
#define LEDDARONE_DETECTIONS_MAX 4

/* ConfigFuzz: MODE_RTL_ENABLED */
#ifdef MODE_RTL_ENABLED
#undef MODE_RTL_ENABLED
#endif
#define MODE_RTL_ENABLED 0

/* ConfigFuzz: HAL_ENABLE_THREAD_STATISTICS */
#ifdef HAL_ENABLE_THREAD_STATISTICS
#undef HAL_ENABLE_THREAD_STATISTICS
#endif
#define HAL_ENABLE_THREAD_STATISTICS 1

/* ConfigFuzz: HAL_LOGGING_ENABLED */
#ifdef HAL_LOGGING_ENABLED
#undef HAL_LOGGING_ENABLED
#endif
#define HAL_LOGGING_ENABLED 1

#endif /* _AP_CONFIG_H_ */
