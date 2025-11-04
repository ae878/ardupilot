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

/* ConfigFuzz Test #663 */

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 0

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_RTL */
#ifdef FS_THR_ENABLED_ALWAYS_RTL
#undef FS_THR_ENABLED_ALWAYS_RTL
#endif
#define FS_THR_ENABLED_ALWAYS_RTL 1

/* ConfigFuzz: FS_GCS_ENABLED_BRAKE_OR_LAND */
#ifdef FS_GCS_ENABLED_BRAKE_OR_LAND
#undef FS_GCS_ENABLED_BRAKE_OR_LAND
#endif
#define FS_GCS_ENABLED_BRAKE_OR_LAND 0

/* ConfigFuzz: RPMMAX */
#ifdef RPMMAX
#undef RPMMAX
#endif
#define RPMMAX 1

/* ConfigFuzz: MODE_CIRCLE_ENABLED */
#ifdef MODE_CIRCLE_ENABLED
#undef MODE_CIRCLE_ENABLED
#endif
#define MODE_CIRCLE_ENABLED 0

/* ConfigFuzz: HAL_SPEKTRUM_TELEM_ENABLED */
#ifdef HAL_SPEKTRUM_TELEM_ENABLED
#undef HAL_SPEKTRUM_TELEM_ENABLED
#endif
#define HAL_SPEKTRUM_TELEM_ENABLED 1

#endif /* _AP_CONFIG_H_ */
