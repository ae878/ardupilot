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

/* ConfigFuzz Test #85 */

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 0

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 32

/* ConfigFuzz: HAL_INS_NONE */
#ifdef HAL_INS_NONE
#undef HAL_INS_NONE
#endif
#define HAL_INS_NONE 1

/* ConfigFuzz: MAVLINK_ENABLED_DEVELOPMENT */
#ifdef MAVLINK_ENABLED_DEVELOPMENT
#undef MAVLINK_ENABLED_DEVELOPMENT
#endif
#define MAVLINK_ENABLED_DEVELOPMENT 0

/* ConfigFuzz: MODE_DRIFT_ENABLED */
#ifdef MODE_DRIFT_ENABLED
#undef MODE_DRIFT_ENABLED
#endif
#define MODE_DRIFT_ENABLED 0

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 0

/* ConfigFuzz: AP_NOTIFY_NAVIGATOR_LED_ENABLED */
#ifdef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#undef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#endif
#define AP_NOTIFY_NAVIGATOR_LED_ENABLED 0

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 1

#endif /* _AP_CONFIG_H_ */
