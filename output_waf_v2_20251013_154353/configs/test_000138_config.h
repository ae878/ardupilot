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

/* ConfigFuzz Test #138 */

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 1

/* ConfigFuzz: AP_OPTICALFLOW_ENABLED */
#ifdef AP_OPTICALFLOW_ENABLED
#undef AP_OPTICALFLOW_ENABLED
#endif
#define AP_OPTICALFLOW_ENABLED 1

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL */
#ifdef FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL
#undef FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL
#endif
#define FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL 0

/* ConfigFuzz: AP_RC_CHANNEL_ENABLED */
#ifdef AP_RC_CHANNEL_ENABLED
#undef AP_RC_CHANNEL_ENABLED
#endif
#define AP_RC_CHANNEL_ENABLED 0

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 1

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_AY */
#ifdef FSYNC_CONFIG_EXT_SYNC_AY
#undef FSYNC_CONFIG_EXT_SYNC_AY
#endif
#define FSYNC_CONFIG_EXT_SYNC_AY 1

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 1

#endif /* _AP_CONFIG_H_ */
