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

/* ConfigFuzz Test #12 */

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_RTL */
#ifdef FS_THR_ENABLED_ALWAYS_RTL
#undef FS_THR_ENABLED_ALWAYS_RTL
#endif
#define FS_THR_ENABLED_ALWAYS_RTL 0

/* ConfigFuzz: AP_AIRSPEED_ENABLED */
#ifdef AP_AIRSPEED_ENABLED
#undef AP_AIRSPEED_ENABLED
#endif
#define AP_AIRSPEED_ENABLED 1

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_GX */
#ifdef FSYNC_CONFIG_EXT_SYNC_GX
#undef FSYNC_CONFIG_EXT_SYNC_GX
#endif
#define FSYNC_CONFIG_EXT_SYNC_GX 0

/* ConfigFuzz: TELEM_TIME_SLOT_MAX */
#ifdef TELEM_TIME_SLOT_MAX
#undef TELEM_TIME_SLOT_MAX
#endif
#define TELEM_TIME_SLOT_MAX 32

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 1

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_TEMP */
#ifdef FSYNC_CONFIG_EXT_SYNC_TEMP
#undef FSYNC_CONFIG_EXT_SYNC_TEMP
#endif
#define FSYNC_CONFIG_EXT_SYNC_TEMP 1

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 1

#endif /* _AP_CONFIG_H_ */
