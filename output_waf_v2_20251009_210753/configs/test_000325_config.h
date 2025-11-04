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

/* ConfigFuzz Test #325 */

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_LAND */
#ifdef FS_THR_ENABLED_ALWAYS_LAND
#undef FS_THR_ENABLED_ALWAYS_LAND
#endif
#define FS_THR_ENABLED_ALWAYS_LAND 0

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC 1

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 1

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 1

#endif /* _AP_CONFIG_H_ */
